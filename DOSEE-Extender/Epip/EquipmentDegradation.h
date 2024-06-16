#pragma once
#include "Hooks/Hooks.h"

BEGIN_NS(epip)

class EquipmentDegradation
{
public:
	void Setup();

private:
	void* OnStatsItemDegradeDurability(StaticSymbols::CDivinityStats_Item_DegradeDurabilityProc* next, CDivinityStats_Item* item, int amount, int chance);
};

END_NS()
