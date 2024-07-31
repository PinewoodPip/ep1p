#include "pch.h"
#include "Hotkeys.h"
#include "EpipSettings.h"
#include "Extender/Utils/Pointer.h"
#include "Extender/Utils/UIUtils.h"
#include "Extender/ScriptExtender.h"

using namespace dse;
using namespace epip;

void Hotkeys::Setup()
{
	gExtender->GetHooks().RegisterInputListener(this);
}

void Hotkeys::OnRawInput(InputManager* self, InputRawChange* change, bool unknown)
{
	if (!unknown)
	{
		//LOG(std::format("RawInputType {} Value1 {} Value2 {} State {}", (int)change->RawInputID, change->Value1, change->Value2, (uint8_t)change->State).c_str());

		if (change->RawInputID == (RawInputType)gSettings->ExamineKeybind && !UIUtils::IsPausedOrInputFocused() && change->State == InputValue::Pressed)
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
	}
}
