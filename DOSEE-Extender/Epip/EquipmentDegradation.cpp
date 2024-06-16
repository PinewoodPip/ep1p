#include "pch.h"
#include "EquipmentDegradation.h"
#include "Extender/ScriptExtender.h"

using namespace dse;
using namespace epip;

void EquipmentDegradation::Setup()
{
	auto& lib = gExtender->GetEngineHooks();
	lib.CDivinityStats_Item_DegradeDurability.SetWrapper(&EquipmentDegradation::OnStatsItemDegradeDurability, this);
}

void* EquipmentDegradation::OnStatsItemDegradeDurability(StaticSymbols::CDivinityStats_Item_DegradeDurabilityProc* next, CDivinityStats_Item* item, int amount, int chance)
{
	// Prevent items from losing durability
	return next(item, 0, 0);
}
