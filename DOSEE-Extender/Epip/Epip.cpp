#include "pch.h"
#include "Epip.h"
#include "Extender/ScriptExtender.h"

using namespace dse;

void Epip::Startup()
{
#if defined(OSI_EOCAPP)
	gSettings = std::make_unique<EpipSettings>();
	LoadConfig(EpipSettings::GetConfigPath(), *gSettings);

	this->_GameOptionsSettings.Setup();
	this->_TargetInfo.Startup();
	this->_WorldTooltips.Setup();
	this->_InfiniteCarryWeight.Setup();
	this->_SkillRangeEffectsFix.Setup();
	this->_OsirisImprovements.Setup();
	this->_EquipmentDegradation.Setup();
	this->_SharedCivils.Setup();
	this->_AutoIdentify.Setup();
	this->_DeadPartyXP.Setup();
	this->_ExamineTweaks.Setup();
#endif
	this->_ScriptBugWatchdog.Setup();
}

void Epip::LoadConfig(std::wstring const& configPath, EpipSettings& config)
{
	std::ifstream f(configPath, std::ios::in);
	if (!f.good()) {
		return;
	}

	Json::CharReaderBuilder factory;
	Json::Value root;
	std::string errs;
	if (!Json::parseFromStream(factory, f, &root, &errs))
	{
		LOG("Failed to read config");
	}

#define EPIP_FOR_SETTING(setting) config.ConfigGet(root, #setting, config.setting);
	EPIP_FOR_ALL_BOOL_SETTINGS();
#define EPIP_FOR_SETTING(setting) uint32_t setting##Temp; \
	config.ConfigGet(root, #setting, setting##Temp); \
	config.setting = (EpipSettings::setting##Choices)setting##Temp;
	EPIP_FOR_ALL_ENUM_SETTINGS();
#undef EPIP_FOR_SETTING
}

std::unique_ptr<Epip> gEpip;
