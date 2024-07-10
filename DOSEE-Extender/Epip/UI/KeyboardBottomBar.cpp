#include "pch.h"
#include "Epip/EpipSettings.h"
#include "Extender/Utils/UIUtils.h"
#include "KeyboardBottomBar.h"
#include "Extender/ScriptExtender.h"

using namespace dse;

void KeyboardBottomBar::Setup()
{
	gExtender->GetHooks().RegisterGameStateChangedListener(this);

	if (gSettings->ExtendedHotbar)
	{
		bool applied = gExtender->GetLibraryManager().ApplyCodePatch("ecl::UIBottomBar::FillIconBuffer patch"); // SlotData iterator patch for icons
		applied = applied && gExtender->GetLibraryManager().ApplyCodePatch("ecl::UIKeyboardBottomBar::ctor patch"); // Extend draw struct to 20 icons

		// SlotData iterator patches
		applied = applied && gExtender->GetLibraryManager().ApplyCodePatch("ecl::UIBottomBar::SetSlot patch");
		applied = applied && gExtender->GetLibraryManager().ApplyCodePatch("ecl::UIBottomBar::UpdateSlots patch");
		applied = applied && gExtender->GetLibraryManager().ApplyCodePatch("ecl::UIBottomBar::UpdateSlots2 patch");
		applied = applied && gExtender->GetLibraryManager().ApplyCodePatch("ecl::UIBottomBar::UpdateSlotCooldowns patch");

		if (!applied)
		{
			// TODO undo previous ones if any fail
			ERROR("Failed to patch hotbar functions");
		}

		gExtender->GetEngineHooks().ecl_UIBottomBar_UpdateSlots.SetWrapper(&KeyboardBottomBar::OnUpdateSlots, this);
	}
}

void KeyboardBottomBar::OnUpdateSlots(StaticSymbols::ecl_UIBottomBar_UpdateSlotsProc* next, UIKeyboardBottomBar* ui, char flags_m)
{
	// Disable iterator patches when on the last row,
	// as otherwise the game would crash accessing beyond the 50th slot.
	if (ui->CurrentRow == 4)
	{
		gExtender->GetLibraryManager().UndoCodePatch("ecl::UIBottomBar::SetSlot patch");
		gExtender->GetLibraryManager().UndoCodePatch("ecl::UIBottomBar::UpdateSlots patch");
		gExtender->GetLibraryManager().UndoCodePatch("ecl::UIBottomBar::UpdateSlots2 patch");
		gExtender->GetLibraryManager().UndoCodePatch("ecl::UIBottomBar::UpdateSlotCooldowns patch");
	}
	else
	{
		gExtender->GetLibraryManager().ApplyCodePatch("ecl::UIBottomBar::SetSlot patch");
		gExtender->GetLibraryManager().ApplyCodePatch("ecl::UIBottomBar::UpdateSlots patch");
		gExtender->GetLibraryManager().ApplyCodePatch("ecl::UIBottomBar::UpdateSlots2 patch");
		gExtender->GetLibraryManager().ApplyCodePatch("ecl::UIBottomBar::UpdateSlotCooldowns patch");

	}
	next(ui, flags_m);
}

void KeyboardBottomBar::OnGameStateChanged(int newState)
{
	// Register invokes and set extended mode
	if (newState == ecl::EoCClient::GameState::PrepareRunning)
	{
		auto ui = UIUtils::GetUIByType(UIObject::TypeID::SkillBar);

		// Won't exist in main menu.
		if (ui)
		{
			// Should only run once per UI, as bottomBar is recreated per-session.
			ui->FlashPlayer->AddInvokeName((int)UIKeyboardBottomBar::Invokes::pipSetExtendedMode, "pipSetExtendedMode");

			auto param = UIUtils::CreateBoolInvokeData(gSettings->ExtendedHotbar);
			ui->FlashPlayer->Invoke1((int)UIKeyboardBottomBar::Invokes::pipSetExtendedMode, &param);
		}
	}
}
