#include <pch.h>
#include <Hooks/DataLibraries.h>
//#include <Extender/Shared/ExtensionState.h>
//#include <Extender/ScriptExtender.h>
#include <GameDefinitions/Symbols.h>
#include <string>
#include <functional>
#include <psapi.h>
#include <DbgHelp.h>

namespace dse
{
	LibraryManager::LibraryManager()
		: symbolMapper_(mappings_)
	{}

	bool LibraryManager::FindLibraries(uint32_t gameRevision)
	{
		RegisterSymbols();

		SymbolMappingLoader loader(mappings_);
		PreRegisterLibraries(loader);
		if (!loader.LoadBuiltinMappings()) {
			ERR("Failed to load symbol mapping table");
			CriticalInitFailed = true;
		}

#if 0
		if (!CriticalInitFailed) {
			// Debug check for symbol xml -> engine bindings
			for (auto const& sym : mappings_.StaticSymbols) {
				if (!sym.second.Bound) {
					WARN("No mapping exists for engine symbol: %s", sym.first.c_str());
				}
			}
		}
#endif

		if (!BindApp()) {
#if !defined(OSI_EOCPLUGIN)
			ERR("LibraryManager::FindLibraries(): Unable to bind EoCApp module.");
#else
			ERR("LibraryManager::FindLibraries(): Unable to bind EoCPlugin module.");
#endif
			return false;
		}

		RegisterLibraries(symbolMapper_);
		symbolMapper_.MapAllSymbols(false);

		CriticalInitFailed = CriticalInitFailed || symbolMapper_.HasFailedCriticalMappings();
		InitFailed = InitFailed || symbolMapper_.HasFailedMappings();

		return !CriticalInitFailed;
	}

#define SYM_OFF(name) mappings_.StaticSymbols.insert(std::make_pair(#name, SymbolMappings::StaticSymbol{ (int)offsetof(StaticSymbols, name) }))
#define CHAR_GETTER_SYM_OFF(name) mappings_.StaticSymbols.insert(std::make_pair("CharacterStatGetters__" #name, SymbolMappings::StaticSymbol{ (int)offsetof(StaticSymbols, CharStatsGetters) + (int)offsetof(stats::CharacterStatsGetters, name) }))

	void LibraryManager::RegisterSymbols()
	{
		SYM_OFF(UIObjectManager__CreateUIObject);
		SYM_OFF(UIObjectManager__GetUIObjectByType);
		SYM_OFF(UIObjectManager__GetInstance);
		SYM_OFF(UIObjectManager__Instance);
		SYM_OFF(EoCAlloc);
		SYM_OFF(EoCFree);
		SYM_OFF(CDivinityStats_Character__GetFireResistance);
		SYM_OFF(CDivinityStats_Character__GetEarthResistance);
		SYM_OFF(CDivinityStats_Character__GetWaterResistance);
		SYM_OFF(CDivinityStats_Character__GetAirResistance);
		SYM_OFF(CDivinityStats_Character__GetPoisonResistance);
		SYM_OFF(CDivinityStats_Character__GetPiercingResistance);
		SYM_OFF(CDivinityStats_Character__GetCrushingResistance);
		SYM_OFF(CDivinityStats_Character__GetSlashingResistance);
		SYM_OFF(CDivinityStats_Character__GetShadowResistance);
		SYM_OFF(ObjectFactory__ecl_Character);
		SYM_OFF(ecl_PickingHelper_DoPick);
		SYM_OFF(esv_ItemHelpers_GenerateTreasureItem);
		SYM_OFF(ecl_EocUIControl_OpenExamineUI);
		SYM_OFF(ecl_EocUIControl);
		SYM_OFF(esv_ActivationManager);
		SYM_OFF(ls_InputManager_InjectInput);
		SYM_OFF(esv_OsirisCharacterFunctions_SendItemUsedEvent);
		SYM_OFF(esv_ActivationManager_ThrowOnCharacterItemEvent);
		SYM_OFF(ecl_UIExamine_SetupInformation);
		SYM_OFF(OsirisCharacterEvents);
		SYM_OFF(ecl_InventoryFactory);
		SYM_OFF(esv_InventoryFactory);
		SYM_OFF(ecl_ItemProtocol_UpdateItems);
		SYM_OFF(IgSetWarningCallback);
		SYM_OFF(IgSetTraceCallbackUTF8);
		SYM_OFF(IgPlayerCallMethod);
		SYM_OFF(IgPlayerCreateFastNameUTF8);
		SYM_OFF(GlobalSwitches);
		SYM_OFF(ecl_PartyManager);
		SYM_OFF(ecl_PlayerManager);
		SYM_OFF(ecl_PlayerManager_GetCharacterByPlayerID);
		SYM_OFF(GetOsirisSaveFileVersion);
		SYM_OFF(ecl_UIBottomBar_UpdateSlots);
		SYM_OFF(ecl_UIBottomBar_UpdateSlots2);
		SYM_OFF(ecl_UIBottomBar_UpdateSlotCooldowns);
		SYM_OFF(RunStoryPatch);
		SYM_OFF(ecl_LevelManager);
		SYM_OFF(ecl_EoCClient);
		SYM_OFF(esv_PartyManager);
		SYM_OFF(esv_ScriptParam_DontCare);
		SYM_OFF(ObjectFactory__esv_Character);
		SYM_OFF(ObjectFactory__ecl_Item);
		SYM_OFF(ObjectFactory__esv_Item);
		SYM_OFF(ecl_GameStateEventManager_ExecuteGameStateChangedEvent);
		SYM_OFF(ObjectPool__esv_ScriptParam_Release);
		SYM_OFF(Effect_UpdateIsVisible);
		SYM_OFF(MoveableObject_CheckVisible);
		SYM_OFF(CDivinityStats_Item_DegradeDurability);
		SYM_OFF(CDivinityStats_Character_GetDefenseDamageReduction);
		SYM_OFF(CDivinityStats_Character_GetDefenseFromLevel);
		SYM_OFF(ecl_EocUIControl_ShowCommonMessageBox);
		SYM_OFF(esv_ScriptParam_GetItem);
		SYM_OFF(esv_ScriptParam_GetCharacter);
		SYM_OFF(ecl_Party_AddToGroup);
		SYM_OFF(ecl_Party_RequestDetach);
		SYM_OFF(esv_Item_GenerateTreasure);
		SYM_OFF(CDivinityStats_Character_GetAbilityBoostFromPrimaryStat);
		SYM_OFF(CDivinityStats_Character_HasTalent);
	}

