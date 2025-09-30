#include "pch.h"
#include "WorldTooltips.h"
#include "Extender/ScriptExtender.h"
#include <GameDefinitions/Item.h>
#include "Epip/EpipSettings.h"
#include "Extender/Utils/UIUtils.h"
#include "Extender/Utils/CharacterUtils.h"

using namespace dse;
using namespace epip;

void WorldTooltips::Setup()
{
	if (gSettings->MoreWorldTooltips)
	{
		auto& lib = gExtender->GetEngineHooks();
		lib.ecl_ItemProtocol_UpdateItems.SetPostHook(&WorldTooltips::OnUpdateItems, this);
	}
	gExtender->GetHooks().RegisterUIListener((int)UIObject::TypeID::WorldTooltip, this);
	gExtender->GetHooks().RegisterInputListener(&_InputListener);
	gExtender->GetHooks().RegisterPickerListener(&_PickerListener);

	_InputListener._WorldTooltips = this;
	_PickerListener._WorldTooltips = this;
}

eoc::IActionData* GetActionData(eoc::ItemTemplate* itemTemplate, eoc::IActionData::ActionType type)
{
	for (auto action : itemTemplate->BaseActionData)
	{
		if (action->Type == type)
		{
			return action;
		}
	}
	return nullptr;
}

void WorldTooltips::OnUpdateItems(void* netProtocol)
{
	auto levelManager = *gStaticSymbols->ecl_LevelManager;
	auto level = levelManager->CurrentLevel;
	if (level)
	{
		auto items = level->ItemManager->ItemSet;
		for (auto item : items)
		{
			auto itemTemplate = (eoc::ItemTemplate*)item->GetCurrentTemplate();
			int previousTooltip = itemTemplate->Tooltip;
			if (previousTooltip != 2)
			{
				bool shouldHaveTooltip = item->Stats != nullptr;

				//shouldHaveTooltip |= (item->LockLevel > 0 && item->LockLevel <= 7);
				//shouldHaveTooltip |= itemTemplate->IsKey; // Might be a wrong field name?

				if (itemTemplate->InventoryType > 0)
				{
					// There are items that have inventory type set but cannot be opened,
					// ex. broken vases.
					shouldHaveTooltip |= GetActionData(itemTemplate, eoc::IActionData::ActionType::OpenClose) != nullptr;
				}

				if (shouldHaveTooltip)
				{
					itemTemplate->Tooltip = 2;
				}
			}
		}
	}
}

bool WorldTooltips::OnInvoke0(UIObject* ui, int64_t invokeEnum)
{
	// tooltipOut UICall is not made when tooltips are hidden from letting go the keybind,
	// thus we must reset bookkeeping manually to avoid getting stuck in the state of having hovered over an item.
	if (invokeEnum == UIWorldTooltip::Invokes::clearAll)
	{
		_OverridePicker = false;
		_ItemHandle = ComponentHandle();
	}
	return false;
}

bool WorldTooltips::OnFunctionCalled(UIObject* ui, const char* uiCall, int paramsCount, ig::InvokeDataValue* invokeData)
{
	if (strcmp(uiCall, "tooltipClicked") == 0)
	{
		// Request the next picker update to execute the use/loot character task, if the item is a container and the setting is enabled
		_RequestLooting = gSettings->LootContainersFromWorldTooltips;
	}
	else if (strcmp(uiCall, "tooltipOver") == 0)
	{
		// Track the hovered item
		float itemHandle = invokeData[0].DoubleVal;
		uint32_t itemHandleInt = *(reinterpret_cast<uint32_t*>(&itemHandle));
		_OverridePicker = true;
		_ItemHandle = (ComponentHandle)itemHandleInt; // DOUBLE CHECK WE set the coprrect field; 
		return true;
	}
	else if (strcmp(uiCall, "tooltipOut") == 0)
	{
		_OverridePicker = false;
		_ItemHandle = ComponentHandle();
	}
	return false;
}

