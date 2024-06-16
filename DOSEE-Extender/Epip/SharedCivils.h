#pragma once
#include "Hooks/Hooks.h"

BEGIN_NS(epip)

class SharedCivils
{
public:
	void Setup();

private:
	void OnItemGenerateTreasure(StaticSymbols::esv_Item_GenerateTreasureProc* next, esv::Item* item, esv::Character* character);
	int OnCharacterStatsGetAbilityBoostFromPrimaryStat(StaticSymbols::CDivinityStats_Character_GetAbilityBoostFromPrimaryStatProc* next, CDivinityStats_Character* stats, AbilityType ability, bool excludeBoosts);

	bool _GeneratingTreasure = false;
};

END_NS()
