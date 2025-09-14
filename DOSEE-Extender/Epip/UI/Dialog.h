#pragma once
#include "Hooks/Hooks.h"

using namespace dse;

class Dialog : public UIEventListener
{
public:
	void Setup();
	void TryRegisterInvokes(UIDialog* ui);

	// Inherited via UIEventListener
	bool OnInvoke4(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* a1, ig::InvokeDataValue* a2, ig::InvokeDataValue* a3, ig::InvokeDataValue* a4) override;
};
