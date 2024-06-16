#include "pch.h"
#include "OsirisImprovements.h"
#include "Extender/ScriptExtender.h"

using namespace dse;
using namespace epip;

void OsirisImprovements::Setup()
{
	gExtender->GetHooks().RegisterGameStateChangedListener(this);
}

void OsirisImprovements::OnGameStateChanged(int newState)
{
	// Enable story log
	// It's fine to do this in PrepareRunning, as it'll trigger upon entering the main
	// menu and persist into sessions afterwards.
	if (newState == ecl::EoCClient::GameState::PrepareRunning)
	{
		GlobalSwitches* switches = *GetStaticSymbols().GlobalSwitches;
		switches->StoryLog = true;
	}
}