void WorldTooltips::WorldTooltipsInputListener::OnRawInput(InputManager* self, InputRawChange* change, bool unknown)
{
	// If left-clicking a world tooltip, attempt to loot/open the item instead
	UIWorldTooltip* worldTooltipsUI = (UIWorldTooltip*)UIUtils::GetUIByType(UIObject::TypeID::WorldTooltip);
	auto _ItemHandle = _WorldTooltips->_ItemHandle;
	if (_ItemHandle && UIUtils::IsVisible(worldTooltipsUI) && change->RawInputID == RawInputType::Left_2 && gSettings->LootContainersFromWorldTooltips && change->State == Released)
	{
		ecl::Item* item = (*gStaticSymbols->ObjectFactory__ecl_Item)->Get(_ItemHandle);
		if (!item) return;
		eoc::ItemTemplate* itemTemplate = (eoc::ItemTemplate*)item->GetCurrentTemplate();
		if (!itemTemplate || !GetActionData(itemTemplate, eoc::IActionData::ActionType::OpenClose)) return; // itemTemplate should always exist (else the item would have no world tooltip to begin with), but eh let's keep a sanity check

		// These flags must be set for this hacky way of interacting with the item to work.
		// They appear to correspond to CanBeMoved (one of them, at least - no idea about the other) - as the hack works on moveable items only without overriding the flags (possibly because of differences in context menu options?).
		ecl::Item::Flags1 prevFlags = item->Flags;
		item->Flags = (ecl::Item::Flags1)((int)item->Flags | ((int)(ecl::Item::Flags1::Unknown3) | (int)(ecl::Item::Flags1::Unknown4)));

		auto& lib = gExtender->GetEngineHooks();

		// Do a right-click first to open the context menu
		change->RawInputID = Right_2;
		change->State = Pressed;
		change->Value1 = 1;
		lib.ls_InputManager_InjectInput.CallOriginal(self, change, unknown);
		change->RawInputID = Right_2;
		change->State = Released;
		change->Value1 = 0;
		lib.ls_InputManager_InjectInput.CallOriginal(self, change, unknown);

		// Select the "Open" context menu entry
		UIObject* contextMenu = UIUtils::GetUIByType(UIObject::TypeID::ContextMenu);
		ig::InvokeDataValue param1EntryIndex = UIUtils::CreateDoubleInvokeData(1); // Doesn't matter?
		ig::InvokeDataValue param2ActionID = UIUtils::CreateDoubleInvokeData(4); // "Use item" action ID
		ig::InvokeDataValue param3UnknownHandle = UIUtils::CreateDoubleInvokeData(0); // Doesn't matter
		std::vector<ig::InvokeDataValue> params = { param1EntryIndex, param2ActionID, param3UnknownHandle };
		contextMenu->OnFunctionCalled("buttonPressed", 3, params.data());

		// Back to the left-click (won't do anything either way)
		change->RawInputID = Left_2;
		change->State = Released;
		change->Value1 = 0;
		lib.ls_InputManager_InjectInput.CallOriginal(self, change, unknown);

		// Reset bookkeeping
		_WorldTooltips->_ItemHandle = ComponentHandle();
		_WorldTooltips->_OverridePicker = false;
		item->Flags = prevFlags;
	}
}

void WorldTooltips::WorldTooltipsPickerListener::OnPickingDone(ecl::PickingHelper* picker)
{
	UIWorldTooltip* worldTooltipsUI = (UIWorldTooltip*)UIUtils::GetUIByType(UIObject::TypeID::WorldTooltip);
	//if (worldTooltipsUI->HoveredItemHandle)
	auto _ItemHandle = _WorldTooltips->_ItemHandle;
	if (_WorldTooltips->_ItemHandle && UIUtils::IsVisible(worldTooltipsUI) && gSettings->LootContainersFromWorldTooltips) // If you first hover over the item then the tooltip then it fucking works
	{
		// Override picker handles; if not done, then this feature would only work if the cursor was first over a gameobject *right* before hovering onto a world tooltip
		picker->CurrentItemHandle = _ItemHandle;
		picker->CurrentObjectHandle = _ItemHandle;

		if (_WorldTooltips->_RequestLooting)
		{
			_WorldTooltips->_RequestLooting = false;

			ecl::Character* playerCharacter = ClientCharacterUtils::GetPlayerCharacter();
			if (!playerCharacter) return;

			if (playerCharacter->InputController)
			{
				ecl::CharacterTask_Item_Use* task = (ecl::CharacterTask_Item_Use*)playerCharacter->InputController->GetTaskByType(ecl::CharacterTask::Type::UseItem);
				ecl::Item* item = (*gStaticSymbols->ObjectFactory__ecl_Item)->Get((ComponentHandle)_ItemHandle);
				if (task && item)
				{
					// Queue "Use item" task
					task->ItemHandle = (ComponentHandle)_ItemHandle;
					task->Something = 0xe;
					playerCharacter->InputController->ForceExecuteNextTask(task, 1, 0); // First bool skips preview phase

					_ItemHandle = ComponentHandle();
				}
			}
		}
	}
}
