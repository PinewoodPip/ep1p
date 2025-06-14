#pragma once
#include "Utils.h"
#include <sstream>
#include <fstream>
#include "json/json.h"
#include "GameDefinitions/Input.h"

BEGIN_NS(epip)

#define EPIP_FOR_ALL_BOOL_SETTINGS() \
	EPIP_FOR_SETTING(ExtendedHotbar) \
	EPIP_FOR_SETTING(ExtraTargetInfo) \
	EPIP_FOR_SETTING(MoreWorldTooltips) \
	EPIP_FOR_SETTING(ForceStoryPatching) \
	EPIP_FOR_SETTING(SharedLuckyCharmLooting) \
	EPIP_FOR_SETTING(DeadPartyMemberXP) \
	EPIP_FOR_SETTING(InfiniteEquipmentDurability) \
	EPIP_FOR_SETTING(InfiniteCarryWeight) \
	EPIP_FOR_SETTING(StoryLogging) \
	EPIP_FOR_SETTING(FixDontCareScriptParam) \
	EPIP_FOR_SETTING(FixSkillRangeGFX) \
	EPIP_FOR_SETTING(LockBottomBar) \
	EPIP_FOR_SETTING(UnlockDialogCamera) \
	EPIP_FOR_SETTING(CreateConsole)
	
#define EPIP_FOR_ALL_ENUM_SETTINGS() \
	EPIP_FOR_SETTING(ExamineInformation) \
	EPIP_FOR_SETTING(AutoIdentifyMode)

#define EPIP_FOR_ALL_FLOAT_SETTINGS() \
	EPIP_FOR_SETTING(CameraMaxDistance)

#define EPIP_FOR_ALL_UINT_SETTINGS() \
	EPIP_FOR_SETTING(ExamineKeybind) \
	EPIP_FOR_SETTING(TogglePartyChainKeybind) \
	EPIP_FOR_SETTING(TogglePartySneakKeybind) \
	EPIP_FOR_SETTING(TogglePartyChainKeybindModifier) \
	EPIP_FOR_SETTING(TogglePartySneakKeybindModifier)

struct EpipSettings
{
public:
	enum class Settings : int
	{
		ExtendedHotbar = -1337, // Start at a negative index to avoid collisions with game setting IDs.
		ExtraTargetInfo,
		ExamineInformation,
		MoreWorldTooltips,
		ForceStoryPatching,
		SharedLuckyCharmLooting,
		DeadPartyMemberXP,
		AutoIdentifyMode,
		InfiniteEquipmentDurability,
		InfiniteCarryWeight,
		StoryLogging,
		FixDontCareScriptParam,
		FixSkillRangeGFX,
		CameraMaxDistance,
		LockBottomBar,
		CreateConsole,
		ExamineKeybind,
		UnlockDialogCamera,
		TogglePartyChainKeybind,
		TogglePartySneakKeybind,
		TogglePartyChainKeybindModifier,
		TogglePartySneakKeybindModifier,
	};
	enum class ExamineInformationChoices
	{
		Vanilla,
		SharedLoremaster,
		FullInformation,
	};
	enum class AutoIdentifyModeChoices
	{
		Disabled,
		WithRequirements,
		Always,
	};

	bool ExtendedHotbar = false;
	bool ExtraTargetInfo = true;
	ExamineInformationChoices ExamineInformation = ExamineInformationChoices::Vanilla;
	bool MoreWorldTooltips = false;
	bool ForceStoryPatching = false;
	bool SharedLuckyCharmLooting = true;
	bool DeadPartyMemberXP = false;
	AutoIdentifyModeChoices AutoIdentifyMode = AutoIdentifyModeChoices::Disabled;
	bool InfiniteEquipmentDurability = false;
	bool InfiniteCarryWeight = false;
	bool StoryLogging = false;
	bool FixDontCareScriptParam = true;
	bool FixSkillRangeGFX = true;
	float CameraMaxDistance = 19.0f; // Game default
	bool LockBottomBar = false;
	bool UnlockDialogCamera = false;
	bool CreateConsole = false;
	uint32_t ExamineKeybind = (uint32_t)RawInputType::T;
	uint32_t TogglePartyChainKeybind = (uint32_t)RawInputType::None;
	uint32_t TogglePartySneakKeybind = (uint32_t)RawInputType::None;
	uint32_t TogglePartyChainKeybindModifier = (uint32_t)RawInputType::None;
	uint32_t TogglePartySneakKeybindModifier = (uint32_t)RawInputType::None;

