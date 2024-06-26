#pragma once
#include "Hooks/Hooks.h"

using namespace dse;

class TargetInfo : public UIEventListener
{
public:
	void Startup();

	void UpdateResistances(UITargetInfo* ui, ig::InvokeDataValue* labelInvokeData);

	void UpdateHPBarText(UITargetInfo* ui);

	// Inherited via UIEventListener
	bool OnInvoke0(UIObject* ui, int64_t invokeEnum) override;
	bool OnInvoke2(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* a1, ig::InvokeDataValue* a2) override;
	void TryRegisterInvokes(UITargetInfo* ui);
	bool OnInvoke3(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* a1, ig::InvokeDataValue* a2, ig::InvokeDataValue* a3) override;
};
