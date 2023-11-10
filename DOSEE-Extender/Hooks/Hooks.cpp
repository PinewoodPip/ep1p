#pragma once
#include <pch.h>
#include <Extender/ScriptExtender.h>

BEGIN_SE()

void Hooks::Startup()
{
	if (loaded_) {
		return;
	}

	auto& lib = gExtender->GetEngineHooks();

	lib.UIObjectManager__CreateUIObject.SetPostHook(&Hooks::OnCreateUIObject, this);

	loaded_ = true;
}

void Hooks::OnCreateUIObject(UIObjectManager* self, ComponentHandle* handle, unsigned int layerIndex, unsigned int creatorId, unsigned int flags,
	uint64_t resourceFlags, short playerID, ComponentHandle* result)
{
	LOG("UIObject created with typeID %d", creatorId);
	UIObject* test = gExtender->GetEngineHooks().UIObjectManager__GetUIObjectByType.CallOriginal(self, creatorId);
	if (test)
	{
		LOG(L"from %s", test->Path.Name.c_str());
	}
}

END_SE()
