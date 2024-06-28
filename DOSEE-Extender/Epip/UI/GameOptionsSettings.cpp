#include "pch.h"
#include "GameOptionsSettings.h"
#include "Extender/ScriptExtender.h"

using namespace epip;

void GameOptionsSettings::Setup()
{
	gExtender->GetHooks().RegisterUIListener((int)UIObject::TypeID::OptionsSettings_Gameplay, this);
}

ig::InvokeDataValue CreateDoubleInvokeData(int value)
{
	ig::InvokeDataValue data = ig::InvokeDataValue();
	data.TypeId = ig::DataType::Double;
	data.DoubleVal = value;
	return data;
}

ig::InvokeDataValue CreateBoolInvokeData(bool value)
{
	ig::InvokeDataValue data = ig::InvokeDataValue();
	data.TypeId = ig::DataType::Bool;
	data.BoolVal = value;
	return data;
}

ig::InvokeDataValue CreateStringInvokeData(STDWString value)
{
	ig::InvokeDataValue data = ig::InvokeDataValue();
	data.TypeId = ig::DataType::WString;
	data.WStringVal = value;
	data.StringVal = "";
	data.BoolVal = false;
	data.DoubleVal = 0;
	return data;
}

void GameOptionsSettings::Render(ig::FlashPlayer* flashPlayer)
{
	RenderLabel(flashPlayer, L"Ep1p Settings");
#define CHECKBOX(setting, name, tooltip) RenderCheckbox(flashPlayer, (int)EpipSettings::Settings::setting, name, true, gSettings->setting, false, tooltip);
#define SLIDER(setting, name, tooltip, minimum, maximum, snapInterval) RenderSlider(flashPlayer, (int)EpipSettings::Settings::setting, name, gSettings->setting, minimum, maximum, snapInterval, false, tooltip);
	CHECKBOX(ExtendedHotbar, L"Extended Hotbar", L"If enabled, the Hotbar UI will show 20 slots at a time.");
	CHECKBOX(ExtraTargetInfo, L"Show target resistances", L"If enabled, the target healthbar UI will show resistances of characters.");
	CHECKBOX(MoreWorldTooltips, L"Show world tooltips for containers", L"If enabled, world tooltips will be shown for all container items.");
	CHECKBOX(DeadPartyMemberXP, L"Grant XP to dead party members", L"If enabled, dead party members will still be able to receive experience in Tactician & Honour modes.");
	CHECKBOX(SharedLuckyCharmLooting, L"Shared Lucky Charm (looting-only)", L"If enabled, looting will use the highest Lucky Charm of all characters in the party.");
	CHECKBOX(AutoIdentify, L"Auto-Identify", L"If enabled, new looted items will not require to be identified.");
	RenderComboBox(flashPlayer, (int)EpipSettings::Settings::ExamineInformation, L"Examine UI Information", L"Controls the information displayed within the Examine UI.<br>- Vanilla: unchanged.<br>- Shared Loremaster: the highest Loremaster of all party members will be used to determine which information to show.<br>- Full information: all information is shown regardless of Loremaster.", std::vector<STDWString>({
		L"Vanilla",
		L"Shared Loremaster",
		L"Full information",
	}), (int)gSettings->ExamineInformation);
	CHECKBOX(InfiniteEquipmentDurability, L"Infinite Equipment Durability", L"If enabled, weapons and armor will not lose durability from use.<br>Existing broken items will still need to be repaired.");
	CHECKBOX(InfiniteCarryWeight, L"Infinite Carry Weight", L"If enabled, characters will no longer become overencumbered from surpassing their carry weight limit.<br>Existing overencumbered characters will remain overencumbered.");
	CHECKBOX(FixSkillRangeGFX, L"Fix Skill Range Indicators", L"If enabled, skill range indicator circle effects will be shown even if the caster is not on screen.<br>Has a minimal performance impact.");
	SLIDER(CameraMaxDistance, L"Maximum Camera Distance", L"Controls how far you can zoom out the camera.<br>Game default is 19m.", 19.0f, 30.0f, 1.0f);

	RenderLabel(flashPlayer, L"Ep1p Developer Settings");
	CHECKBOX(FixDontCareScriptParam, L"Scripting Engine Collapse Fix", L"If enabled, a patch will be applied to prevent the scripting engine from randomly breaking.<br>Don't disable this unless you know what you're doing!");
	CHECKBOX(ForceStoryPatching, L"Force Story Patching", L"If enabled, story patching will be performed on each session load.");
	CHECKBOX(StoryLogging, L"Story Logging", L"If enabled, story scripting will be logged to osirislog.log in the game executable's folder. This will slow the game down considerably.");
#undef CHECKBOX
}

void GameOptionsSettings::RenderLabel(ig::FlashPlayer* flashPlayer, STDWString label)
{
	ig::InvokeDataValue param1 = CreateStringInvokeData(label);

	flashPlayer->Invoke1(UIGameOptionsMenu::Invokes::addMenuLabel, &param1);
}

