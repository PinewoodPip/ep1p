#include "pch.h"
#include "Epip/EpipSettings.h"
#include "Extender/Utils/UIUtils.h"
#include "KeyboardBottomBar.h"
#include "Extender/ScriptExtender.h"
#include "ControllerEquipmentPanel.h"
#include <Extender/Utils/CharacterUtils.h>

using namespace dse;
using namespace epip;

void ControllerEquipmentPanel::Setup()
{
	gExtender->GetHooks().RegisterUIListener((int)UIObject::TypeID::ControllerEquipmentPanel, this);
	gExtender->GetHooks().RegisterUIListener((int)UIObject::TypeID::ControllerObjectContextMenu, this); // Normal context menu is never used(?)
}

// TODO consolidate
ig::InvokeDataValue CreateDoubleInvokeDataTemp(int value)
{
	ig::InvokeDataValue data = ig::InvokeDataValue();
	data.TypeId = ig::DataType::Double;
	data.DoubleVal = value;
	return data;
}
ig::InvokeDataValue CreateStringInvokeDataTemp(STDWString value)
{
	ig::InvokeDataValue data = ig::InvokeDataValue();
	data.TypeId = ig::DataType::WString;
	data.WStringVal = value;
	data.StringVal = "";
	data.BoolVal = false;
	data.DoubleVal = 0;
	return data;
}

// TODO move to a utility class
void AddContextMenuEntry(UIObject* ui, STDWString label, int entryID, int actionID)
{
	ig::InvokeDataValue invokeData1ID = CreateDoubleInvokeDataTemp(entryID);
	ig::InvokeDataValue invokeData2ActionID = CreateDoubleInvokeDataTemp(actionID);
	ig::InvokeDataValue invokeData3Handle = CreateDoubleInvokeDataTemp(0); // Doesn't matter
	ig::InvokeDataValue invokeData4Unused = CreateStringInvokeDataTemp(label);
	ig::InvokeDataValue invokeData5Label = CreateStringInvokeDataTemp(label);
	ui->FlashPlayer->Invoke5(UIContextMenu::Invokes::addButton, &invokeData1ID, &invokeData2ActionID, &invokeData3Handle, &invokeData4Unused, &invokeData5Label);
}
// Overload for same entryID & actionID
void AddContextMenuEntry(UIObject* ui, STDWString label, int actionID)
{
	AddContextMenuEntry(ui, label, actionID, actionID);
}

void ControllerEquipmentPanel::AfterInvoke0(UIObject* ui, int64_t invokeEnum)
{
	if (ui->TypeId == (int32_t)UIObject::TypeID::ControllerObjectContextMenu)
	{
		// Add context menu options for toggling helmet state
		if (invokeEnum == UIContextMenu::Invokes::updateButtons && _NextItemIsHelmet)
		{
			ecl::Character* character = ClientCharacterUtils::GetPlayerCharacter();
			auto helmetState = character->PlayerData->HelmetOptionState;
			if (helmetState != 0)
			{
				AddContextMenuEntry(ui, L"Hide helmet", CONTEXT_MENU_ACTION_IDS::HIDE_HELMET);
			}
			if (helmetState != 1)
			{
				AddContextMenuEntry(ui, L"Always show helmet", CONTEXT_MENU_ACTION_IDS::ALWAYS_SHOW_HELMET);
			}
			if (helmetState != 2)
			{
				AddContextMenuEntry(ui, L"Only show helmet in combat", CONTEXT_MENU_ACTION_IDS::SHOW_HELMET_IN_COMBAT);
			}
			_NextItemIsHelmet = false;
		}
	}
}

bool ControllerEquipmentPanel::OnFunctionCalled(UIObject* ui, const char* uiCall, int paramsCount, ig::InvokeDataValue* invokeData)
{
	if (strcmp(uiCall, "showDollActionMenuItem") == 0) // From equipment UI
	{
		float flashItemHandle = invokeData[0].DoubleVal;
		uint32_t itemHandleInt = *(reinterpret_cast<uint32_t*>(&flashItemHandle));
		ecl::Item* item = (*gStaticSymbols->ObjectFactory__ecl_Item)->Get((ComponentHandle)itemHandleInt);

		// Check whether the context menu is for an equipped helmet
		if (item && item->InventoryHandle_mOrParent)
		{
			ecl::Inventory* inv = (*gStaticSymbols->ecl_InventoryFactory)->Get((ComponentHandle)item->InventoryHandle_mOrParent);
			ObjectHandle equippedHelmet = inv->ItemHandles[0]; // Helmet slot
			if (equippedHelmet == (ComponentHandle)itemHandleInt)
			{
				_NextItemIsHelmet = true;
			}
		}
	}
	else if (strcmp(uiCall, "buttonPressed") == 0) // From context menu
	{
		// Set helmet state
		int actionID = invokeData[0].DoubleVal;
		if (actionID >= CONTEXT_MENU_ACTION_IDS::HIDE_HELMET)
		{
			ecl::Character* character = ClientCharacterUtils::GetPlayerCharacter();
			switch (actionID)
			{
				case CONTEXT_MENU_ACTION_IDS::HIDE_HELMET:
				{
					character->PlayerData->HelmetOptionState = 0;
					break;
				}
				case CONTEXT_MENU_ACTION_IDS::ALWAYS_SHOW_HELMET:
				{
					character->PlayerData->HelmetOptionState = 1;
					break;
				}
				case CONTEXT_MENU_ACTION_IDS::SHOW_HELMET_IN_COMBAT:
				{
					character->PlayerData->HelmetOptionState = 2;
					break;
				}
			}
		}
	}
	return false;
}
