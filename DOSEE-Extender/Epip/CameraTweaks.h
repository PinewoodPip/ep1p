#pragma once
#include "Hooks/Hooks.h"

BEGIN_NS(epip)

class CameraTweaks : GameStateChangedEventListener
{
public:
	void Setup();

	// Inherited via GameStateChangedEventListener
	void OnGameStateChanged(int newState) override;
};

END_NS()

