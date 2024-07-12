#pragma once
#include "Hooks/Hooks.h"
#include "Extender/ScriptExtender.h"

BEGIN_NS(epip)

class Hotkeys : public InputListener
{
public:
	void Setup();

	virtual void OnRawInput(InputManager* self, InputRawChange* change, bool unknown) override;
};

END_NS()

