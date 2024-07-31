#pragma once
#include "pch.h"
//#include <GameDefinitions/Components/Character.h>
//#include <GameDefinitions/Components/Projectile.h>
//#include <GameDefinitions/GameObjects/GameAction.h>
//#include <GameDefinitions/Components/Inventory.h>
//#include <GameDefinitions/GameObjects/Level.h>
//#include <GameDefinitions/CustomStats.h>
//#include <GameDefinitions/Input.h>
//#include <GameDefinitions/Misc.h>
//#include <GameDefinitions/Osiris.h>
//#include <GameDefinitions/GameObjects/ActionMachine.h>
#include <GameDefinitions/UI.h>
//#include <GameDefinitions/GameObjects/Surface.h>
//#include <GameDefinitions/GameObjects/AiHelpers.h>
//#include <GameDefinitions/GameObjects/Controllers.h>
//#include <GameDefinitions/GameObjects/Camera.h>
//#include <GameDefinitions/GameObjects/Material.h>
//#include <GameDefinitions/GameObjects/Vision.h>
#include <GameDefinitions/EntitySystem.h>
#include <GameDefinitions/Character.h>
#include <GameDefinitions/RPGStats.h>
#include <GameDefinitions/Input.h>
#include <GameDefinitions/Misc.h>
#include <GameDefinitions/Effect.h>
#include <GameDefinitions/Player.h>
#include <GameDefinitions/Level.h>
#include <GameDefinitions/Inventory.h>

namespace dse
{
	//enum class EsvGlobalEoCApp {
	//	EsvLSDialogEventManager = 0,
	//	EsvStoryDialogEventManager = 1,
	//	EsvStoryItemEventManager = 2,
	//	EsvStoryCharacterEventManager = 3,
	//	// 4
	//	// 5-6 event visitor
	//	// 7-8 game event visitor
	//	ServerLevelManager = 9,
	//	PartyManager = 10,
	//	EsvCharacterFactory = 11,
	//	// 12
	//	EsvProjectileFactory = 13,
	//	EsvEoCTriggerFactory = 14,
	//	EsvItemFactory = 15,
	//	EsvSkillFactory = 16,
	//	EsvSkillStatePool = 17,
	//	EsvInventoryFactory = 18,
	//	EsvInventoryViewFactory = 19,
	//	StoryImplementation = 20,
	//	AlignmentFactory = 21,
	//	AlignmentContainer = 22,
	//	OsirisVariableHelper = 23,
	//	// 24
	//	OverheadTextFactory = 25,
	//	SurfaceActionFactory = 26,
	//	CustomBookManager = 27,
	//	// 28
	//	GameControl = 29,
	//	// 30
	//	CharacterCreationManager = 31,
	//	MarkerManager = 32,
	//	OsirisTaskFactory = 33,
	//	EnvironmentalInfluencesPool = 34,
	//	CombatFormationManager = 35,
	//	DivinityStats = 36,
	//	PlanManager = 37,
	//	// 38
	//	ActivationManager = 39
	//};

	//enum class EsvGlobalEoCPlugin {
	//	EsvSavegameManager = 0,
	//	EsvEoCServer = 1,
	//	EsvCacheTemplateManager = 2,
	//	EsvAiFactory = 3,
	//	EsvGameObjectFactory = 4,
	//	EsvLSDialogEventManager = 5,
	//	EsvStoryDialogEventManager = 6,
	//	EsvStoryItemEventManager = 7,
	//	EsvStoryCharacterEventManager = 8,
	//	// 9, 10-11, 12-13 event visitors
	//	ServerLevelManager = 14,
	//	PartyManager = 15,
	//	EsvCharacterFactory = 16,
	//	EsvProjectileFactory = 17,
	//	EsvEoCTriggerFactory = 18,
	//	EsvItemFactory = 19,
	//	EsvSkillFactory = 20,
	//	EsvSkillStatePool = 21,
	//	EsvInventoryFactory = 22,
	//	EsvInventoryViewFactory = 23,
	//	StoryImplementation = 24,
	//	AlignmentFactory = 25,
	//	OsirisVariableHelper = 26,
	//	// 27
	//	OverheadTextFactory = 28,
	//	SurfaceActionFactory = 29,
	//	CustomBookManager = 30,
	//	// 31
	//	GameControl = 32,
	//	// 33
	//	CharacterCreationManager = 34,
	//	MarkerManager = 35,
	//	OsirisTaskFactory = 36,
	//	EnvironmentalInfluencesPool = 37,
	//	CombatFormationManager = 38,
	//	DivinityStats = 39,
	//	PlanManager = 40,
	//	ActivationManager = 41
	//};

