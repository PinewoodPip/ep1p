#include "pch.h"
#include "ScriptBugWatchdog.h"
#include "Extender/ScriptExtender.h"

void ScriptBugWatchdog::Setup()
{
	auto& lib = gExtender->GetEngineHooks();
	lib.esv_ActivationManager_ThrowOnCharacterItemEvent.SetWrapper(&ScriptBugWatchdog::OnActivateCharacterItemEvent, this);
	lib.ObjectPool__esv_ScriptParam_Release.SetWrapper(&ScriptBugWatchdog::OnScriptParamRelease, this);
}

bool IsParamTypeWrong(esv::PlanManager::ScriptParam* param, esv::PlanManager::ScriptParam::ParamType expectedType)
{
	return param->Type != esv::PlanManager::ScriptParam::WILDCARD && param->Type != expectedType;
}

void ScriptBugWatchdog::OnActivateCharacterItemEvent(StaticSymbols::esv_ActivationManager_ThrowOnCharacterItemEventProc* next, esv::ActivationManager* self, esv::Character* character, esv::Item* item, char* eventName)
{
	// Stop performing this check once a scripting failure has happened.
	if (_WarningShown) return;

	// If the global _ param has been overwritten, the scripting engine has become borked and any character/item initialized afterwards will have broken scripts.
	esv::PlanManager::ScriptParam* dontCareParam = *GetStaticSymbols().esv_ScriptParam_DontCare;
	if (dontCareParam->Type != esv::PlanManager::ScriptParam::WILDCARD)
	{
		auto uiCtrl = *GetStaticSymbols().ecl_EocUIControl;
		wchar_t msg[255] = L"Ep1p has detected that the scripting engine has become borked.<br>It is highly recommended to save and fully restart the game before continuing.";
		GetStaticSymbols().ecl_EocUIControl_ShowCommonMessageBox(uiCtrl, &msg[0]);
		_WarningShown = true;
	}

	next(self, character, item, eventName);
}

void ScriptBugWatchdog::OnScriptParamRelease(StaticSymbols::ObjectPool__esv_ScriptParam_ReleaseProc* next, void* pool, esv::PlanManager::ScriptParam* param)
{
	if (param == *GetStaticSymbols().esv_ScriptParam_DontCare)
	{
		LOG("Attempting to release DontCare parameter; the scripting engine would become borked!");
		return;
	}
	next(pool, param);
}
