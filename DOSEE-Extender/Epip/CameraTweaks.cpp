#include "pch.h"
#include "CameraTweaks.h"
#include <Extender/ScriptExtender.h>
#include "Hooks/Hooks.h"
#include "Epip/EpipSettings.h"

using namespace dse;
using namespace epip;

void CameraTweaks::Setup()
{
	gExtender->GetHooks().RegisterGameStateChangedListener(this);

	// NO-OP setting the camera flag for being in dialogue, allowing it to be rotated in-dialog (position will still tween to target)
	if (gSettings->UnlockDialogCamera)
	{
		bool applied = gExtender->GetLibraryManager().ApplyCodePatch("ecl::KeywordControl::ShowUIDialog camera patch");
		if (!applied)
		{
			WARN("Could not patch camera dialog flag");
		}
	}
}

void CameraTweaks::OnGameStateChanged(int newState)
{
	if (newState == ecl::EoCClient::GameState::PrepareRunning)
	{
		// Update camera global switches
		(*gStaticSymbols->GlobalSwitches)->CameraMaxDistance = gSettings->CameraMaxDistance;
	}
}
