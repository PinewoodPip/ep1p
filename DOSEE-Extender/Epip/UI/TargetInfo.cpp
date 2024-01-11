#include "pch.h"
#include <format>
#include "Utils/Text.h"
#include "TargetInfo.h"
#include "Extender/ScriptExtender.h"
#include "Hooks/Hooks.h"
#include "Extender/Utils/CharacterUtils.h"
#include "GameDefinitions/UI.h"

using namespace dse;

void TargetInfo::Startup()
{
	gExtender->GetHooks().RegisterUIListener(UITypeID::UITypeID_TargetInfo, this);
}

bool TargetInfo::OnInvoke3(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2, ig::InvokeDataValue* invokeData3)
{
	if (invokeEnum == 9) // setText
	{
		ComponentHandle pointerCharacterHandle = gExtender->GetHooks().LastPickerCharacterHandle;
		UITargetInfo* targetInfoUI = (UITargetInfo*)ui;
		targetInfoUI->ShowHP = true;
		ecl::Character* character = ClientCharacterUtils::GetCharacter(gExtender->GetHooks().LastPickerCharacterHandle);

		if (character)
		{
			// Show resistances under the healthbar
			CDivinityStats_Character* stats = character->Stats;
			int32_t slashingResistance = GetStaticSymbols().CDivinityStats_Character__GetSlashingResistance(stats, false);
			int32_t piercingResistance = GetStaticSymbols().CDivinityStats_Character__GetPiercingResistance(stats, false);
			int32_t crushingResistance = GetStaticSymbols().CDivinityStats_Character__GetCrushingResistance(stats, false);
			int32_t fireResistance = GetStaticSymbols().CDivinityStats_Character__GetFireResistance(stats, false);
			int32_t waterResistance = GetStaticSymbols().CDivinityStats_Character__GetWaterResistance(stats, false);
			int32_t earthResistance = GetStaticSymbols().CDivinityStats_Character__GetEarthResistance(stats, false);
			int32_t airResistance = GetStaticSymbols().CDivinityStats_Character__GetAirResistance(stats, false);
			int32_t poisonResistance = GetStaticSymbols().CDivinityStats_Character__GetPoisonResistance(stats, false);
			int32_t tenebriumResistance = GetStaticSymbols().CDivinityStats_Character__GetShadowResistance(stats, false);
			std::string formattedResistances = std::format("{}  {}  {}  {}  {}  {}\n{}  {}  {}",
				Text::Colorize(std::format("{}%", std::to_string(fireResistance)), "f77c27"),
				Text::Colorize(std::format("{}%", std::to_string(waterResistance)), "27aff6"),
				Text::Colorize(std::format("{}%", std::to_string(earthResistance)), "aa7840"),
				Text::Colorize(std::format("{}%", std::to_string(airResistance)), "8f83cb"),
				Text::Colorize(std::format("{}%", std::to_string(poisonResistance)), "5bd42b"),
				Text::Colorize(std::format("{}%", std::to_string(tenebriumResistance)), "5b34ca"),
				Text::Colorize(std::format("S: {}%", std::to_string(slashingResistance)), "acacac"),
				Text::Colorize(std::format("P: {}%", std::to_string(piercingResistance)), "acacac"),
				Text::Colorize(std::format("C: {}%", std::to_string(crushingResistance)), "acacac")
			);
			invokeData2->WStringVal = dse::STDWString(formattedResistances.begin(), formattedResistances.end());

			// Show current and max HP besides name
			std::string healthBarHeaderLabel = std::format("{} - {}/{} HP", std::string(invokeData1->WStringVal.begin(), invokeData1->WStringVal.end()), character->Stats->CurrentHP, character->Stats->MaxHP);
			invokeData1->WStringVal = dse::STDWString(healthBarHeaderLabel.begin(), healthBarHeaderLabel.end());
		}
	}
	return false;
}
