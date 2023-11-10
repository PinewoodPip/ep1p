#pragma once
#include "pch.h"

BEGIN_SE()

class Hooks
{
public:
	void Startup();

	void OnCreateUIObject(UIObjectManager* self, ComponentHandle* handle, unsigned int layerIndex, unsigned int creatorId, unsigned int flags,
		uint64_t resourceFlags, short playerID, ComponentHandle* result);

private:
	bool loaded_{ false };
};

END_SE()
