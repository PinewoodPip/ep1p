#include "pch.h"
#include "EquipmentDegradation.h"
#include "Extender/ScriptExtender.h"
#include "Epip/EpipSettings.h"

using namespace dse;
using namespace epip;

void EquipmentDegradation::Setup()
{
	if (gSettings->InfiniteEquipmentDurability)
	{
		auto& lib = gExtender->GetEngineHooks();
		lib.CDivinityStats_Item_DegradeDurability.SetWrapper(&EquipmentDegradation::OnStatsItemDegradeDurability, this);
	}
}

void* EquipmentDegradation::OnStatsItemDegradeDurability(StaticSymbols::CDivinityStats_Item_DegradeDurabilityProc* next, CDivinityStats_Item* item, int amount, int chance)
{
	// Prevent items from losing durability, unless they are unrepairable
	int aggregatedFlags = 0;
	for (auto dynStat : item->DynamicStats)
	{
		aggregatedFlags = aggregatedFlags | dynStat->Flags;
	}
	bool unrepairable = (aggregatedFlags >> 30) & 1; // "Unrepairable" flag
	return unrepairable ? next(item, amount, chance) : next(item, 0, 0);
}