	struct StaticSymbols : Noncopyable<StaticSymbols>
	{
		struct EoCLibraryInfo
		{
			uint8_t const* initFunc;
			uint8_t const* freeFunc;
			uint32_t refs;
		};

		EoCAllocFunc EoCAlloc{ nullptr };
		EoCFreeFunc EoCFree{ nullptr };
		CrtAllocFunc CrtAlloc{ nullptr };
		CrtFreeFunc CrtFree{ nullptr };

		typedef int (*CDivinityStats_Character__GetResistanceFunc)(CDivinityStats_Character* self, bool ignoreBoosts);
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetFireResistance{ nullptr };
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetEarthResistance{ nullptr };
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetWaterResistance{ nullptr };
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetAirResistance{ nullptr };
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetPoisonResistance{ nullptr };
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetPiercingResistance{ nullptr };
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetCrushingResistance{ nullptr };
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetSlashingResistance{ nullptr };
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetShadowResistance{ nullptr };

		ComponentFactory<ecl::Character>** ObjectFactory__ecl_Character{ nullptr };
		ComponentFactory<esv::Character>** ObjectFactory__esv_Character{ nullptr };

		ComponentFactory<esv::Item>** ObjectFactory__esv_Item{ nullptr };

		using ecl_PickingHelper_DoPickProc = void (ecl::PickingHelper* self);
		ecl_PickingHelper_DoPickProc* ecl_PickingHelper_DoPick{ nullptr };

		using esv_ItemHelpers_GenerateTreasureItemProc = esv::Item* (void* request, int16_t unknown);
		esv_ItemHelpers_GenerateTreasureItemProc* esv_ItemHelpers_GenerateTreasureItem{ nullptr };

		ecl::PartyManager** ecl_PartyManager{ nullptr };

		using RunStoryPatchProc = bool (void* param1, Path* path1, Path* path2);
		RunStoryPatchProc* RunStoryPatch{ nullptr };

		using GetOsirisSaveFileVersionProc = int (STDString* param1, Path* param2);
		GetOsirisSaveFileVersionProc* GetOsirisSaveFileVersion{ nullptr };

		using ecl_UIBottomBar_UpdateSlotsProc = void(UIKeyboardBottomBar* ui, char flags_m);
		ecl_UIBottomBar_UpdateSlotsProc* ecl_UIBottomBar_UpdateSlots{ nullptr };
		using ecl_UIBottomBar_UpdateSlots2Proc = void(UIKeyboardBottomBar* ui);
		ecl_UIBottomBar_UpdateSlots2Proc* ecl_UIBottomBar_UpdateSlots2{ nullptr };
		using ecl_UIBottomBar_UpdateSlotCooldownsProc = void(UIKeyboardBottomBar* ui);
		ecl_UIBottomBar_UpdateSlotCooldownsProc* ecl_UIBottomBar_UpdateSlotCooldowns{ nullptr };

		using ecl_PlayerManager_GetCharacterByPlayerIDProc = ecl::Character* (ecl::PlayerManager* self, short playerID);
		ecl_PlayerManager_GetCharacterByPlayerIDProc* ecl_PlayerManager_GetCharacterByPlayerID{ nullptr };

		ecl::PlayerManager** ecl_PlayerManager{ nullptr };
		ecl::LevelManager** ecl_LevelManager{ nullptr };
		ecl::EoCClient** ecl_EoCClient{ nullptr };
		esv::PartyManager** esv_PartyManager{ nullptr };
		esv::PlanManager::ScriptParam** esv_ScriptParam_DontCare{ nullptr };

		ecl::EocUIControl** ecl_EocUIControl{ nullptr };
		GlobalSwitches** GlobalSwitches{ nullptr };

		esv::ActivationManager** esv_ActivationManager{ nullptr };

		using ecl_EocUIControl_OpenExamineUIProc = void(ecl::EocUIControl* self, short playerID, ComponentHandle* objectHandle);
		ecl_EocUIControl_OpenExamineUIProc* ecl_EocUIControl_OpenExamineUI{ nullptr };

		using ecl_GameStateEventManager_ExecuteGameStateChangedEventProc = void(void* self, uint32_t unknown1, uint32_t unknown2);
		ecl_GameStateEventManager_ExecuteGameStateChangedEventProc* ecl_GameStateEventManager_ExecuteGameStateChangedEvent{ nullptr };

		using ObjectPool__esv_ScriptParam_ReleaseProc = void(void* pool, esv::PlanManager::ScriptParam* param);
		ObjectPool__esv_ScriptParam_ReleaseProc* ObjectPool__esv_ScriptParam_Release{ nullptr };

		using Effect_UpdateIsVisibleProc = void(Effect* effect, void* cullDesc, void* visualSet, int visiblityFlags);
		Effect_UpdateIsVisibleProc* Effect_UpdateIsVisible{ nullptr };

