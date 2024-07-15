#pragma once
#include "Hooks/Hooks.h"

BEGIN_NS(epip)

class SharedCivils : public GetAbilityBoostListener
{
public:
	void Setup();
private:
	void OnItemGenerateTreasure(StaticSymbols::esv_Item_GenerateTreasureProc* next, esv::Item* item, esv::Character* character);
	virtual int OnGetAbilityBoost(CDivinityStats_Character* stats, AbilityType ability, bool excludeBoosts) override;

	bool _GeneratingTreasure = false;
};

END_NS()
