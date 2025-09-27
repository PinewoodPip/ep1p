#pragma once
#include "Hooks/Hooks.h"
#include "Extender/ScriptExtender.h"

using namespace dse;

BEGIN_NS(epip)

// Must be a separate class to workaround an issue with wrappers and multiple inheritance.
class KeyboardBottomBarListener : public UIEventListener
{
	virtual bool OnFunctionCalled(UIObject* ui, const char* uiCall, int paramsCount, ig::InvokeDataValue* invokeData) override;
};

class KeyboardBottomBar : public GameStateChangedEventListener
{
public:
	void Setup();

	void OnUpdateSlots(StaticSymbols::ecl_UIBottomBar_UpdateSlotsProc* next, UIKeyboardBottomBar* ui, char flags_m);

	virtual void OnGameStateChanged(int newState) override;
private:
	KeyboardBottomBarListener _UIListener;
};

END_NS()
