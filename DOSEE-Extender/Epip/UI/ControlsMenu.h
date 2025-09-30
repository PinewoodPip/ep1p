#pragma once
#include "Hooks/Hooks.h"
#include "Epip/EpipSettings.h"

using namespace dse;

BEGIN_NS(epip)

struct EpipKeybind
{
	std::wstring Name;
	EpipSettings::Settings SettingsID;
    EpipSettings::Settings ModifierSettingsID;
};

class ControlsMenu : public UIEventListener
{
public:
	// Maps keybind IDs within the UI to their corresponding Epip setting.
	static const int STARTING_ENTRYID = 999;
	static const inline std::map<int, EpipKeybind> ENTRYID_TO_EPIP_SETTING {
		{STARTING_ENTRYID, EpipKeybind {.Name = L"Ep1p: Examine Character/Item", .SettingsID = EpipSettings::Settings::ExamineKeybind, .ModifierSettingsID = EpipSettings::Settings::ExamineKeybindModifier}},
		{STARTING_ENTRYID + 1, {.Name = L"Ep1p: Chain/Unchain Party", .SettingsID = EpipSettings::Settings::TogglePartyChainKeybind, .ModifierSettingsID = EpipSettings::Settings::TogglePartyChainKeybindModifier}},
		{STARTING_ENTRYID + 2, {.Name = L"Ep1p: Sneak/Unsneak Party", .SettingsID = EpipSettings::Settings::TogglePartySneakKeybind, .ModifierSettingsID = EpipSettings::Settings::TogglePartySneakKeybindModifier}},
	};
    std::map<EpipSettings::Settings, int> EPIP_SETTING_TO_ENTRY_ID;

