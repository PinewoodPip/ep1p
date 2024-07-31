#include "pch.h"
#include <format>
#include "Utils/Text.h"
#include "TargetInfo.h"
#include "Extender/ScriptExtender.h"
#include "Hooks/Hooks.h"
#include "Extender/Utils/CharacterUtils.h"
#include "Extender/Utils/Pointer.h"
#include "GameDefinitions/UI.h"
#include "Epip/EpipSettings.h"

using namespace dse;

void TargetInfo::Startup()
{
	gExtender->GetHooks().RegisterUIListener((int)UIObject::TypeID::TargetInfo, this);
}

int GetMaxAP(CDivinityStats_Character* stats)
{
	int maxAP = 0;
	for (auto dynStat : stats->DynamicStats)
	{
		maxAP += dynStat->APMaximum;
	}
	return maxAP;
}

STDWString GetResistancesString(ecl::Character* character)
{
	auto& symbols = GetStaticSymbols();
	CDivinityStats_Character* stats = character->Stats;
	int32_t fireResistance = symbols.CDivinityStats_Character__GetFireResistance(stats, false);
	int32_t waterResistance = symbols.CDivinityStats_Character__GetWaterResistance(stats, false);
	int32_t earthResistance = symbols.CDivinityStats_Character__GetEarthResistance(stats, false);
	int32_t airResistance = symbols.CDivinityStats_Character__GetAirResistance(stats, false);
	int32_t poisonResistance = symbols.CDivinityStats_Character__GetPoisonResistance(stats, false);
	int32_t tenebriumResistance = symbols.CDivinityStats_Character__GetShadowResistance(stats, false);
	std::string formattedResistances;

	if (character->PlayerData)
	{
		// Also show armor for players
		int armor = symbols.CDivinityStats_Character_GetDefenseFromLevel(stats, stats->Level, false);
		float armorDR = symbols.CDivinityStats_Character_GetDefenseDamageReduction(stats, stats->Level);

		formattedResistances = std::format("{}  {}  {}  {}  {}  {}\n{}  {}",
			Text::Colorize(std::format("{}%", std::to_string(fireResistance)), "f77c27"),
			Text::Colorize(std::format("{}%", std::to_string(waterResistance)), "27aff6"),
			Text::Colorize(std::format("{}%", std::to_string(earthResistance)), "aa7840"),
			Text::Colorize(std::format("{}%", std::to_string(airResistance)), "8f83cb"),
			Text::Colorize(std::format("{}%", std::to_string(poisonResistance)), "5bd42b"),
			Text::Colorize(std::format("{}%", std::to_string(tenebriumResistance)), "5b34ca"),
			Text::Colorize(std::format("Armor: {}", std::to_string(armor)), "acacac"),
			Text::Colorize(std::format("({:.0f}% Phys. DR)", armorDR * 100.0f), "acacac")
		);
	}
	else
	{
		// Also show pierce/crush/slash resistances for non-players
		int32_t slashingResistance = symbols.CDivinityStats_Character__GetSlashingResistance(stats, false);
		int32_t piercingResistance = symbols.CDivinityStats_Character__GetPiercingResistance(stats, false);
		int32_t crushingResistance = symbols.CDivinityStats_Character__GetCrushingResistance(stats, false);

		formattedResistances = std::format("{}  {}  {}  {}  {}  {}\n{}  {}  {}",
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
	}
	
	return STDWString(formattedResistances.begin(), formattedResistances.end());
}

ig::InvokeDataValue _CreateBoolInvokeData(bool value)
{
	ig::InvokeDataValue data = ig::InvokeDataValue();
	data.TypeId = ig::DataType::Bool;
	data.BoolVal = value;
	return data;
}

ig::InvokeDataValue _CreateStringInvokeData(STDWString value)
{
	ig::InvokeDataValue data = ig::InvokeDataValue();
	data.TypeId = ig::DataType::WString;
	data.StringVal = "";
	data.WStringVal = value;
	data.BoolVal = false;
	data.DoubleVal = 0;
	return data;
}

void TargetInfo::UpdateResistances(UITargetInfo* ui, ig::InvokeDataValue* labelInvokeData)
{
	ecl::Character* character = PointerUtils::GetCurrentPickerCharacter();
	ig::InvokeDataValue invokeData;

	TryRegisterInvokes((UITargetInfo*)ui);
	if (character && gSettings->ExtraTargetInfo)
	{
		// Show resistances under the healthbar
		STDWString resistancesStr = GetResistancesString(character);
		invokeData = _CreateStringInvokeData(resistancesStr);
	}
	else
	{
		invokeData = _CreateStringInvokeData(STDWString());
	}
	ui->FlashPlayer->Invoke1((uint64_t)UITargetInfo::Invokes::pipSetResistances, &invokeData);
}

void TargetInfo::UpdateHPBarText(UITargetInfo* ui)
{
	ecl::Character* character = PointerUtils::GetCurrentPickerCharacter();
	ig::InvokeDataValue invokeData;

	TryRegisterInvokes((UITargetInfo*)ui);
	if (character)
	{
		// Show current and max HP
		std::string healthBarHeaderLabel = std::format("{}/{} HP", character->Stats->CurrentHP, character->Stats->MaxHP);
		auto str = dse::STDWString(healthBarHeaderLabel.begin(), healthBarHeaderLabel.end());
		invokeData = _CreateStringInvokeData(str);
	}
	else
	{
		invokeData = _CreateStringInvokeData(STDWString());
	}
	ui->FlashPlayer->Invoke1((uint64_t)UITargetInfo::Invokes::pipSetHPBarText, &invokeData);
}

bool IsClientInCombat()
{
	auto manager = *gStaticSymbols->UIObjectManager__Instance;
	for (int i = 0; i < manager->UIObjectsCount; ++i)
	{
		auto ui = manager->UIObjects[i];
		if (ui->TypeId == (uint64_t)UIObject::TypeID::CombatTurn)
		{
			return true;
		}
	}
	return false;
}

bool TargetInfo::OnInvoke0(UIObject* ui, int64_t invokeEnum)
{
	if (invokeEnum == (uint64_t)UITargetInfo::Invokes::show)
	{
		// Update UI position offset
		TryRegisterInvokes((UITargetInfo*)ui);
		ig::InvokeDataValue invokeData = _CreateBoolInvokeData(IsClientInCombat());
		ui->FlashPlayer->Invoke1((uint64_t)UITargetInfo::Invokes::pipSetInCombat, &invokeData);
	}
	return false;
}

bool TargetInfo::OnInvoke2(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2)
{
	if (invokeEnum == (uint64_t)UITargetInfo::Invokes::setHPBars)
	{
		UpdateHPBarText((UITargetInfo*)ui);
	}
	return false;
}

bool TargetInfo::OnInvoke3(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2, ig::InvokeDataValue* invokeData3)
{
	if (invokeEnum == (uint64_t)UITargetInfo::Invokes::setText)
	{
		UpdateHPBarText((UITargetInfo*)ui);
		UpdateResistances((UITargetInfo*)ui, invokeData2);
	}
	return false;
}

void TargetInfo::TryRegisterInvokes(UITargetInfo* ui)
{
	if (ui->FlashPlayer->Invokes.size() <= (uint64_t)UITargetInfo::Invokes::pipSetHPBarText)
	{
		ui->FlashPlayer->AddInvokeName((uint64_t)UITargetInfo::Invokes::pipSetHPBarText, _strdup("pipUpdateHPText"));
		ui->FlashPlayer->AddInvokeName((uint64_t)UITargetInfo::Invokes::pipSetResistances, _strdup("pipUpdateResistancesText"));
		ui->FlashPlayer->AddInvokeName((uint64_t)UITargetInfo::Invokes::pipSetInCombat, _strdup("pipSetInCombat"));
	}
}
