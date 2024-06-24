#include <pch.h>
#include <Hooks/DataLibraries.h>
#include <Extender/ScriptExtender.h>
#include <string>
#include <functional>
#include <psapi.h>
#include <GameDefinitions/UI.h>

#if !defined(OSI_EOCAPP)
BEGIN_SE()

void LibraryManager::PreRegisterLibraries(SymbolMappingLoader& loader)
{
	loader.AddKnownModule("Main");
	loader.AddKnownModule("GameEngine");
	loader.AddKnownModule("CoreLib");
}

void LibraryManager::RegisterLibraries(SymbolMapper& mapper)
{
	mapper.AddModule("Main", L"EoCPlugin.dll");
	/*mapper.AddModule("GameEngine", L"GameEngine.dll");
	mapper.AddModule("CoreLib", L"CoreLib.dll");
	mapper.AddEngineCallback("FindLibraries", &FindLibrariesEoCPlugin);
	mapper.AddEngineCallback("FindActivateEntitySystem", &FindActivateEntitySystem);
	mapper.AddEngineCallback("FindCharacterStatGetters", &FindCharacterStatGetters);
	mapper.AddEngineCallback("FindActionMachineSetState", &FindActionMachineSetState);
	mapper.AddEngineCallback("FindActionMachineResetState", &FindActionMachineResetState);
	mapper.AddEngineCallback("FindStatusHeal", &FindStatusHeal);
	mapper.AddEngineCallback("FindStatusHit", &FindStatusHit);*/
}

bool LibraryManager::BindApp()
{
	// Ensure we're not in the release game build
	HMODULE hEoCApp = GetModuleHandleW(L"EoCApp.exe");
	if (hEoCApp != NULL) {
		MessageBoxW(NULL, L"This version of the Script Extender can only be used in the editor.", L"Osiris Extender Error", MB_OK | MB_ICONERROR);
		TerminateProcess(GetCurrentProcess(), 1);
	}

	HMODULE hDivinityEngine = GetModuleHandleW(L"TheDivinityEngine.exe");
	if (hDivinityEngine == NULL) {
		return false;
	}

	symbolMapper_.AddModule("Main", L"EoCPlugin.dll");
	symbolMapper_.AddModule("GameEngine", L"GameEngine.dll");
	symbolMapper_.AddModule("CoreLib", L"CoreLib.dll");
	appModule_ = symbolMapper_.Modules().find("Main")->second;
	gameEngineModule_ = symbolMapper_.Modules().find("GameEngine")->second;
	coreLibModule_ = symbolMapper_.Modules().find("CoreLib")->second;

	return true;
}

END_SE()
#endif
