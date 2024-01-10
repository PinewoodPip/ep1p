#pragma once
#include "pch.h"
#include "GameDefinitions/Symbols.h"

BEGIN_SE()

class Hooks
{
public:
	void Startup();

	void OnCreateUIObject(UIObjectManager* self, ComponentHandle* handle, unsigned int layerIndex, unsigned int creatorId, unsigned int flags,
		uint64_t resourceFlags, short playerID, ComponentHandle* result);
	void OnPickingHelperDone(ecl::PickingHelper* self);

	void CaptureExternalInterfaceCalls(UIObject* uiObject);

	ComponentHandle LastPickerCharacterHandle = {};
private:
	bool loaded_{ false };
};

END_SE()
