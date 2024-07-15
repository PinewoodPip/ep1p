#pragma once
#include <pch.h>
#include <Extender/ScriptExtender.h>
#include <string>
#include <format>
#include "Utils/Text.h"
#include "Extender/Utils/CharacterUtils.h"
#include "GameDefinitions/UI.h"
#include "GameDefinitions/Misc.h"
#include <algorithm>

BEGIN_SE()

std::unordered_map<UIObject::VMT*, UIObject::OnFunctionCalledProc> OriginalUIObjectCallHandlers;

FlashPlayerHooks flashPlayerHooks;

void Hooks::Startup()
{
	if (loaded_) {
		return;
	}

	auto& lib = gExtender->GetEngineHooks();

#if defined(OSI_EOCAPP)
	lib.UIObjectManager__CreateUIObject.SetPostHook(&Hooks::OnCreateUIObject, this);
	lib.ecl_PickingHelper_DoPick.SetPostHook(&Hooks::OnPickingHelperDone, this);
	lib.ls_InputManager_InjectInput.SetPreHook(&Hooks::OnInjectInput, this);
	lib.ecl_GameStateEventManager_ExecuteGameStateChangedEvent.SetPostHook(&Hooks::OnGameStateChanged, this);
	lib.CDivinityStats_Character_GetAbilityBoostFromPrimaryStat.SetWrapper(&Hooks::OnCharacterStatsGetAbilityBoostFromPrimaryStat, this); // Always hook this as it might be used by multiple tweaks.
#endif

	loaded_ = true;
}

void Hooks::OnGameStateChanged(void* eventManager, uint32_t newState, uint32_t unknown2)
{
	if (newState == ecl::EoCClient::GameState::PrepareRunning)
	{
		gExtender->RegisterIggyCallbacks();
	}
	for (auto listener : gExtender->GetHooks().GameStateChangedListeners)
	{
		listener->OnGameStateChanged(newState);
	}
}

UIObject* FindUIObjectByFlashPlayer(ig::FlashPlayer* flashPlayer)
{
	UIObjectManager* manager = gStaticSymbols->GetUIObjectManager();
	UIObject* ui = nullptr;
	for (int i = 0; i < manager->UIObjectsCount; ++i)
	{
		if (manager->UIObjects[i]->FlashPlayer == flashPlayer)
		{
			ui = manager->UIObjects[i];
			break;
		}
	}
	return ui;
}

void Hooks::OnCreateUIObject(UIObjectManager* self, ComponentHandle* handle, unsigned int layerIndex, unsigned int creatorId, unsigned int flags,
	uint64_t resourceFlags, short playerID, ComponentHandle* result)
{
	LOG("UIObject created with typeID %d", creatorId);
	UIObject* ui = (self->UIObjects)[self->UIObjectsCount - 1];
	// The new UI is not always the last one in the set - they might be sorted?
	for (int i = 0; i < self->UIObjectsCount; ++i)
	{
		CaptureExternalInterfaceCalls(self->UIObjects[i]);
	}
}

void Hooks::OnPickingHelperDone(ecl::PickingHelper* self)
{
	ComponentHandle characterHandle = self->CurrentCharacterHandle;
	ecl::Character* character = ClientCharacterUtils::GetCharacter(characterHandle);
	if (character)
	{
		LastPickerCharacterHandle = characterHandle;
	}
	CurrentPickerCharacterHandle = character ? characterHandle : ComponentHandle();
}

int Hooks::OnCharacterStatsGetAbilityBoostFromPrimaryStat(StaticSymbols::CDivinityStats_Character_GetAbilityBoostFromPrimaryStatProc* next, CDivinityStats_Character* stats, AbilityType ability, bool excludeBoosts)
{
	for (auto listener : AbilityBoostListeners)
	{
		int value = listener->OnGetAbilityBoost(stats, ability, excludeBoosts);
		if (value != 0)
		{
			return value;
		}
	}
	return next(stats, ability, excludeBoosts);
}