		using MoveableObject_CheckVisibleProc = int(void* obj, void* cullDesc);
		MoveableObject_CheckVisibleProc* MoveableObject_CheckVisible{ nullptr };

		using CDivinityStats_Item_DegradeDurabilityProc = void* (CDivinityStats_Item* item, int amount, int chance);
		CDivinityStats_Item_DegradeDurabilityProc* CDivinityStats_Item_DegradeDurability{ nullptr };

		using ecl_EocUIControl_ShowCommonMessageBoxProc = void(ecl::EocUIControl* self, wchar_t* msg);
		ecl_EocUIControl_ShowCommonMessageBoxProc* ecl_EocUIControl_ShowCommonMessageBox{ nullptr };

		using CDivinityStats_Character_GetDefenseDamageReductionProc = float(CDivinityStats_Character* character, int level);
		CDivinityStats_Character_GetDefenseDamageReductionProc* CDivinityStats_Character_GetDefenseDamageReduction{ nullptr };

		using CDivinityStats_Character_GetDefenseFromLevelProc = int(CDivinityStats_Character* character, int level, bool excludeBoosts);
		CDivinityStats_Character_GetDefenseFromLevelProc* CDivinityStats_Character_GetDefenseFromLevel{ nullptr };

		using esv_ScriptParam_GetCharacterProc = esv::Character* (esv::PlanManager::ScriptParam* self);
		esv_ScriptParam_GetCharacterProc* esv_ScriptParam_GetCharacter{ nullptr };
		using esv_ScriptParam_GetItemProc = esv::Item* (esv::PlanManager::ScriptParam* self);
		esv_ScriptParam_GetItemProc* esv_ScriptParam_GetItem{ nullptr };

		using esv_Item_GenerateTreasureProc = void(esv::Item* self, esv::Character* character);
		esv_Item_GenerateTreasureProc* esv_Item_GenerateTreasure{ nullptr };

		using CDivinityStats_Character_GetAbilityBoostFromPrimaryStatProc = int(CDivinityStats_Character* self, AbilityType ability, bool excludeBoosts);
		CDivinityStats_Character_GetAbilityBoostFromPrimaryStatProc* CDivinityStats_Character_GetAbilityBoostFromPrimaryStat{ nullptr };

		using CDivinityStats_Character_HasTalentProc = bool(CDivinityStats_Character* self, TalentType talent, bool excludeBoosts);
		CDivinityStats_Character_HasTalentProc* CDivinityStats_Character_HasTalent{ nullptr };

		using ls_InputManager_InjectInputProc = bool (InputManager* self, InputRawChange* rawInputChange, bool unknown);
		ls_InputManager_InjectInputProc* ls_InputManager_InjectInput{ nullptr };

		using esv_OsirisCharacterFunctions_SendItemUsedEventProc = bool(void* self, ObjectHandle* characterHandle, ObjectHandle* itemHandle);
		esv_OsirisCharacterFunctions_SendItemUsedEventProc* esv_OsirisCharacterFunctions_SendItemUsedEvent{ nullptr };

		using esv_ActivationManager_ThrowOnCharacterItemEventProc = void(esv::ActivationManager* self, esv::Character* character, esv::Item* item, char* eventName);
		esv_ActivationManager_ThrowOnCharacterItemEventProc* esv_ActivationManager_ThrowOnCharacterItemEvent{ nullptr };

		using ecl_UIExamine_SetupInformationProc = void(UIObject* self, bool clearPanel);
		ecl_UIExamine_SetupInformationProc* ecl_UIExamine_SetupInformation{ nullptr };

		OsirisCharacterEventManager** OsirisCharacterEvents{ nullptr };

		using ecl_ItemProtocol_UpdateItemsProc = void(void* self);
		ecl_ItemProtocol_UpdateItemsProc* ecl_ItemProtocol_UpdateItems{ nullptr };

		ComponentFactory<ecl::Inventory>** ecl_InventoryFactory{ nullptr };
		ComponentFactory<esv::Inventory>** esv_InventoryFactory{ nullptr };

		FixedString::CreateProc* ls__FixedString__Create{ nullptr };
		GlobalStringTable const** ls__GlobalStrings{ nullptr };

		Path::GetPrefixForRootProc* ls__Path__GetPrefixForRoot{ nullptr };
		STDString** ls__PathRoots{ nullptr };

		uint8_t const* ActivateClientSystemsHook{ nullptr };
		uint8_t const* ActivateServerSystemsHook{ nullptr };
		eoc::NetworkFixedStrings** NetworkFixedStrings{ nullptr };
		void* InitNetworkFixedStrings{ nullptr };

