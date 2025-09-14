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
	CHECKBOX(ExtendedHotbar, L"Extended Hotbar", L"If enabled, the Hotbar UI will show 20 slots per row.<br>The maximum amount of hotbar slots (50) remains unchanged.");
	CHECKBOX(LockBottomBar, L"Lock Hotbar dragging by default", L"If enabled, the hotbar will be locked upon loading into a game, preventing slot contents from being dragged out of it.<br>You may use the lock button in the bottom left of the UI to lock/unlock dragging while playing.");
	CHECKBOX(ExtraTargetInfo, L"Show resistances by target healthbar", L"If enabled, the healthbar UI that shows while hovering over characters will show their resistances.");
	CHECKBOX(MoreWorldTooltips, L"Show world tooltips for containers", L"If enabled, world tooltips will be shown for all container items.");
	CHECKBOX(SharedLuckyCharmLooting, L"Shared Lucky Charm", L"If enabled, looting will use the highest Lucky Charm of all characters in the party. Does not affect any other Lucky Charm effects.");
	RenderComboBox(flashPlayer, (int)EpipSettings::Settings::AutoIdentifyMode, L"Auto-Identify", L"Determines whether newly-generated items should be automatically identified.<br>- Disabled: items will not be auto-identified.<br>- With requirements: items will be identified if anyone in the party meets the loremaster requirement and the party has an identifying glass.<br>- Always: items will always be identified regardless of requirements.", std::vector<STDWString>({
		L"Disabled",
		L"With requirements",
		L"Always",
		}), (int)gSettings->AutoIdentifyMode);
	RenderComboBox(flashPlayer, (int)EpipSettings::Settings::ExamineInformation, L"Examine UI Information", L"Controls the information displayed within the Examine UI.<br>- Vanilla: unchanged.<br>- Shared Loremaster: the highest Loremaster of all party members will be used to determine which information to show.<br>- Full information: all information is shown regardless of Loremaster.", std::vector<STDWString>({
		L"Vanilla",
		L"Shared Loremaster",
		L"Full information",
	}), (int)gSettings->ExamineInformation);
	CHECKBOX(AutoScrollListenedDialogues, L"Automatically scroll listened dialogues", L"If enabled, dialogs you're listening to in multiplayer will automatically scroll to new dialog lines.");
	CHECKBOX(AutoStopListening, L"Automatically stop listening to dialogues", L"If enabled, dialogs you're listening to will automatically close when the dialogue is finished by the player that started it.");
	CHECKBOX(InfiniteEquipmentDurability, L"Unlimited Equipment Durability", L"If enabled, weapons and armor will not lose durability from use, unless they are unrepairable.<br>Existing broken items will still need to be repaired.");
	CHECKBOX(InfiniteCarryWeight, L"Unlimited Carry Weight", L"If enabled, characters will no longer become overencumbered from surpassing their carry weight limit.<br>Existing overencumbered characters will remain overencumbered.");
	CHECKBOX(DeadPartyMemberXP, L"Always grant XP to dead party members", L"If enabled, dead party members will be able to receive experience in Tactician & Honour modes.");
	SLIDER(CameraMaxDistance, L"Maximum Camera Distance", L"Controls how far you can zoom out the camera.<br>Game default is 19m.", 19.0f, 30.0f, 1.0f);
	CHECKBOX(FixSkillRangeGFX, L"Fix skill range indicators", L"If enabled, skill range indicator circle effects will be shown even if the caster is not on screen.<br>Has a minimal performance impact.");

	RenderLabel(flashPlayer, L"Ep1p Developer Settings");
	CHECKBOX(FixDontCareScriptParam, L"Scripting Engine Collapse Fix", L"If enabled, a patch will be applied to prevent the scripting engine from randomly breaking.<br>If disabled, you will still be notified when Ep1p detects the scripting engine broke.");
	CHECKBOX(ForceStoryPatching, L"Force Story Patching", L"If enabled, story patching will be performed on each session load.<br>This will increase load times considerably.");
	CHECKBOX(StoryLogging, L"Story Logging", L"If enabled, story scripting will be logged to osirislog.log in the game executable's folder.<br>This will slow the game down considerably.");
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

bool GameOptionsSettings::OnInvoke1(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1)
{
	if (invokeEnum == UIGameOptionsMenu::Invokes::setTopTitle)
	{
		_PendingChanges = *gSettings;
		Render(ui->FlashPlayer);
	}
	return false;
}

bool GameOptionsSettings::OnFunctionCalled(const char* uiCall, int paramsCount, ig::InvokeDataValue* invokeData)
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
	return false;
}
