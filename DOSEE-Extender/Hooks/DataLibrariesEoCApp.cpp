#include <pch.h>
#include <Hooks/DataLibraries.h>
//#include <Extender/ScriptExtender.h>
#include <GameDefinitions/Symbols.h>
#include <functional>
#include <psapi.h>

#if defined(OSI_EOCAPP)
namespace dse
{
	void LibraryManager::PreRegisterLibraries(SymbolMappingLoader& loader)
	{
		loader.AddKnownModule("Main");
	}

	void LibraryManager::RegisterLibraries(SymbolMapper& mapper)
	{
		mapper.AddModule("Main", L"EoCApp.exe");
	}

	bool LibraryManager::BindApp()
	{
		// Ensure we're not within editor
		HMODULE hEoCPlugin = GetModuleHandleW(L"EoCPlugin.dll");
		if (hEoCPlugin != NULL) {
			MessageBoxW(NULL, L"This version of the Script Extender can only be used ingame.", L"Osiris Extender Error", MB_OK | MB_ICONERROR);
			TerminateProcess(GetCurrentProcess(), 1);
		}

		symbolMapper_.AddModule("Main", L"EoCApp.exe");
		appModule_ = symbolMapper_.Modules().find("Main")->second;

		return true;
	}
}
#endif
