#pragma once
#include "Hooks/Hooks.h"

BEGIN_NS(epip)

class WorldTooltips : public UIEventListener
{
public:
	// Inner classes serve as a workaround for Wrappers.cpp not supporting multiple inheritance (fails a static assert)
	class WorldTooltipsInputListener : public InputListener
	{
	public:
		virtual void OnRawInput(InputManager* self, InputRawChange* change, bool unknown) override;

		WorldTooltips* _WorldTooltips;
	};
	class WorldTooltipsPickerListener : public PickerListener
	{
	public:
		virtual void OnPickingDone(ecl::PickingHelper* picker) override;

		WorldTooltips* _WorldTooltips;
	};
	void Setup();

	void OnUpdateItems(void* netProtocol);

	bool OnInvoke0(UIObject* ui, int64_t invokeEnum) override;
	bool OnFunctionCalled(UIObject* ui, const char* uiCall, int paramsCount, ig::InvokeDataValue* invokeData) override;

private:
	WorldTooltipsInputListener _InputListener;
	WorldTooltipsPickerListener _PickerListener;
	ComponentHandle _ItemHandle;
	bool _OverridePicker = false;
	bool _RequestLooting = false;
};

END_NS()
