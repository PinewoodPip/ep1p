#pragma once
#include "UI/TargetInfo.h"
#include "WorldTooltips.h"
#include "InfiniteCarryWeight.h"
#include "ScriptBugWatchdog.h"
#include "SkillRangeEffectFix.h"
#include "OsirisImprovements.h"
#include "EquipmentDegradation.h"
#include "SharedCivils.h"
#include "AutoIdentify.h"

using namespace epip;

class Epip
{
public:
	void Startup();
private:
	TargetInfo _TargetInfo;
	KeyboardBottomBar _KeyboardBottomBar;
	WorldTooltips _WorldTooltips;
	InfiniteCarryWeight _InfiniteCarryWeight;
	ScriptBugWatchdog _ScriptBugWatchdog;
	SkillRangeEffectsFix _SkillRangeEffectsFix;
	OsirisImprovements _OsirisImprovements;
	EquipmentDegradation _EquipmentDegradation;
	SharedCivils _SharedCivils;
	AutoIdentify _AutoIdentify;
};

extern std::unique_ptr<Epip> gEpip;
