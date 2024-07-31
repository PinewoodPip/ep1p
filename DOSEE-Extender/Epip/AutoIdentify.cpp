#include "pch.h"
#include "AutoIdentify.h"
#include "Extender/Utils/CharacterUtils.h"
#include <Extender/ScriptExtender.h>
#include "Hooks/Hooks.h"
#include "Epip/EpipSettings.h"

using namespace dse;
using namespace epip;

void AutoIdentify::Setup()
{
	auto& lib = gExtender->GetEngineHooks();
	lib.esv_ItemHelpers_GenerateTreasureItem.SetWrapper(&AutoIdentify::OnTreasureItemGenerated, this);
}

esv::Item* AutoIdentify::OnTreasureItemGenerated(StaticSymbols::esv_ItemHelpers_GenerateTreasureItemProc* next, void* request, int16_t unknown)
{
	esv::Item* item = next(request, unknown);
	if (item->Stats)
	{
		// Set newly-generated items to be identified. This happens before to-client sync.
		item->Stats->IdentifiedState = CanAutoIdentify(item);
	}
	return item;
}

bool AutoIdentify::CanAutoIdentify(esv::Item* item)
{
	auto setting = gSettings->AutoIdentifyMode;
	if (setting == EpipSettings::AutoIdentifyModeChoices::Disabled)
	{
		return false;
	}
	else if (setting == EpipSettings::AutoIdentifyModeChoices::Always)
	{
		return true;
	}
	else if (setting == EpipSettings::AutoIdentifyModeChoices::WithRequirements)
	{
		// "With requirements" mode
		int identifyRequirement = 1;
		int level = item->Stats->Level;
		if (level > 17)
		{
			identifyRequirement = 5;
		}
		else if (level > 14)
		{
			identifyRequirement = 4;
		}
		else if (level > 10)
		{
			identifyRequirement = 3;
		}
		else if (level > 5)
		{
			identifyRequirement = 2;
		}
		bool hasIdentifyingGlass = false;
		auto partyMembers = ServerCharacterUtils::GetPartyMembers();
		int highestLoremaster = 0;
		for (auto character : *partyMembers)
		{
			highestLoremaster = std::max(highestLoremaster, SharedCharacterUtils::GetLoremaster(character->Stats));
			hasIdentifyingGlass = hasIdentifyingGlass || ServerCharacterUtils::HasItemWithUseAction(character, eoc::IActionData::ActionType::Identify);
		}
		return hasIdentifyingGlass && (highestLoremaster >= identifyRequirement);
	}
	WARN("Unknown auto-identify mode");
	return false;
}
