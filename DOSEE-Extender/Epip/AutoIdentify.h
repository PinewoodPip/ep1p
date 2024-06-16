#pragma once
#include "Hooks/Hooks.h"

BEGIN_NS(epip)

class AutoIdentify
{
public:
	void Setup();

private:
	esv::Item* OnTreasureItemGenerated(StaticSymbols::esv_ItemHelpers_GenerateTreasureItemProc* next, void* request, int16_t unknown);
};

END_NS()