    // The 1 time in the whole project that an LLM was of any use
    static const inline std::unordered_map<std::wstring, int> STR_TO_RAWINPUT {
        {L"None", -1},
        {L"Return", 0},
        {L"Escape", 1},
        {L"Backspace", 2},
        {L"Tab", 3},
        {L"CapsLock", 4},
        {L"Space", 5},
        {L"PrintScreen", 6},
        {L"ScrollLock", 7},
        {L"Pause", 8},
        {L"Insert", 9},
        {L"Home", 10},
        {L"PageUp", 11},
        {L"Delete", 12},
        {L"End", 13},
        {L"PageDown", 14},
        {L"Comma", 15},
        {L"Minus", 16},
        {L"Dot", 17},
        {L"Slash", 18},
        {L"Semicolon", 19},
        {L"Equals", 20},
        {L"LeftSquareBracket", 21},
        {L"Backslash", 22},
        {L"RightSquareBracket", 23},
        {L"Backtick", 24},
        {L"Apostrophe", 25},
        {L"Num0", 26},
        {L"Num1", 27},
        {L"Num2", 28},
        {L"Num3", 29},
        {L"Num4", 30},
        {L"Num5", 31},
        {L"Num6", 32},
        {L"Num7", 33},
        {L"Num8", 34},
        {L"Num9", 35},
        {L"A", 36},
        {L"B", 37},
        {L"C", 38},
        {L"D", 39},
        {L"E", 40},
        {L"F", 41},
        {L"G", 42},
        {L"H", 43},
        {L"I", 44},
        {L"J", 45},
        {L"K", 46},
        {L"L", 47},
        {L"M", 48},
        {L"N", 49},
        {L"O", 50},
        {L"P", 51},
        {L"Q", 52},
        {L"R", 53},
        {L"S", 54},
        {L"T", 55},
        {L"U", 56},
        {L"V", 57},
        {L"W", 58},
        {L"X", 59},
        {L"Y", 60},
        {L"Z", 61},
        {L"F1", 62},
        {L"F2", 63},
        {L"F3", 64},
        {L"F4", 65},
        {L"F5", 66},
        {L"F6", 67},
        {L"F7", 68},
        {L"F8", 69},
        {L"F9", 70},
        {L"F10", 71},
        {L"F11", 72},
        {L"F12", 73},
        {L"F13", 74},
        {L"F14", 75},
        {L"F15", 76},
        {L"F16", 77},
        {L"F17", 78},
        {L"F18", 79},
        {L"F19", 80},
        {L"F20", 81},
        {L"F21", 82},
        {L"F22", 83},
        {L"F23", 84},
        {L"F24", 85},
        {L"Right", 86},
        {L"Left", 87},
        {L"Down", 88},
        {L"Up", 89},
        {L"NumLock", 90},
        {L"KP_Divide", 91},
        {L"KP_Multiply", 92},
        {L"KP_Minus", 93},
        {L"KP_Plus", 94},
        {L"KP_Enter", 95},
        {L"KP1", 96},
        {L"KP2", 97},
        {L"KP3", 98},
        {L"KP4", 99},
        {L"KP5", 100},
        {L"KP6", 101},
        {L"KP7", 102},
        {L"KP8", 103},
        {L"KP9", 104},
        {L"KP0", 105},
        {L"KP_Period", 106},
        {L"LCtrl", 107},
        {L"LShift", 108},
        {L"LAlt", 109},
        {L"LGUI", 110},
        {L"RCtrl", 111},
        {L"RShift", 112},
        {L"RAlt", 113},
        {L"RGUI", 114},
        {L"Mode", 115},
        {L"Left_2", 116},
        {L"Middle", 117},
        {L"Right_2", 118},
        {L"X1", 119},
        {L"X2", 120},
        {L"Motion", 121},
        {L"Motion_XNeg", 122},
        {L"Motion_YPos", 123},
        {L"Motion_XPos", 124},
        {L"Motion_YNeg", 125},
        {L"Wheel_XPos", 126},
        {L"Wheel_XNeg", 127},
        {L"Wheel_YPos", 128},
        {L"Wheel_YNeg", 129},
        {L"LeftStick_XNeg", 130},
        {L"LeftStick_YPos", 131},
        {L"LeftStick_XPos", 132},
        {L"LeftStick_YNeg", 133},
        {L"RightStick_XNeg", 134},
        {L"RightStick_YPos", 135},
        {L"RightStick_XPos", 136},
        {L"RightStick_YNeg", 137},
        {L"LeftTrigger", 138},
        {L"RightTrigger", 139},
        {L"A_2", 140},
        {L"B_2", 141},
        {L"X_2", 142},
        {L"Y_2", 143},
        {L"Back", 144},
        {L"Guide", 145},
        {L"Start", 146},
        {L"LeftStick", 147},
        {L"RightStick", 148},
        {L"LeftShoulder", 149},
        {L"RightShoulder", 150},
        {L"DPad_Up", 151},
        {L"DPad_Down", 152},
        {L"DPad_Left", 153},
        {L"DPad_Right", 154},
        {L"Touch_Tap", 155},
        {L"Touch_Hold", 156},
        {L"Touch_Pinch_In", 157},
        {L"Touch_Pinch_Out", 158},
        {L"Touch_Rotate", 159},
        {L"Touch_Flick", 160}
    };
    std::unordered_map<int, std::wstring> RAWINPUT_TO_STR;

	void Setup();
	void RenderEntries(UIObject* ui);

    STDWString GetKeybindLabel(RawInputType modifier, RawInputType baseKey);
    void GetKeybind(EpipSettings::Settings baseKeySetting, EpipSettings::Settings modifierKeySetting, int& baseKey, int& modifierKey);
    void SetKeybindLabel(UIObject* ui, int entryID, EpipKeybind keybind);

	bool OnInvoke0(UIObject* ui, int64_t invokeEnum) override;
    bool OnInvoke1(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* a1) override;
	bool OnFunctionCalled(UIObject* ui, const char* uiCall, int paramsCount, ig::InvokeDataValue* invokeData) override;

private:
	std::optional<EpipSettings::Settings> _CurrentKeybind;
	RawInputType _CurrentModifier;
	RawInputType _CurrentInput;
};

END_NS()