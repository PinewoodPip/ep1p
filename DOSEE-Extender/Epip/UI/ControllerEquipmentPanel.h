#pragma once
#include "ControllerEquipmentPanel.h"
#include "Hooks/Hooks.h"

using namespace dse;

BEGIN_NS(epip)

class ControllerEquipmentPanel : public UIEventListener
{
public:
	enum CONTEXT_MENU_ACTION_IDS
	{
		HIDE_HELMET = 999, // Higher than any vanilla action ID
		SHOW_HELMET_IN_COMBAT,
		ALWAYS_SHOW_HELMET,
	};
	void Setup();

	virtual void AfterInvoke0(UIObject* ui, int64_t invokeEnum) override;
	bool OnFunctionCalled(UIObject* ui, const char* uiCall, int paramsCount, ig::InvokeDataValue* invokeData) override;

private:
	bool _NextItemIsHelmet = false;
};

END_NS()