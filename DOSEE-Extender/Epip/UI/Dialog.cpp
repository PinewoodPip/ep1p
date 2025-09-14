#include "pch.h"
#include <format>
#include "Utils/Text.h"
#include "Dialog.h"
#include "Extender/ScriptExtender.h"
#include "Hooks/Hooks.h"
#include "Extender/Utils/CharacterUtils.h"
#include "Extender/Utils/Pointer.h"
#include "Extender/Utils/UIUtils.h"
#include "GameDefinitions/UI.h"
#include "Epip/EpipSettings.h"

using namespace dse;
using namespace epip;

void Dialog::Setup()
{
	gExtender->GetHooks().RegisterUIListener((int)UIObject::TypeID::Dialog, this);
}

bool Dialog::OnInvoke4(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2, ig::InvokeDataValue* invokeData3, ig::InvokeDataValue* invokeData4)
{
	// Apply settings to the swf
	// It doesn't really matter from which invoke we do this
	TryRegisterInvokes((UIDialog*)ui);
	return false;
}

void Dialog::TryRegisterInvokes(UIDialog* ui)
{
	if (ui->FlashPlayer->Invokes.size() <= (uint64_t)UIDialog::Invokes::pipSetAlwaysAutoScroll)
	{
		ui->FlashPlayer->AddInvokeName((uint64_t)UIDialog::Invokes::pipSetAlwaysAutoScroll, _strdup("pipSetAlwaysAutoScroll"));
		ui->FlashPlayer->AddInvokeName((uint64_t)UIDialog::Invokes::pipSetAutoStopListening, _strdup("pipSetAutoStopListening"));
	}

	// Apply autoscroll setting
	ig::InvokeDataValue autoScroll = UIUtils::CreateBoolInvokeData(gSettings->AutoScrollListenedDialogues);
	ui->FlashPlayer->Invoke1((uint64_t)UIDialog::Invokes::pipSetAlwaysAutoScroll, &autoScroll);

	// Apply autolisten setting
	ig::InvokeDataValue autoStopListening = UIUtils::CreateBoolInvokeData(gSettings->AutoStopListening);
	ui->FlashPlayer->Invoke1((uint64_t)UIDialog::Invokes::pipSetAutoStopListening, &autoStopListening);
}
