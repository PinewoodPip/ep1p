#pragma once
#include "Hooks/Hooks.h"

BEGIN_NS(epip)

class WorldTooltips : GameStateChangedEventListener
{
public:
	void Setup();

	void OnGameStateChanged(int newState) override;
};

END_NS()

