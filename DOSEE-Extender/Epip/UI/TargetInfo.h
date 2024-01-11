#pragma once
#include "Hooks/Hooks.h"

using namespace dse;

class TargetInfo : public UIEventListener
{
public:
	void Startup();

	// Inherited via UIEventListener
	bool OnInvoke3(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* a1, ig::InvokeDataValue* a2, ig::InvokeDataValue* a3) override;
};
