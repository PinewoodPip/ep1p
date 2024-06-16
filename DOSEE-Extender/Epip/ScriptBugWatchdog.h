#pragma once
#include "Hooks/Hooks.h"

using namespace dse;

class ScriptBugWatchdog
{
public:
	void Setup();
private:
	void OnActivateCharacterItemEvent(StaticSymbols::esv_ActivationManager_ThrowOnCharacterItemEventProc* next, esv::ActivationManager* self, esv::Character* character, esv::Item* item, char* eventName);
	void OnScriptParamRelease(StaticSymbols::ObjectPool__esv_ScriptParam_ReleaseProc* next, void* pool, esv::PlanManager::ScriptParam* param);

	bool _WarningShown = false;
};

