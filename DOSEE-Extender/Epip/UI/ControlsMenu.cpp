#include "pch.h"
#include "ControlsMenu.h"
#include "Extender/ScriptExtender.h"
#include "Extender/Utils/UIUtils.h"

using namespace epip;

void ControlsMenu::Setup()
{
	gExtender->GetHooks().RegisterUIListener((int)UIObject::TypeID::OptionsInput, this);

	// Create inverse lookup maps
	for (auto pair : STR_TO_RAWINPUT)
	{
		RAWINPUT_TO_STR.insert({{ pair.second, pair.first }});
	}
	for (auto pair : ENTRYID_TO_EPIP_SETTING)
	{
		EPIP_SETTING_TO_ENTRY_ID.insert({ { pair.second.SettingsID, pair.first } });
	}
}

bool ControlsMenu::OnInvoke1(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* a1)
{
	// Add entries for Ep1p keybinds;
	// done with setTitle invoke as it occurs before the vanilla entries are added,
	// thus placing Ep1p's at the top of the menu.
	if (invokeEnum == UIControlsMenu::Invokes::setTitle)
	{
		RenderEntries(ui);
	}

	if (invokeEnum == UIControlsMenu::Invokes::changeOverlayText && _CurrentKeybind)
	{
		// Parse the entered keybind from the string passed to the UI
		auto stringValue = std::wstring(a1->WStringVal);
		std::wstring baseLabel = stringValue;
		std::wstring modifierLabel;

		// Search for chord delimiter
		std::wstring delimiter = L" + ";
		int index = stringValue.find(delimiter);
		if (index >= 0)
		{
			baseLabel = stringValue.substr(index + delimiter.length());
			modifierLabel = L"L" + stringValue.substr(0, index); // Only allow left-side modifiers (ex. "left shift"); the UI cannot distinguish the pairs of modifier keys.
		}

		// Parse the RawInput IDs
		if (STR_TO_RAWINPUT.contains(baseLabel))
		{
			int keybind = STR_TO_RAWINPUT.at(baseLabel);

			// Track the selected keybind
			_CurrentInput = (RawInputType)keybind;
			ui->FlashPlayer->Invoke0(UIControlsMenu::Invokes::enableSaveButton); // Allow saving keybinds

			// Parse modifier; nested within the parent if to disallow binding only modifiers by themselves.
			if (STR_TO_RAWINPUT.contains(modifierLabel))
			{
				int keybind = STR_TO_RAWINPUT.at(modifierLabel);
				if (UIUtils::IsModifierKey((RawInputType)keybind))
				{
					_CurrentModifier = (RawInputType)keybind;
				}
			}
			else
			{
				_CurrentModifier = None;
			}
		}
	}
	return false;
}

// Sets the binding label for an entry
void ControlsMenu::SetKeybindLabel(UIObject* ui, int entryID, EpipKeybind keybind)
{
	int baseBinding;
	int modifierBinding;
	GetKeybind(keybind.SettingsID, keybind.ModifierSettingsID, baseBinding, modifierBinding);

	// Set the label
	ig::InvokeDataValue entryIDData = UIUtils::CreateDoubleInvokeData(entryID);
	ig::InvokeDataValue inputIndex = UIUtils::CreateDoubleInvokeData(0);
	ig::InvokeDataValue label = UIUtils::CreateStringInvokeData(STDWString(GetKeybindLabel((RawInputType)modifierBinding, (RawInputType)baseBinding)));
	ui->FlashPlayer->Invoke3(UIControlsMenu::Invokes::setInput, &entryIDData, &inputIndex, &label);
}

// Renders the custom keybind entries onto the UI
void ControlsMenu::RenderEntries(UIObject* ui)
{
	// Register new invokes first;
	// Since this UI is re-created each time the menu is accessed,
	// it's not sufficient to only do this once.
	if (ui->FlashPlayer->Invokes.size() <= (uint64_t)UIControlsMenu::Invokes::pipHideSecondInput)
	{
		ui->FlashPlayer->AddInvokeName((uint64_t)UIControlsMenu::Invokes::pipHideSecondInput, _strdup("pipHideSecondInput"));
	}

	// Render keybinds
	int currentID = STARTING_ENTRYID;
	while (ENTRYID_TO_EPIP_SETTING.contains(currentID))
	{
		EpipKeybind keybind = ENTRYID_TO_EPIP_SETTING.at(currentID); // TODO can a copy here be avoided?

		// Add entry
		ig::InvokeDataValue param1 = UIUtils::CreateDoubleInvokeData(0); // Functionality for multiple tabs is unused by the game.
		ig::InvokeDataValue param2 = UIUtils::CreateDoubleInvokeData(currentID);
		ig::InvokeDataValue param3 = UIUtils::CreateStringInvokeData(STDWString(keybind.Name));
		ig::InvokeDataValue param4 = UIUtils::CreateStringInvokeData(L""); // Will be overwritten by the invoke below.
		ui->FlashPlayer->Invoke4(UIControlsMenu::Invokes::addEntry, &param1, &param2, &param3, &param4);

		SetKeybindLabel(ui, currentID, keybind);

		// Hide 2nd input field
		ig::InvokeDataValue secondInputTabID = UIUtils::CreateDoubleInvokeData(0);
		ig::InvokeDataValue secondInputEntryID = UIUtils::CreateDoubleInvokeData(currentID);
		ui->FlashPlayer->Invoke2(UIControlsMenu::Invokes::pipHideSecondInput, &secondInputTabID, &secondInputEntryID);

		currentID++;
	}
}

