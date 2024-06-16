#pragma once
#include "Hooks/Hooks.h"

BEGIN_NS(epip)

class OsirisImprovements : GameStateChangedEventListener
{
public:
	void Setup();

	void OnGameStateChanged(int newState) override;
};

END_NS()
