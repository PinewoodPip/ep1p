#include "pch.h"
#include "Epip.h"

using namespace dse;

void Epip::Startup()
{
	this->_TargetInfo.Startup();
}

std::unique_ptr<Epip> gEpip;
