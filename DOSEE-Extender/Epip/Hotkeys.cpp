#include "pch.h"
#include "Hotkeys.h"
#include "EpipSettings.h"
#include <Extender/Utils/CharacterUtils.h>
#include "Extender/Utils/Pointer.h"
#include "Extender/Utils/UIUtils.h"
#include "Extender/ScriptExtender.h"

using namespace dse;
using namespace epip;

void Hotkeys::Setup()
{
	gExtender->GetHooks().RegisterInputListener(this);
}

void Hotkeys::TogglePartyChain()
{
	ecl::PartyManager* partyManager = *GetStaticSymbols().ecl_PartyManager;
	auto party = partyManager->Components[0]; // Assuming there never is a second party, which I really think is always the case for DOS1. It's very likely this party system was backported from OR intended for DOS2, during DOSEE development
	Set<ecl::Character*>* partyMembers = &party->CharacterSet;
	Set<ecl::PartyGroup*>* partyGroups = &party->PartyGroupSet;
	ecl::Character* activeChar = ClientCharacterUtils::GetPlayerCharacter();
	int reservedPlayerID = activeChar->ReservedPlayerID_m;

	bool shouldUnchain = partyGroups->size() == 1;
	if (shouldUnchain)
	{
		for (auto character : *partyMembers)
		{
			if (character->ReservedPlayerID_m == reservedPlayerID)
			{
				GetStaticSymbols().ecl_Party_RequestDetach(party, character->Handle_m, 0); // TODO what should the ID be?
			}
		}
	}
	else
	{
		auto targetGroup = partyGroups->data()[0];
		auto targetGroupID = 0;

		// Toggle chaining in reverse order to avoid shuffling characters around.
		// TODO this will order characters by their order in the array - should preserve the player's order instead
		for (int i = partyMembers->size() - 1; i >= 0; --i)
		{
			auto character = partyMembers->data()[i];
			bool isInGroup = false;
			bool isControlled = character->ReservedPlayerID_m == reservedPlayerID;
			for (auto handle : targetGroup->SomeHolder->CharacterHandles_m)
			{
				if (handle == character->Handle_m)
				{
					isInGroup = true;
				}
			}
			if (isControlled && !isInGroup)
			{
				GetStaticSymbols().ecl_Party_AddToGroup(party, character->Handle_m, 0, targetGroup->SomeHolder->CharacterHandles_m.size());
			}
		}
	}
}

void Hotkeys::TogglePartySneak()
{
	ecl::PartyManager* partyManager = *GetStaticSymbols().ecl_PartyManager;
	auto party = partyManager->Components[0]; // See relevant comment in TogglePartyChain()
	auto partyMembers = party->CharacterSet;
	auto partyGroups = party->PartyGroupSet;
	ecl::Character* activeChar = ClientCharacterUtils::GetPlayerCharacter();
	bool shouldUnsneak = ClientCharacterUtils::HasStatusType(activeChar, ecl::Status::StatusType::Sneaking);
	int reservedPlayerID = activeChar->ReservedPlayerID_m;

	// Toggle sneaking of client-controlled characters to match the active char's new desired sneaking state.
	for (auto character : partyMembers)
	{
		bool isSneaking = ClientCharacterUtils::HasStatusType(character, ecl::Status::StatusType::Sneaking);
		bool isControlled = character->ReservedPlayerID_m == reservedPlayerID;
		if (isControlled && ((isSneaking && shouldUnsneak) || (!isSneaking && !shouldUnsneak)))
		{
			auto inputController = character->InputController;
			auto task = inputController->GetTaskByType(ecl::CharacterTask::Sneak);
			task->Execute2();
		}
	}
}

void Hotkeys::OnRawInput(InputManager* self, InputRawChange* change, bool unknown)
{
	#define IsKeybindPressed(setting) change->RawInputID == gSettings->setting &&  (gSettings->setting##Modifier == RawInputType::None || ActiveKeyModifier == gSettings->setting##Modifier)

	// Update tracked key modifiers
	if (!unknown)
	{
		RawInputType input = change->RawInputID;
		// GUI key intentionally unsupported
		if (input == RawInputType::LShift || input == RawInputType::RShift || input == RawInputType::LCtrl || input == RawInputType::RCtrl || input == RawInputType::LAlt || input == RawInputType::RAlt)
		{
			if (change->State == InputValue::Pressed)
			{
				ActiveKeyModifier = input;
			}
			else
			{
				ActiveKeyModifier = RawInputType::None;
			}
		}
	}
	if (!unknown && !UIUtils::IsPausedOrInputFocused() && change->State == InputValue::Pressed)
	{
		//LOG(std::format("RawInputType {} Value1 {} Value2 {} State {}", (int)change->RawInputID, change->Value1, change->Value2, (uint8_t)change->State).c_str());

		if (IsKeybindPressed(ExamineKeybind))
		{
			ecl::Character* character = PointerUtils::GetCurrentPickerCharacter();
			ObjectHandle characterHandle = gExtender->GetHooks().LastPickerCharacterHandle;
			UIObject* examineUI = UIUtils::GetUIByType(UIObject::TypeID::Examine);
			ObjectHandle previousObject = {};
			if (examineUI)
			{
				previousObject = ((ecl::UIExamine*)examineUI)->CurrentObjectHandle;
			}

			// Open the UI if there is a character and the UI either is closed or is showing a different entity
			if (character && (!examineUI || !UIUtils::IsVisible(examineUI) || (previousObject != characterHandle)))
			{
				GetStaticSymbols().ecl_EocUIControl_OpenExamineUI(*GetStaticSymbols().ecl_EocUIControl, 1, &characterHandle);
			}
			else if (UIUtils::IsVisible(examineUI)) // Otherwise close it if it was open (ex. pressing hotkey again over the same entity, or when there is no entity picked)
			{
				examineUI->Hide();
			}
		}
		else if (IsKeybindPressed(TogglePartyChainKeybind))
		{
			TogglePartyChain();
		}
		else if (IsKeybindPressed(TogglePartySneakKeybind))
		{
			TogglePartySneak();
		}
	}
	#undef IsKeybindPressed
}
