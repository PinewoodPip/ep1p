#pragma once
#include "Hooks/Hooks.h"

BEGIN_NS(epip)

class WorldTooltips
{
public:
	void Setup();

	void OnUpdateItems(void* netProtocol);
};

END_NS()