static bool OnGetFlashMovieProperties(ig::FlashPlayer* flashPlayer, ig::FlashPlayerProperties* props)
{
	UIObject* hotbar = FindUIObjectByFlashPlayer(flashPlayer);
	bool success = flashPlayerHooks.OriginalGetFlashMovieProperties(flashPlayer, props);
	if (hotbar && hotbar->TypeId == (int)UIObject::TypeID::SkillBar)
	{
		//props->Width = 700;
		//hotbar->McSizeWidth = 700;
	}
	return success;
}

static bool OnInvoke0(ig::FlashPlayer* flashPlayer, int64_t invokeEnum)
{
	UIObject* ui = FindUIObjectByFlashPlayer(flashPlayer);
	if (ui)
	{
		//LOG(L"Invoke0 ID %d from TypeID %d path %s", invokeEnum, ui->TypeID, ui->Path.Name.c_str());
		Hooks hooks = gExtender->GetHooks();
		if (hooks.EventListeners.contains(ui->TypeId))
		{
			auto listeners = hooks.EventListeners.find(ui->TypeId)->second;
			for (auto listener : listeners)
			{
				listener->OnInvoke0(ui, invokeEnum);
			}
		}
	}
	return flashPlayerHooks.OriginalInvoke0(flashPlayer, invokeEnum);
}

static bool OnInvoke1(ig::FlashPlayer* flashPlayer, int64_t invokeEnum, ig::InvokeDataValue* invokeData1)
{
	UIObject* ui = FindUIObjectByFlashPlayer(flashPlayer);
	if (ui)
	{
		//LOG(L"Invoke1 ID %d from TypeID %d path %s", invokeEnum, ui->TypeID, ui->Path.Name.c_str());
		Hooks hooks = gExtender->GetHooks();
		if (hooks.EventListeners.contains(ui->TypeId))
		{
			auto listeners = hooks.EventListeners.find(ui->TypeId)->second;
			for (auto listener : listeners)
			{
				listener->OnInvoke1(ui, invokeEnum, invokeData1);
			}
		}
	}
	return flashPlayerHooks.OriginalInvoke1(flashPlayer, invokeEnum, invokeData1);
}

static bool OnInvoke2(ig::FlashPlayer* flashPlayer, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2)
{
	UIObject* ui = FindUIObjectByFlashPlayer(flashPlayer);
	if (ui)
	{
		//LOG(L"Invoke2 ID %d from TypeID %d path %s", invokeEnum, ui->TypeID, ui->Path.Name.c_str());
		Hooks hooks = gExtender->GetHooks();
		if (hooks.EventListeners.contains(ui->TypeId))
		{
			auto listeners = hooks.EventListeners.find(ui->TypeId)->second;
			for (auto listener : listeners)
			{
				listener->OnInvoke2(ui, invokeEnum, invokeData1, invokeData2);
			}
		}
	}
	return flashPlayerHooks.OriginalInvoke2(flashPlayer, invokeEnum, invokeData1, invokeData2);
}

static bool OnInvoke3(ig::FlashPlayer* flashPlayer, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2, ig::InvokeDataValue* invokeData3)
{
	UIObject* ui = FindUIObjectByFlashPlayer(flashPlayer);
	if (ui)
	{
		//LOG(L"Invoke3 ID %d from TypeID %d path %s", invokeEnum, ui->TypeID, ui->Path.Name.c_str());
		Hooks hooks = gExtender->GetHooks();
		if (hooks.EventListeners.contains(ui->TypeId))
		{
			auto listeners = hooks.EventListeners.find(ui->TypeId)->second;
			for (auto listener : listeners)
			{
				listener->OnInvoke3(ui, invokeEnum, invokeData1, invokeData2, invokeData3);
			}
		}
	}
	return flashPlayerHooks.OriginalInvoke3(flashPlayer, invokeEnum, invokeData1, invokeData2, invokeData3);
}

