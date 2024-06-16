#include "pch.h"
#include "Epip.h"
#include "Extender/ScriptExtender.h"

using namespace dse;

void Epip::Startup()
{
	this->_TargetInfo.Startup();
	this->_WorldTooltips.Setup();
	this->_InfiniteCarryWeight.Setup();
	this->_ScriptBugWatchdog.Setup();
	this->_OsirisImprovements.Setup();
}

std::unique_ptr<Epip> gEpip;
