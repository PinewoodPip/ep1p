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
};

END_SE()
