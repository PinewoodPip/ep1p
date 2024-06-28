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
}

void CameraTweaks::OnGameStateChanged(int newState)
{
	if (newState == ecl::EoCClient::GameState::PrepareRunning)
	{
		// Update camera global switches
		(*gStaticSymbols->GlobalSwitches)->CameraMaxDistance = gSettings->CameraMaxDistance;
	}
}
