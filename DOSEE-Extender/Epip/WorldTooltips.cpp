#include "pch.h"
#include "WorldTooltips.h"
#include "Extender/ScriptExtender.h"
#include <GameDefinitions/Item.h>

using namespace dse;
using namespace epip;

void WorldTooltips::Setup()
{
	gExtender->GetHooks().RegisterGameStateChangedListener(this);
}

void WorldTooltips::OnGameStateChanged(int newState)
{
	if (newState == ecl::EoCClient::GameState::PrepareRunning)
	{
		// Enable world tooltips for all item templates on the level
		// TODO also do this for items spawned later on - use template manager instead
		auto levelManager = *gStaticSymbols->ecl_LevelManager;
		auto level = levelManager->CurrentLevel;
		auto items = level->ItemManager->ItemSet;
		for (auto item : items)
		{
			auto itemTemplate = (eoc::ItemTemplate*)item->GetCurrentTemplate();
			itemTemplate->Tooltip = 2;
		}
	}
}