	bool LibraryManager::PostStartupFindLibraries()
	{
		if (PostLoaded) {
			return !CriticalInitFailed;
		}

		auto initStart = std::chrono::high_resolution_clock::now();

		symbolMapper_.MapAllSymbols(true);

		if (!CriticalInitFailed) {

			for (auto const& sym : mappings_.StaticSymbols) {
				if (sym.second.Bound && sym.second.Offset != -1) {
					auto ptr = (void**)((uint8_t*)&GetStaticSymbols() + sym.second.Offset);
					if (!*ptr) {
						ERR("Engine symbol not bound after mapping phase: %s", sym.first.c_str());
					}
				}
			}

			/*GFS.Initialize();
			InitializeEnumerations();
			InitPropertyMaps();
			lua::RegisterLibraries();
			TypeInformationRepository::GetInstance().Initialize();*/
		}

		auto initEnd = std::chrono::high_resolution_clock::now();
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(initEnd - initStart).count();
		/*Log("LibraryManager::PostStartupFindLibraries() took %d ms", ms);*/

		PostLoaded = true;
		return !CriticalInitFailed;
	}

	bool LibraryManager::GetGameVersion(GameVersionInfo& version)
	{
		HMODULE hGameModule = GetModuleHandleW(L"EoCApp.exe"); // TODO editor support
		if (hGameModule == NULL) {
			// TODO
			version.Major = 2;
			version.Minor = 0;
			version.Revision = 119;
			version.Build = 430;
			return false;
		}

		auto hResource = FindResource(hGameModule, MAKEINTRESOURCE(VS_VERSION_INFO), RT_VERSION);
		if (hResource == NULL) return false;
		auto dwSize = SizeofResource(hGameModule, hResource);
		auto hData = LoadResource(hGameModule, hResource);
		if (hData == NULL) return false;
		auto pRes = LockResource(hData);
		if (pRes == NULL) return false;

		auto pResCopy = LocalAlloc(LMEM_FIXED, dwSize);
		CopyMemory(pResCopy, pRes, dwSize);

		UINT verLength;
		VS_FIXEDFILEINFO* fixedFileInfo;
		if (VerQueryValue(pResCopy, L"\\", (LPVOID*)&fixedFileInfo, &verLength) != TRUE) return false;

		version.Major = HIWORD(fixedFileInfo->dwFileVersionMS);
		version.Minor = LOWORD(fixedFileInfo->dwFileVersionMS);
		version.Revision = HIWORD(fixedFileInfo->dwFileVersionLS);
		version.Build = LOWORD(fixedFileInfo->dwFileVersionLS);

		LocalFree(pResCopy);
		FreeResource(hData);
		return true;
	}

