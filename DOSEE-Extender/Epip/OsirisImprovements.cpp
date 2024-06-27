#include "pch.h"
#include "OsirisImprovements.h"
#include "Extender/ScriptExtender.h"
#include "Epip/EpipSettings.h"

using namespace dse;
using namespace epip;

void OsirisImprovements::Setup()
{
	gExtender->GetHooks().RegisterGameStateChangedListener(this);
	if (gSettings->ForceStoryPatching)
	{
		auto& lib = gExtender->GetEngineHooks();
		//gExtender->GetLibraryManager().ApplyCodePatch("storypatch patch"); // Patch equivalent of the following hook.
		lib.GetOsirisSaveFileVersion.SetWrapper(&OsirisImprovements::OnOsirisGetSaveFileVersion, this);
	}
}

int OsirisImprovements::OnOsirisGetSaveFileVersion(StaticSymbols::GetOsirisSaveFileVersionProc* next, STDString* param1, Path* param2)
{
	// Force story patching
	// Game interprets this as uint; -1 is thus highest version possible
	return -1;
}

void OsirisImprovements::OnGameStateChanged(int newState)
{
	// Enable story log
	// It's fine to do this in PrepareRunning, as it'll trigger upon entering the main
	// menu and persist into sessions afterwards.
	if (newState == ecl::EoCClient::GameState::PrepareRunning && gSettings->StoryLogging)
	{
		GlobalSwitches* switches = *GetStaticSymbols().GlobalSwitches;
		switches->StoryLog = true;
	}
}
