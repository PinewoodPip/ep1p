#include "pch.h"
#include "SharedCivils.h"
#include "Extender/ScriptExtender.h"
#include "Epip/EpipSettings.h"

using namespace dse;
using namespace epip;

int GetLuck(CDivinityStats_Character* stats)
{
	int luck = 0;
	for (CharacterDynamicStat* dynStat : stats->DynamicStats)
	{
		luck += dynStat->Luck;
	}
	// TODO check for traits (romantic higher than pragmatic)
	if (GetStaticSymbols().CDivinityStats_Character_HasTalent(stats, TalentType::Luck, false))
	{
		luck += 1;
	}
	return luck;
}

void SharedCivils::Setup()
{
	auto& lib = gExtender->GetEngineHooks();
	if (gSettings->SharedLuckyCharmLooting)
	{
		gExtender->GetHooks().RegisterAbilityBoostListener(this);
		lib.esv_Item_GenerateTreasure.SetWrapper(&SharedCivils::OnItemGenerateTreasure, this);
	}
}

void SharedCivils::OnItemGenerateTreasure(StaticSymbols::esv_Item_GenerateTreasureProc* next, esv::Item* item, esv::Character* character)
{
	_GeneratingTreasure = true;
	next(item, character);
}

int SharedCivils::OnGetAbilityBoost(CDivinityStats_Character* stats, AbilityType ability, bool excludeBoosts)
{
	if (_GeneratingTreasure && ability == AbilityType::Luck)
	{
		_GeneratingTreasure = false;

		// Get the highest luck of all player characters
		int characterLuck = GetLuck(stats);
		int highestLuck = 0;
		esv::Character* character = nullptr;
		auto factory = *gStaticSymbols->ObjectFactory__esv_Character;
		for (auto otherCharacter : factory->Components)
		{
			if (otherCharacter->PlayerData != nullptr && otherCharacter->Stats != stats)
			{
				highestLuck = std::max(highestLuck, GetLuck(otherCharacter->Stats));
			}
		}
		// Add a boost to bring the calculated Lucky Charm to the maximum of all party members.
		return std::max(0, highestLuck - characterLuck);
	}
	return 0;
}
