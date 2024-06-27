#include "pch.h"
#include "WorldTooltips.h"
#include "Extender/ScriptExtender.h"
#include <GameDefinitions/Item.h>
#include "Epip/EpipSettings.h"

using namespace dse;
using namespace epip;

void WorldTooltips::Setup()
{
	if (gSettings->MoreWorldTooltips)
	{
		auto& lib = gExtender->GetEngineHooks();
		lib.ecl_ItemProtocol_UpdateItems.SetPostHook(&WorldTooltips::OnUpdateItems, this);
	}
}

eoc::IActionData* GetActionData(eoc::ItemTemplate* itemTemplate, eoc::IActionData::ActionType type)
{
	for (auto action : itemTemplate->BaseActionData)
	{
		if (action->Type == type)
		{
			return action;
		}
	}
	return nullptr;
}

void WorldTooltips::OnUpdateItems(void* netProtocol)
{
	auto levelManager = *gStaticSymbols->ecl_LevelManager;
	auto level = levelManager->CurrentLevel;
	if (level)
	{
		auto items = level->ItemManager->ItemSet;
		for (auto item : items)
		{
			auto itemTemplate = (eoc::ItemTemplate*)item->GetCurrentTemplate();
			int previousTooltip = itemTemplate->Tooltip;
			if (previousTooltip != 2)
			{
				bool shouldHaveTooltip = item->Stats != nullptr;

				//shouldHaveTooltip |= (item->LockLevel > 0 && item->LockLevel <= 7);
				//shouldHaveTooltip |= itemTemplate->IsKey; // Might be a wrong field name?

				if (itemTemplate->InventoryType > 0)
				{
					// There are items that have inventory type set but cannot be opened,
					// ex. broken vases.
					shouldHaveTooltip |= GetActionData(itemTemplate, eoc::IActionData::ActionType::OpenClose) != nullptr;
				}

				if (shouldHaveTooltip)
				{
					itemTemplate->Tooltip = 2;
				}
			}
		}
	}
}