void GameOptionsSettings::RenderComboBox(ig::FlashPlayer* flashPlayer, int id, STDWString label, STDWString tooltip, std::vector<STDWString> options, int selectedIndex)
{
	ig::InvokeDataValue param1 = CreateDoubleInvokeData(id);
	ig::InvokeDataValue param2 = CreateStringInvokeData(label);
	ig::InvokeDataValue param3 = CreateStringInvokeData(tooltip);

	flashPlayer->Invoke3(UIGameOptionsMenu::Invokes::addMenuDropDown, &param1, &param2, &param3);

	// Add dropdown entries
	for (auto option : options)
	{
		param1 = CreateDoubleInvokeData(id);
		ig::InvokeDataValue optionParam = CreateStringInvokeData(option);

		flashPlayer->Invoke2((int64_t)UIGameOptionsMenu::Invokes::addMenuDropDownEntry, &param1, &optionParam);
	}
	param1 = CreateDoubleInvokeData(id);
	ig::InvokeDataValue selectedIndexParam = CreateDoubleInvokeData(selectedIndex);
	flashPlayer->Invoke2(UIGameOptionsMenu::Invokes::selectMenuDropDownEntry, &param1, &selectedIndexParam);
}

void GameOptionsSettings::RenderCheckbox(ig::FlashPlayer* flashPlayer, const int id, const STDWString label, bool enabled, int stateID, bool filtered, const STDWString tooltip)
{
	ig::InvokeDataValue param1 = CreateDoubleInvokeData(id);
	ig::InvokeDataValue param2 = CreateStringInvokeData(label);
	ig::InvokeDataValue param3 = CreateBoolInvokeData(enabled);
	ig::InvokeDataValue param4 = CreateDoubleInvokeData(stateID);
	ig::InvokeDataValue param5 = CreateBoolInvokeData(filtered);
	ig::InvokeDataValue param6 = CreateStringInvokeData(tooltip);

	flashPlayer->Invoke6(UIGameOptionsMenu::Invokes::addMenuCheckbox, &param1, &param2, &param3, &param4, &param5, &param6);
}

void GameOptionsSettings::RenderSlider(ig::FlashPlayer* flashPlayer, const int id, const STDWString label, float amount, float minimum, float maximum, int snapInterval, bool hideNumbers, const STDWString tooltip)
{
	ig::InvokeDataValue param1 = CreateDoubleInvokeData(id);
	ig::InvokeDataValue param2 = CreateStringInvokeData(label);
	ig::InvokeDataValue param3 = CreateDoubleInvokeData(amount);
	ig::InvokeDataValue param4 = CreateDoubleInvokeData(minimum);
	ig::InvokeDataValue param5 = CreateDoubleInvokeData(maximum);
	ig::InvokeDataValue param6 = CreateDoubleInvokeData(snapInterval);
	ig::InvokeDataValue param7 = CreateBoolInvokeData(hideNumbers);
	ig::InvokeDataValue param8 = CreateStringInvokeData(tooltip);
	std::vector params{ param1, param2, param3, param4, param5, param6, param7, param8 };

	flashPlayer->InvokeArgs(UIGameOptionsMenu::Invokes::addMenuSlider, params.data(), params.size());
	// Not sure in which situation setValue() would be necessary, addMenuSlider already passes default value
}

void GameOptionsSettings::ApplyPendingChanges()
{
	if (_HasPendingChanges)
	{
		*gSettings = _PendingChanges;
		_HasPendingChanges = false;
		SaveToFile();
		gStaticSymbols->ecl_EocUIControl_ShowCommonMessageBox(*gStaticSymbols->ecl_EocUIControl, const_cast<wchar_t*>(L"You must restart the game for changes to Ep1p settings to take effect."));
	}
}

void GameOptionsSettings::SaveToFile()
{
	gSettings->Save();
}

bool GameOptionsSettings::OnInvoke0(UIObject* ui, int64_t invokeEnum)
{
	return false;
}

bool GameOptionsSettings::OnInvoke1(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1)
{
	if (invokeEnum == UIGameOptionsMenu::Invokes::setTopTitle)
	{
		_PendingChanges = *gSettings;
		Render(ui->FlashPlayer);
	}
	return false;
}

void GameOptionsSettings::OnFunctionCalled(const char* uiCall, int paramsCount, ig::InvokeDataValue* invokeData)
{
	if (strcmp(uiCall, "checkBoxID") == 0)
	{
		auto id = invokeData[0].DoubleVal;
		auto checked = invokeData[1].DoubleVal;
		_PendingChanges.SetByID(id, checked > 0); // Fuck their filtered state bs
		_HasPendingChanges = true;
	}
	else if (strcmp(uiCall, "comboBoxID") == 0)
	{
		auto id = invokeData[0].DoubleVal;
		auto index = invokeData[1].DoubleVal;
		_PendingChanges.SetByID(id, (int)index);
		_HasPendingChanges = true;
	}
	else if (strcmp(uiCall, "menuSliderID") == 0)
	{
		auto id = invokeData[0].DoubleVal;
		auto index = invokeData[1].DoubleVal;
		_PendingChanges.SetByID(id, (float)index);
		_HasPendingChanges = true;
	}
	else if (strcmp(uiCall, "applyPressed") == 0)
	{
		ApplyPendingChanges();
	}
}
