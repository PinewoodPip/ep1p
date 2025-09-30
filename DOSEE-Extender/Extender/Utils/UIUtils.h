#pragma once
#include "GameDefinitions/UI.h"

BEGIN_SE()

class UIUtils
{
public:
	static UIObject* GetUIByType(UIObject::TypeID typeID);
	static ig::InvokeDataValue CreateDoubleInvokeData(int value);
	static ig::InvokeDataValue CreateBoolInvokeData(bool value);
	static ig::InvokeDataValue CreateStringInvokeData(STDWString value);
	static bool IsPausedOrInputFocused();
	static bool IsVisible(UIObject* ui);
	static bool IsModifierKey(RawInputType inputType); // Returns whether an input is considered a modifier and not valid as a standalone keybind.
};

END_SE()
