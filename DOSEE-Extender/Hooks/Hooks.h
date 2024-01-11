#pragma once
#include "pch.h"
#include "GameDefinitions/Symbols.h"

BEGIN_SE()

class UIEventListener
{
public:
	virtual bool OnInvoke2(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* a1, ig::InvokeDataValue* a2) { return false; };
	virtual bool OnInvoke3(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* a1, ig::InvokeDataValue* a2, ig::InvokeDataValue* a3) { return false; };
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