// Stringifies a keybind.
STDWString ControlsMenu::GetKeybindLabel(RawInputType modifier, RawInputType baseKey)
{
	auto label = STDWString();
	if (modifier != None)
	{
		label.append(RAWINPUT_TO_STR.at(modifier));
		label.append(L" + ");
	}
	label.append(RAWINPUT_TO_STR.at(baseKey));
	return label;
}

// Returns the RawInput IDs for a keybind.
void ControlsMenu::GetKeybind(EpipSettings::Settings baseKeySetting, EpipSettings::Settings modifierKeySetting, int& baseKey, int& modifierKey)
{
	// TODO this fucking sucks. Settings should've been an object to begin with instead of an enum.
	switch (baseKeySetting)
	{	
	case dse::epip::EpipSettings::Settings::ExamineKeybind:
		baseKey = gSettings->ExamineKeybind;
		break;
	case dse::epip::EpipSettings::Settings::TogglePartyChainKeybind:
		baseKey = gSettings->TogglePartyChainKeybind;
		break;
	case dse::epip::EpipSettings::Settings::TogglePartySneakKeybind:
		baseKey = gSettings->TogglePartySneakKeybind;
		break;
	default:
		break;
	}
	switch (modifierKeySetting)
	{
	case dse::epip::EpipSettings::Settings::ExamineKeybindModifier:
		modifierKey = gSettings->ExamineKeybindModifier;
		break;
	case dse::epip::EpipSettings::Settings::TogglePartyChainKeybindModifier:
		modifierKey = gSettings->TogglePartyChainKeybindModifier;
		break;
	case dse::epip::EpipSettings::Settings::TogglePartySneakKeybindModifier:
		modifierKey = gSettings->TogglePartySneakKeybindModifier;
		break;
	default:
		break;
	}
}

bool ControlsMenu::OnFunctionCalled(UIObject* ui, const char* uiCall, int paramsCount, ig::InvokeDataValue* invokeData)
{
	bool isChangingEpipKeybind = _CurrentKeybind.has_value();
	if (strcmp(uiCall, "SaveKeyChanges") == 0)
	{
		// Save settings, which includes keybinds
		gSettings->Save();
	}
	else if (strcmp(uiCall, "changingKey") == 0 || strcmp(uiCall, "inputCancelPressed") == 0)
	{
		// Track requests to rebind Epip keybinds
		if (invokeData)
		{
			int keyID = (int)invokeData[0].DoubleVal;
			if (ENTRYID_TO_EPIP_SETTING.contains(keyID))
			{
				_CurrentKeybind.emplace(ENTRYID_TO_EPIP_SETTING.at(keyID).SettingsID);
				_CurrentInput = None;
				_CurrentModifier = None;
			}
		}
		else // inputCancelPressed case (which is parameterless)
		{
			_CurrentKeybind.reset();
			_CurrentInput = None;
			_CurrentModifier = None;
		}
	}
	else if (strcmp(uiCall, "stopChangingKey") == 0)
	{
		_CurrentKeybind.reset();
	}
	else if (strcmp(uiCall, "inputAcceptPressed") == 0 && isChangingEpipKeybind)
	{
		// Set keybind
#define EPIP_FOR_SETTING(setting) \
	if (EpipSettings::Settings::setting == _CurrentKeybind.value()) \
	{ \
		gSettings->setting = _CurrentInput; \
		gSettings->setting##Modifier = _CurrentModifier; \
	} \

		EPIP_FOR_ALL_BASE_KEYBIND_SETTINGS();
#undef EPIP_FOR_SETTING

		// Update the keybind label
		int entryID = EPIP_SETTING_TO_ENTRY_ID.at(_CurrentKeybind.value());
		SetKeybindLabel(ui, entryID, ENTRYID_TO_EPIP_SETTING.at(entryID));
	}
	else if (strcmp(uiCall, "inputClearPressed") == 0 && isChangingEpipKeybind)
	{
		// Clear keybind
#define EPIP_FOR_SETTING(setting) \
	if (EpipSettings::Settings::setting == _CurrentKeybind.value()) \
	{ \
		gSettings->setting = RawInputType::None; \
		gSettings->setting##Modifier = RawInputType::None; \
	} \

		EPIP_FOR_ALL_BASE_KEYBIND_SETTINGS();
#undef EPIP_FOR_SETTING

		// Update the keybind label
		int entryID = EPIP_SETTING_TO_ENTRY_ID.at(_CurrentKeybind.value());
		SetKeybindLabel(ui, entryID, ENTRYID_TO_EPIP_SETTING.at(entryID));
	}
	return false;
}
