#pragma once
#include "Hooks/Hooks.h"
#include "Extender/ScriptExtender.h"

BEGIN_NS(epip)

class Hotkeys : public InputListener
{
public:
	void Setup();
	void TogglePartyChain();
	void TogglePartySneak();

	virtual void OnRawInput(InputManager* self, InputRawChange* change, bool unknown) override;

private:
	RawInputType ActiveKeyModifier = RawInputType::None;
};

END_NS()

