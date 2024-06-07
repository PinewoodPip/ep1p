#pragma once
#include "UI/TargetInfo.h"
#include "WorldTooltips.h"
#include "InfiniteCarryWeight.h"

//using namespace dse;
using namespace epip;

class Epip
{
public:
	void Startup();
private:
	TargetInfo _TargetInfo;
	KeyboardBottomBar _KeyboardBottomBar;
	WorldTooltips _WorldTooltips;
	InfiniteCarryWeight _InfiniteCarryWeight;
};

extern std::unique_ptr<Epip> gEpip;