static bool OnInvoke4(ig::FlashPlayer* flashPlayer, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2, ig::InvokeDataValue* invokeData3, ig::InvokeDataValue* invokeData4)
{
	UIObject* ui = FindUIObjectByFlashPlayer(flashPlayer);
	if (ui)
	{
		//LOG(L"Invoke4 ID %d from TypeID %d path %s", invokeEnum, ui->TypeID, ui->Path.Name.c_str());
		Hooks hooks = gExtender->GetHooks();
		if (hooks.EventListeners.contains(ui->TypeId))
		{
			auto listeners = hooks.EventListeners.find(ui->TypeId)->second;
			for (auto listener : listeners)
			{
				listener->OnInvoke4(ui, invokeEnum, invokeData1, invokeData2, invokeData3, invokeData4);
			}
		}
	}
	return flashPlayerHooks.OriginalInvoke4(flashPlayer, invokeEnum, invokeData1, invokeData2, invokeData3, invokeData4);
}

static bool OnInvoke5(ig::FlashPlayer* flashPlayer, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2, ig::InvokeDataValue* invokeData3, ig::InvokeDataValue* invokeData4, ig::InvokeDataValue* invokeData5)
{
	UIObject* ui = FindUIObjectByFlashPlayer(flashPlayer);
	if (ui)
	{
		//LOG(L"Invoke5 ID %d from TypeID %d path %s", invokeEnum, ui->TypeID, ui->Path.Name.c_str());
		Hooks hooks = gExtender->GetHooks();
		if (hooks.EventListeners.contains(ui->TypeId))
		{
			auto listeners = hooks.EventListeners.find(ui->TypeId)->second;
			for (auto listener : listeners)
			{
				listener->OnInvoke5(ui, invokeEnum, invokeData1, invokeData2, invokeData3, invokeData4, invokeData5);
			}
		}
	}
	return flashPlayerHooks.OriginalInvoke5(flashPlayer, invokeEnum, invokeData1, invokeData2, invokeData3, invokeData4, invokeData5);
}

static bool OnInvoke6(ig::FlashPlayer* flashPlayer, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2, ig::InvokeDataValue* invokeData3, ig::InvokeDataValue* invokeData4, ig::InvokeDataValue* invokeData5, ig::InvokeDataValue* invokeData6)
{
	UIObject* ui = FindUIObjectByFlashPlayer(flashPlayer);
	if (ui)
	{
		//LOG(L"Invoke6 ID %d from TypeID %d path %s", invokeEnum, ui->TypeID, ui->Path.Name.c_str());
		Hooks hooks = gExtender->GetHooks();
		if (hooks.EventListeners.contains(ui->TypeId))
		{
			auto listeners = hooks.EventListeners.find(ui->TypeId)->second;
			for (auto listener : listeners)
			{
				listener->OnInvoke6(ui, invokeEnum, invokeData1, invokeData2, invokeData3, invokeData4, invokeData5, invokeData6);
			}
		}
	}
	return flashPlayerHooks.OriginalInvoke6(flashPlayer, invokeEnum, invokeData1, invokeData2, invokeData3, invokeData4, invokeData5, invokeData6);
}

void CaptureInvokes(UIObject* ui)
{
	// Only do this once; all FlashPlayers use the same VMT
	if (flashPlayerHooks.Hooked) return;

	ig::FlashPlayer* flashPlayer = ui->FlashPlayer;
	auto vmt = *reinterpret_cast<ig::FlashPlayer::VMT**>(flashPlayer);

	WriteAnchor _w((uint8_t*)vmt, sizeof(*vmt));
	flashPlayerHooks.OriginalInvoke0 = vmt->Invoke0;
	vmt->Invoke0 = &OnInvoke0;
	flashPlayerHooks.OriginalInvoke1 = vmt->Invoke1;
	vmt->Invoke1 = &OnInvoke1;
	flashPlayerHooks.OriginalInvoke2 = vmt->Invoke2;
	vmt->Invoke2 = &OnInvoke2;
	flashPlayerHooks.OriginalInvoke3 = vmt->Invoke3;
	vmt->Invoke3 = &OnInvoke3;
	flashPlayerHooks.OriginalInvoke4 = vmt->Invoke4;
	vmt->Invoke4 = &OnInvoke4;
	flashPlayerHooks.OriginalInvoke5 = vmt->Invoke5;
	vmt->Invoke5 = &OnInvoke5;
	flashPlayerHooks.OriginalInvoke6 = vmt->Invoke6;
	vmt->Invoke6 = &OnInvoke6;
	flashPlayerHooks.Hooked = true;
}

