// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <pch.h>
#include "DxgiWrapper.h"
#include <ShellAPI.h>
#include <KnownFolders.h>
#include <ShlObj.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include "Extender/ScriptExtender.h"
#include "Epip/Epip.h"

bool ShouldRunProxy()
{
	return GetModuleHandleW(L"EoCApp.exe") != NULL || GetModuleHandleW(L"TheDivinityEngine.exe") != NULL;
}

void CreateConsole()
{
	AllocConsole();
	SetConsoleTitleW(L"DOSEE Script Extender(? No promises)");

	if (IsValidCodePage(CP_UTF8)) {
		SetConsoleCP(CP_UTF8);
		SetConsoleOutputCP(CP_UTF8);
	}

	auto hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleMode(hStdout, ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
	// Disable Ctrl+C handling
	SetConsoleCtrlHandler(NULL, TRUE);

	FILE* outputStream;
	freopen_s(&outputStream, "CONOUT$", "w", stdout);
	FILE* inputStream;
	freopen_s(&inputStream, "CONIN$", "r", stdin);

	std::cout << "Hello world" << std::endl;
}

HMODULE gThisModule{ NULL };

void SetupExtender(HMODULE hModule)
{
	dse::gExtender = std::make_unique<dse::ScriptExtender>();
	gEpip = std::make_unique<Epip>();

	DisableThreadLibraryCalls(hModule);

	CreateConsole();

	dse::gExtender->Initialize();
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		gThisModule = hModule;
		if (ShouldRunProxy()) {
			gDxgiWrapper = std::make_unique<DxgiWrapper>();
			SetupExtender(hModule);
		}
		break;

	case DLL_PROCESS_DETACH:
		if (gDxgiWrapper) {
			gDxgiWrapper.reset();
		}
		break;

	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}
