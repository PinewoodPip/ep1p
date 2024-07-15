#pragma once
#include "Hooks/Hooks.h"

using namespace dse;

BEGIN_NS(epip)

class ExamineTweaks : public GetAbilityBoostListener
{
public:
	void Setup();

	void OnSetupInformation(StaticSymbols::ecl_UIExamine_SetupInformationProc* next, UIObject* self, bool clearPanel);
	virtual int OnGetAbilityBoost(CDivinityStats_Character* stats, AbilityType ability, bool excludeBoosts) override;

	bool _IsPreparingExamine = false;
};

END_NS()

