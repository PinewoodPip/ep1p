#include "pch.h"
#include "Epip.h"
#include "Extender/ScriptExtender.h"

using namespace dse;

void Epip::Startup()
{
#if defined(OSI_EOCAPP)
	this->_TargetInfo.Startup();
	this->_WorldTooltips.Setup();
	this->_InfiniteCarryWeight.Setup();
	this->_SkillRangeEffectsFix.Setup();
	this->_OsirisImprovements.Setup();
	this->_EquipmentDegradation.Setup();
	this->_SharedCivils.Setup();
	this->_AutoIdentify.Setup();
	this->_DeadPartyXP.Setup();
#endif
	this->_ScriptBugWatchdog.Setup();
}

std::unique_ptr<Epip> gEpip;