void UIObjectFunctionCallCapture(UIObject* self, const char* function, unsigned int numArgs, ig::InvokeDataValue* args)
{
	int i;
	/*LOG("UICall %s argsCount %d", function, numArgs);
	LOG(L"	from %s", self->Path.Name.c_str());
	for (i = 0; i < numArgs; ++i)
	{
		ig::InvokeDataValue* invokeValue = &args[i];
		switch (invokeValue->TypeId)
		{
			case ig::DataType::String:
			{
				LOG_NO_ENDL(" String %s", invokeValue->StringVal.c_str());
				break;
			}
			case ig::DataType::Double:
			{
				LOG_NO_ENDL(" Double %f", invokeValue->DoubleVal);
				break;
			}
			case ig::DataType::Bool:
			{
				if (invokeValue->BoolVal)
				{
					LOG_NO_ENDL(" Bool True");
				}
				else
				{
					LOG_NO_ENDL(" Bool False");
				}
				break;
			}
		}
		break;
	}
	LOG("");*/

	// Forward event to listeners
	Hooks hooks = gExtender->GetHooks();
	if (hooks.EventListeners.contains(self->TypeId))
	{
		auto listeners = hooks.EventListeners.find(self->TypeId)->second;
		for (auto listener : listeners)
		{
			listener->OnFunctionCalled(function, numArgs, args);
		}
	}

	auto vmt = *reinterpret_cast<UIObject::VMT**>(self);
	auto handler = OriginalUIObjectCallHandlers.find(vmt);
	if (handler != OriginalUIObjectCallHandlers.end()) {
		handler->second(self, function, numArgs, args);
	}
	else {
		WARN("Couldn't find original OnFunctionCalled handler for UI object");
	}

	// Setup Invoke captures, if necessary
	CaptureInvokes(self);
}

void Hooks::CaptureExternalInterfaceCalls(UIObject* uiObject)
{
	auto vmt = *reinterpret_cast<UIObject::VMT**>(uiObject);
	if (vmt->OnFunctionCalled == &UIObjectFunctionCallCapture) return;

	WriteAnchor _w((uint8_t*)vmt, sizeof(*vmt));
	OriginalUIObjectCallHandlers.insert(std::make_pair(vmt, vmt->OnFunctionCalled));
	vmt->OnFunctionCalled = &UIObjectFunctionCallCapture;
}

void Hooks::RegisterUIListener(int typeID, UIEventListener* listener)
{
	if (!this->EventListeners.contains(typeID))
	{
		this->EventListeners.insert(std::make_pair(typeID, std::vector<UIEventListener*>()));
	}
	auto listeners = this->EventListeners.find(typeID);
	listeners->second.push_back(listener);
}

void Hooks::RegisterGameStateChangedListener(GameStateChangedEventListener* listener)
{
	GameStateChangedListeners.insert(listener);
}

void Hooks::RegisterInputListener(InputListener* listener)
{
	InputListeners.push_back(listener);
}

void Hooks::RegisterAbilityBoostListener(GetAbilityBoostListener* listener)
{
	AbilityBoostListeners.push_back(listener);
}

std::unordered_map<UIObject::VMT*, UIObject::OnFunctionCalledProc>& Hooks::GetOriginalUIObjectCallHandlers()
{
	return OriginalUIObjectCallHandlers;
}

FlashPlayerHooks& Hooks::GetFlashPlayerHooks()
{
	return flashPlayerHooks;
}

void Hooks::OnInjectInput(InputManager* self, InputRawChange* change, bool unknown)
{
	for (auto listener : InputListeners)
	{
		listener->OnRawInput(self, change, unknown);
	}
}

END_SE()