		/*UIObjectManager::RegisterUIObjectCreatorProc* UIObjectManager__RegisterUIObjectCreator{ nullptr };*/
		UIObjectManager::CreateUIObjectProc* UIObjectManager__CreateUIObject{ nullptr };
		UIObjectManager::GetUIObjectByTypeProc* UIObjectManager__GetUIObjectByType{ nullptr };
		UIObjectManager::GetInstanceProc* UIObjectManager__GetInstance{ nullptr };
		UIObjectManager** UIObjectManager__Instance{ nullptr };
		/*UIObjectManager::DestroyUIObjectProc* UIObjectManager__DestroyUIObject{ nullptr };
		ecl::EoCUI::ctor ecl__EoCUI__ctor{ nullptr };
		UIObject::VMT* ecl__EoCUI__vftable{ nullptr };
		UIObject::GetUIScaleMultiplierProc* ls__UIObject__GetUIScaleMultiplier{ nullptr };
		UIObject::RaiseFlagProc* ls__UIObject__RaiseFlag{ nullptr };
		UIObject::RaiseFlagProc* ls__UIObject__ClearFlag{ nullptr };*/

		/*ig::ValuePathMakeNameRefProc IgValuePathMakeNameRef{ nullptr };
		ig::ValuePathMakeArrayRefProc IgValuePathPathMakeArrayRef{ nullptr };
		ig::ValuePathSetArrayIndexProc IgValuePathSetArrayIndex{ nullptr };

		ig::ValueGetTypeProc IgValueGetType{ nullptr };
		ig::ValueGetArrayLengthProc IgValueGetArrayLength{ nullptr };

		ig::ValueGetBooleanProc IgValueGetBoolean{ nullptr };
		ig::ValueGetF64Proc IgValueGetF64{ nullptr };
		ig::ValueGetStringUTF8Proc IgValueGetStringUTF8{ nullptr };

		ig::ValueSetBooleanProc IgValueSetBoolean{ nullptr };
		ig::ValueSetF64Proc IgValueSetF64{ nullptr };
		ig::ValueSetStringUTF8Proc IgValueSetStringUTF8{ nullptr };

		

		*/

		ig::SetWarningCallbackProc IgSetWarningCallback{ nullptr };
		ig::SetTraceCallbackUTF8Proc IgSetTraceCallbackUTF8{ nullptr };
		ig::PlayerCallMethod IgPlayerCallMethod{ nullptr };
		ig::PlayerCreateFastNameUTF8 IgPlayerCreateFastNameUTF8{ nullptr };

		void* DUMMY1{ nullptr };
		std::map<uint8_t const*, EoCLibraryInfo> Libraries;

		uint8_t const* ServerRegisterFuncs[50]{ nullptr };
		uint8_t* const* ServerGlobals[50]{ nullptr };
		uint8_t const* EocRegisterFuncs[6]{ nullptr };
		uint8_t const** EocGlobals[6]{ nullptr };

		inline StaticSymbols() {}
		StaticSymbols(StaticSymbols const&) = delete;
		StaticSymbols& operator = (StaticSymbols const&) = delete;

		inline UIObjectManager* GetUIObjectManager() const
		{
			if (UIObjectManager__Instance != nullptr) {
				return *UIObjectManager__Instance;
			}
			else if (UIObjectManager__GetInstance != nullptr) {
				return UIObjectManager__GetInstance();
			}
			else {
				return nullptr;
			}
		}

		/*inline void RegisterUIObjectCreator(UIObjectManager* self, unsigned int index, UIObjectFunctor* creator)
		{
#if defined(OSI_EOCAPP)
			auto hashMap = (UIObjectManager*)((intptr_t)self + offsetof(UIObjectManager, UIObjectCreators));
			UIObjectManager__RegisterUIObjectCreator(hashMap, index, creator);
#else
			UIObjectManager__RegisterUIObjectCreator(self, index, creator);
#endif
		}*/

		void CanonicalizePath(STDString& path) const;
		/*STDString ToPath(StringView path, PathRootType root, bool canonicalize = true) const;
		FileReaderPin MakeFileReader(StringView path, PathRootType root = PathRootType::Data, bool canonicalize = true) const;
		void DestroyFileReader(FileReader* reader);
		bool FileExists(StringView path, PathRootType root = PathRootType::Data, bool canonicalize = true) const;
		GlobalTemplateBank* GetGlobalTemplateBank() const;
		ResourceBank* GetResourceBank() const;*/
	};

	extern StaticSymbols* gStaticSymbols;

	void InitStaticSymbols();

	inline StaticSymbols& GetStaticSymbols()
	{
		return *gStaticSymbols;
	}
}
