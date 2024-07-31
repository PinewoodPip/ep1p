#include "pch.h"
#include "Extender/Utils/CharacterUtils.h"
#include "Epip/EpipSettings.h"
#include "ExamineTweaks.h"
#include "Extender/ScriptExtender.h"

using namespace dse;
using namespace epip;

void ExamineTweaks::Setup()
{
	auto& lib = gExtender->GetEngineHooks();
	lib.ecl_UIExamine_SetupInformation.SetWrapper(&ExamineTweaks::OnSetupInformation, this);
	gExtender->GetHooks().RegisterAbilityBoostListener(this);
}

void ExamineTweaks::OnSetupInformation(StaticSymbols::ecl_UIExamine_SetupInformationProc* next, UIObject* self, bool clearPanel)
{
	_IsPreparingExamine = true;
	return next(self, clearPanel);
}

int ExamineTweaks::OnGetAbilityBoost(CDivinityStats_Character* stats, AbilityType ability, bool excludeBoosts)
{
	if (_IsPreparingExamine)
	{
		_IsPreparingExamine = false;

		auto setting = gSettings->ExamineInformation;
		int characterLoremaster = SharedCharacterUtils::GetLoremaster(stats);
		if (setting == EpipSettings::ExamineInformationChoices::FullInformation)
		{
			// Add a boost to bring loremaster to 5
			return std::max(0, 5 - characterLoremaster);
		}
		else if (setting == EpipSettings::ExamineInformationChoices::SharedLoremaster)
		{
			// Get the highest loremaster of all player characters
			int highestLoremaster = 0;
			esv::Character* character = nullptr;
			auto factory = *gStaticSymbols->ObjectFactory__esv_Character;
			for (auto otherCharacter : factory->Components)
			{
				if (otherCharacter->PlayerData != nullptr && otherCharacter->Stats != stats)
				{
					highestLoremaster = std::max(highestLoremaster, SharedCharacterUtils::GetLoremaster(otherCharacter->Stats));
				}
			}
			// Add a boost to bring the calculated Lucky Charm to the maximum of all party members.
			return std::max(0, highestLoremaster - characterLoremaster);
		}
	}
	return 0;
}
