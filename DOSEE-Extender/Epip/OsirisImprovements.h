#pragma once
#include "Hooks/Hooks.h"

BEGIN_NS(epip)

class OsirisImprovements : GameStateChangedEventListener
{
public:
	void Setup();

	int OnOsirisGetSaveFileVersion(StaticSymbols::GetOsirisSaveFileVersionProc* next, STDString* param1, Path* param2);

	void OnGameStateChanged(int newState) override;
};

END_NS()
