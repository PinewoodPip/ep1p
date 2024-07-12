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

		if (change->RawInputID == (RawInputType)gSettings->ExamineKeybind && !UIUtils::IsPausedOrInputFocused())
		{
			ecl::Character* character = PointerUtils::GetCurrentPickerCharacter();
			if (character)
			{
				GetStaticSymbols().ecl_EocUIControl_OpenExamineUI(*GetStaticSymbols().ecl_EocUIControl, 1, &gExtender->GetHooks().LastPickerCharacterHandle);
			}
		}
	}
}