	void SetByID(int id, bool value)
	{
#define EPIP_FOR_SETTING(setting) if (id == (int)Settings::setting) setting = value;
		EPIP_FOR_ALL_BOOL_SETTINGS();
#undef EPIP_FOR_SETTING
	}

	void SetByID(int id, int value)
	{
#define EPIP_FOR_SETTING(setting) if (id == (int)Settings::setting) setting = (setting##Choices) value;
		EPIP_FOR_ALL_ENUM_SETTINGS();
#undef EPIP_FOR_SETTING
	}

	void SetByID(int id, float value)
	{
#define EPIP_FOR_SETTING(setting) if (id == (int)Settings::setting) setting = value;
		EPIP_FOR_ALL_FLOAT_SETTINGS();
#undef EPIP_FOR_SETTING
	}

	void SetByID(int id, uint32_t value)
	{
#define EPIP_FOR_SETTING(setting) if (id == (int)Settings::setting) setting = value;
		EPIP_FOR_ALL_UINT_SETTINGS();
#undef EPIP_FOR_SETTING
	}

	static std::wstring GetConfigPath()
	{
		std::wstring exeDir;
		HMODULE exeHandle = GetModuleHandleW(NULL);
		if (exeHandle != NULL) {
			exeDir.resize(MAX_PATH);
			DWORD exeSize = GetModuleFileNameW(exeHandle, exeDir.data(), (DWORD)exeDir.size());
			exeDir.resize(exeSize);
			auto sep = exeDir.find_last_of(L'\\');
			if (sep != std::string::npos) {
				exeDir = exeDir.substr(0, sep + 1);
			}
		}

		return exeDir + L"Ep1pSettings.json";
	}

	void ConfigGet(Json::Value& node, char const* key, bool& value)
	{
		auto configVar = node[key];
		if (!configVar.isNull() && configVar.isBool()) {
			value = configVar.asBool();
		}
	}

	void ConfigGet(Json::Value& node, char const* key, uint32_t& value)
	{
		auto configVar = node[key];
		if (!configVar.isNull() && configVar.isUInt()) {
			value = configVar.asUInt();
		}
	}

	void ConfigGet(Json::Value& node, char const* key, float& value)
	{
		auto configVar = node[key];
		if (!configVar.isNull() && configVar.isDouble()) {
			value = configVar.asDouble();
		}
	}

	void ConfigGet(Json::Value& node, char const* key, std::wstring& value)
	{
		auto configVar = node[key];
		if (!configVar.isNull() && configVar.isString()) {
			value = StringFromUTF8(configVar.asString());
		}
	}

	Json::Value ToJson()
	{
		Json::Value root;
#define EPIP_FOR_SETTING(setting) root[#setting] = setting;
		EPIP_FOR_ALL_BOOL_SETTINGS();
		EPIP_FOR_ALL_FLOAT_SETTINGS();
		EPIP_FOR_ALL_UINT_SETTINGS();
#define EPIP_FOR_SETTING(setting) root[#setting] = (int)setting;
		EPIP_FOR_ALL_ENUM_SETTINGS();
#undef EPIP_FOR_SETTING
		return root;
	}

	void Save()
	{
		Json::Value json = ToJson();
		std::ofstream f(GetConfigPath(), std::ios::out);
		if (!f.good()) {
			ERR("Cannot save settings file");
			return;
		}

		Json::CharReaderBuilder factory;
		Json::Value root;
		std::string errs;
		f << json << std::endl;
		f.close();
	}
};

END_NS()

extern std::unique_ptr<dse::epip::EpipSettings> gSettings;
