#pragma once
#include "Epip/EpipSettings.h"
#include "Hooks/Hooks.h"

using namespace dse;
using namespace epip;

class GameOptionsSettings : public UIEventListener
{
public:
	void Setup();
	void Render(ig::FlashPlayer* flashPlayer);
	void RenderLabel(ig::FlashPlayer* flashPlayer, STDWString label);
	void RenderComboBox(ig::FlashPlayer* flashPlayer, int id, STDWString label, STDWString tooltip, std::vector<STDWString> options, int selectedIndex);
	void RenderCheckbox(ig::FlashPlayer* flashPlayer, const int id, const STDWString label, bool enabled, int stateID, bool filtered, const STDWString tooltip);
	void RenderSlider(ig::FlashPlayer* flashPlayer, const int id, const STDWString label, float amount, float minimum, float maximum, int snapInterval, bool hideNumbers, const STDWString tooltip);
	void ApplyPendingChanges();
	void SaveToFile();

	virtual bool OnInvoke1(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1) override;
	bool OnFunctionCalled(const char* uiCall, int paramsCount, ig::InvokeDataValue* invokeData) override;

private:
	EpipSettings* _CurrentSettings;
	EpipSettings _PendingChanges;
	bool _HasPendingChanges = false;
};

