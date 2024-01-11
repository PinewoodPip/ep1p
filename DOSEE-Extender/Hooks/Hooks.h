#pragma once
#include "pch.h"
#include "GameDefinitions/Symbols.h"

BEGIN_SE()

class UIEventListener
{
public:
	virtual bool OnInvoke0(UIObject* ui, int64_t invokeEnum) { return false; };
	virtual bool OnInvoke1(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1) { return false; };
	virtual bool OnInvoke2(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2) { return false; };
	virtual bool OnInvoke3(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2, ig::InvokeDataValue* invokeData3) { return false; };
	virtual bool OnInvoke4(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2, ig::InvokeDataValue* invokeData3, ig::InvokeDataValue* invokeData4) { return false; };
	virtual bool OnInvoke5(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2, ig::InvokeDataValue* invokeData3, ig::InvokeDataValue* invokeData4, ig::InvokeDataValue* invokeData5) { return false; };
	virtual bool OnInvoke6(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2, ig::InvokeDataValue* invokeData3, ig::InvokeDataValue* invokeData4, ig::InvokeDataValue* invokeData5, ig::InvokeDataValue* invokeData6) { return false; };
};

class Hooks
{
public:
	void Startup();

	void OnCreateUIObject(UIObjectManager* self, ComponentHandle* handle, unsigned int layerIndex, unsigned int creatorId, unsigned int flags,
		uint64_t resourceFlags, short playerID, ComponentHandle* result);
	void OnPickingHelperDone(ecl::PickingHelper* self);
	void OnInjectInput(InputManager* self, InputRawChange* change, bool unknown);

	void CaptureExternalInterfaceCalls(UIObject* uiObject);
	void RegisterUIListener(int typeID, UIEventListener* listener);

	ecl::Character* GetLastPickerCharacter();

	ComponentHandle LastPickerCharacterHandle = {};

	std::unordered_map<int, std::vector<UIEventListener*>> EventListeners;
private:
	bool loaded_{ false };
};

END_SE()
