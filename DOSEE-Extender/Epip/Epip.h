#pragma once
#include "UI/TargetInfo.h"

//using namespace dse;

class Epip
{
public:
	void Startup();
private:
	TargetInfo _TargetInfo;
};

extern std::unique_ptr<Epip> gEpip;
