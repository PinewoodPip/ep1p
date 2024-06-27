#pragma once
#include "EpipSettings.h"
#include "UI/TargetInfo.h"
#include "UI/GameOptionsSettings.h"
#include "WorldTooltips.h"
#include "InfiniteCarryWeight.h"
#include "ScriptBugWatchdog.h"
#include "SkillRangeEffectFix.h"
#include "OsirisImprovements.h"
#include "EquipmentDegradation.h"
#include "SharedCivils.h"
#include "AutoIdentify.h"
#include "DeadPartyXP.h"
#include "UI/ExamineTweaks.h"

using namespace epip;

BEGIN_NS(epip)

class Epip
{
public:
	void Startup();
	void LoadConfig(std::wstring const& configPath, EpipSettings& config);
private:
	TargetInfo _TargetInfo;
	KeyboardBottomBar _KeyboardBottomBar;
	GameOptionsSettings _GameOptionsSettings;
	WorldTooltips _WorldTooltips;
	InfiniteCarryWeight _InfiniteCarryWeight;
	ScriptBugWatchdog _ScriptBugWatchdog;
	SkillRangeEffectsFix _SkillRangeEffectsFix;
	OsirisImprovements _OsirisImprovements;
	EquipmentDegradation _EquipmentDegradation;
	SharedCivils _SharedCivils;
	AutoIdentify _AutoIdentify;
	DeadPartyXP _DeadPartyXP;
	ExamineTweaks _ExamineTweaks;
};

END_NS()

extern std::unique_ptr<Epip> gEpip;
