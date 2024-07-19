#pragma once
#include "Hooks/Hooks.h"

BEGIN_NS(epip)

class MainMenu : UIEventListener
{
public:
	void Setup();

	virtual bool OnInvoke1(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1) override;
	virtual bool OnFunctionCalled(const char* uiCall, int paramsCount, ig::InvokeDataValue* invokeData) override;
};

END_NS()