	void LibraryManager::ShowStartupError(STDWString const& msg, bool wait, bool exitGame)
	{
		ERR(L"STARTUP ERROR: %s", msg.c_str());

		/*if (GetStaticSymbols().ecl__EoCClient == nullptr
			|| GetStaticSymbols().ecl__EoCClient__HandleError == nullptr
			|| GetStaticSymbols().EoCAlloc == nullptr) {
			return;
		}

		if (wait) {
			std::thread messageThread([this, msg, exitGame]() {
				unsigned retries{ 0 };
				while (!CanShowError() && retries < 1200) {
					Sleep(100);
					retries++;
				}

				if (retries < 1200) {
					ShowStartupError(msg, exitGame);
				}
				else {
					MessageBoxW(NULL, msg.c_str(), L"Script Extender Error",
						MB_OK | MB_ICONERROR | MB_TASKMODAL | MB_SETFOREGROUND);
				}
				});
			messageThread.detach();
		}
		else {
			if (CanShowError()) {
				ShowStartupError(msg, exitGame);
			}
			else {
				ShowStartupMessage(msg, exitGame);
			}
		}*/
	}

	void LibraryManager::ShowStartupError(STDWString const& msg, bool exitGame)
	{
		if (!CanShowMessages()) return;

		/*GetStaticSymbols().ecl__EoCClient__HandleError(*GetStaticSymbols().ecl__EoCClient, &msg, exitGame, &msg);*/
	}

	void LibraryManager::ShowStartupMessage(STDWString const& msg, bool exitGame)
	{
		// Don't show progress if we're already in a loaded state, as it'll show a message box instead
		if (CanShowError()) return;

		ShowStartupError(msg, exitGame);
	}

	bool LibraryManager::CanShowMessages()
	{
		return false; // TODO
		/*return GetStaticSymbols().GetClientState()
			&& GetStaticSymbols().ecl__EoCClient__HandleError != nullptr
			&& GetStaticSymbols().EoCAlloc != nullptr;*/
	}

	bool LibraryManager::CanShowError()
	{
		return false; // TODO
		/*if (!CanShowMessages()) return false;

		auto state = GetStaticSymbols().GetClientState();
		return state == ecl::GameState::Running
			|| state == ecl::GameState::Paused
			|| state == ecl::GameState::GameMasterPause
			|| state == ecl::GameState::Menu
			|| state == ecl::GameState::Lobby;*/
	}


	void LibraryManager::ApplyCodePatches()
	{

	}


	bool LibraryManager::ApplyCodePatch(std::string const& mapping)
	{
		auto it = mappings_.Mappings.find(mapping);
		if (it == mappings_.Mappings.end()) {
			ERR("Cannot apply patch - no such mapping: '%s'", mapping.c_str());
			return false;
		}

		if (it->second.Patches.empty()) {
			ERR("Cannot apply patch - mapping '%s' contains no patch entries", mapping.c_str());
			return false;
		}

		bool hasChanges = false;
		for (auto& patch : it->second.Patches) {
			hasChanges = ApplyPatch(patch) || hasChanges;
		}

		return hasChanges;
	}

	bool LibraryManager::UndoCodePatch(std::string const& mapping)
	{
		auto it = mappings_.Mappings.find(mapping);
		if (it == mappings_.Mappings.end()) {
			ERR("Cannot undo patch - no such mapping: '%s'", mapping.c_str());
			return false;
		}

		bool hasChanges = false;
		for (auto& patch : it->second.Patches) {
			hasChanges = UndoPatch(patch) || hasChanges;
		}

		return hasChanges;
	}

	bool LibraryManager::ApplyPatch(SymbolMappings::Patch& patch)
	{
		if (patch.WasApplied || patch.ResolvedRef == nullptr) {
			return false;
		}

		WriteAnchor code(patch.ResolvedRef, patch.Bytes.size());
		patch.OriginalBytes.resize(patch.Bytes.size());
		memcpy(patch.OriginalBytes.data(), patch.ResolvedRef, patch.OriginalBytes.size());
		memcpy(const_cast<uint8_t*>(patch.ResolvedRef), patch.Bytes.data(), patch.Bytes.size());
		patch.WasApplied = true;
		return true;
	}

	bool LibraryManager::UndoPatch(SymbolMappings::Patch& patch)
	{
		if (!patch.WasApplied) return false;

		WriteAnchor code(patch.ResolvedRef, patch.OriginalBytes.size());
		memcpy(const_cast<uint8_t*>(patch.ResolvedRef), patch.OriginalBytes.data(), patch.OriginalBytes.size());
		patch.WasApplied = false;
		return true;
	}
}
