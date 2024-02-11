#pragma once
#include "UI/TargetInfo.h"
#include "WorldTooltips.h"

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
};

extern std::unique_ptr<Epip> gEpip;
