#pragma once
#include "Hooks/Hooks.h"
#include "Extender/ScriptExtender.h"

using namespace dse;

class KeyboardBottomBar : public GameStateChangedEventListener
{
public:
	void Setup();

	void OnUpdateSlots(StaticSymbols::ecl_UIBottomBar_UpdateSlotsProc* next, UIKeyboardBottomBar* ui, char flags_m);

	virtual void OnGameStateChanged(int newState) override;
};

