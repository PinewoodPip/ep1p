#pragma once
#include <pch.h>
#include <Extender/ScriptExtender.h>
#include <format>
#include "Utils/Text.h"

BEGIN_SE()

std::unordered_map<UIObject::VMT*, UIObject::OnFunctionCalledProc> OriginalUIObjectCallHandlers;

struct FlashPlayerHooks
{
	bool Hooked{ false };
	ig::FlashPlayer::VMT* VMT{ nullptr };
	ig::FlashPlayer::VMT::Invoke6Proc OriginalInvoke6{ nullptr };
	ig::FlashPlayer::VMT::Invoke5Proc OriginalInvoke5{ nullptr };
	ig::FlashPlayer::VMT::Invoke4Proc OriginalInvoke4{ nullptr };
	ig::FlashPlayer::VMT::Invoke3Proc OriginalInvoke3{ nullptr };
	ig::FlashPlayer::VMT::Invoke2Proc OriginalInvoke2{ nullptr };
	ig::FlashPlayer::VMT::Invoke1Proc OriginalInvoke1{ nullptr };
	ig::FlashPlayer::VMT::Invoke0Proc OriginalInvoke0{ nullptr };
	ig::FlashPlayer::VMT::InvokeArgsProc OriginalInvokeArgs{ nullptr };

	/*void Hook(ig::FlashPlayer::VMT* vmt);*/
};

FlashPlayerHooks flashPlayerHooks;

void Hooks::Startup()
{
	if (loaded_) {
		return;
	}

	auto& lib = gExtender->GetEngineHooks();

	lib.UIObjectManager__CreateUIObject.SetPostHook(&Hooks::OnCreateUIObject, this);
	lib.ecl_PickingHelper_DoPick.SetPostHook(&Hooks::OnPickingHelperDone, this);

	loaded_ = true;
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
	if (ui)
	{
		LOG(L"from %s", ui->Path.Name.c_str());
		CaptureExternalInterfaceCalls(ui);
	}
}

void Hooks::OnPickingHelperDone(ecl::PickingHelper* self)
{
	ComponentHandle characterHandle = self->CurrentCharacterHandle;
	ComponentFactory<ecl::Character>* factory = *GetStaticSymbols().ObjectFactory__ecl_Character;
	ecl::Character* character = factory->Get(characterHandle);
	if (character)
	{
		LOG("Picking done");
		LastPickerCharacterHandle = characterHandle;
	}
}

static bool OnInvoke0(ig::FlashPlayer* flashPlayer, int64_t invokeEnum)
{
	UIObject* ui = FindUIObjectByFlashPlayer(flashPlayer);
	if (ui)
	{
		//LOG(L"Invoke0 ID %d from TypeID %d path %s", invokeEnum, ui->TypeID, ui->Path.Name.c_str());
	}
	return flashPlayerHooks.OriginalInvoke0(flashPlayer, invokeEnum);
}

static bool OnInvoke1(ig::FlashPlayer* flashPlayer, int64_t invokeEnum, ig::InvokeDataValue* invokeData1)
{
	UIObject* ui = FindUIObjectByFlashPlayer(flashPlayer);
	if (ui)
	{
		//LOG(L"Invoke1 ID %d from TypeID %d path %s", invokeEnum, ui->TypeID, ui->Path.Name.c_str());
	}
	return flashPlayerHooks.OriginalInvoke1(flashPlayer, invokeEnum, invokeData1);
}

static bool OnInvoke2(ig::FlashPlayer* flashPlayer, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2)
{
	UIObject* ui = FindUIObjectByFlashPlayer(flashPlayer);
	if (ui)
	{
		//LOG(L"Invoke2 ID %d from TypeID %d path %s", invokeEnum, ui->TypeID, ui->Path.Name.c_str());
	}
	return flashPlayerHooks.OriginalInvoke2(flashPlayer, invokeEnum, invokeData1, invokeData2);
}

static bool OnInvoke3(ig::FlashPlayer* flashPlayer, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2, ig::InvokeDataValue* invokeData3)
{
	UIObject* ui = FindUIObjectByFlashPlayer(flashPlayer);
	if (ui)
	{
		//LOG(L"Invoke3 ID %d from TypeID %d path %s", invokeEnum, ui->TypeID, ui->Path.Name.c_str());
		if (invokeEnum == 9 && ui->TypeID == 0x29)
		{
			UITargetInfo* targetInfoUI = (UITargetInfo*)ui;
			targetInfoUI->ShowHP = true;
			ComponentFactory<ecl::Character>* factory = *GetStaticSymbols().ObjectFactory__ecl_Character;
			ecl::Character* character = factory->Get(gExtender->GetHooks().LastPickerCharacterHandle);

			if (character)
			{
				CDivinityStats_Character* stats = character->Stats;
				int32_t slashingResistance = GetStaticSymbols().CDivinityStats_Character__GetSlashingResistance(stats, false);
				int32_t piercingResistance = GetStaticSymbols().CDivinityStats_Character__GetPiercingResistance(stats, false);
				int32_t crushingResistance = GetStaticSymbols().CDivinityStats_Character__GetCrushingResistance(stats, false);
				int32_t fireResistance = GetStaticSymbols().CDivinityStats_Character__GetFireResistance(stats, false);
				int32_t waterResistance = GetStaticSymbols().CDivinityStats_Character__GetWaterResistance(stats, false);
				int32_t earthResistance = GetStaticSymbols().CDivinityStats_Character__GetEarthResistance(stats, false);
				int32_t airResistance = GetStaticSymbols().CDivinityStats_Character__GetAirResistance(stats, false);
				int32_t poisonResistance = GetStaticSymbols().CDivinityStats_Character__GetPoisonResistance(stats, false);
				int32_t tenebriumResistance = GetStaticSymbols().CDivinityStats_Character__GetShadowResistance(stats, false);
				std::string formattedResistances = std::format("{}  {}  {}  {}  {}  {}\n{}  {}  {}",
					Text::Colorize(std::format("{}%", std::to_string(fireResistance)), "f77c27"),
					Text::Colorize(std::format("{}%", std::to_string(waterResistance)), "27aff6"),
					Text::Colorize(std::format("{}%", std::to_string(earthResistance)), "aa7840"),
					Text::Colorize(std::format("{}%", std::to_string(airResistance)), "8f83cb"),
					Text::Colorize(std::format("{}%", std::to_string(poisonResistance)), "5bd42b"),
					Text::Colorize(std::format("{}%", std::to_string(tenebriumResistance)), "5b34ca"),
					Text::Colorize(std::format("S: {}%", std::to_string(slashingResistance)), "acacac"),
					Text::Colorize(std::format("P: {}%", std::to_string(piercingResistance)), "acacac"),
					Text::Colorize(std::format("C: {}%", std::to_string(crushingResistance)), "acacac")
				);
				invokeData2->WStringVal = dse::STDWString(formattedResistances.begin(), formattedResistances.end());

				std::string healthBarHeaderLabel = std::format("{} - {}/{} HP", std::string(invokeData1->WStringVal.begin(), invokeData1->WStringVal.end()), character->Stats->CurrentHP, character->Stats->MaxHP);
				invokeData1->WStringVal = dse::STDWString(healthBarHeaderLabel.begin(), healthBarHeaderLabel.end());
			}
		}
	}
	return flashPlayerHooks.OriginalInvoke3(flashPlayer, invokeEnum, invokeData1, invokeData2, invokeData3);
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
	flashPlayerHooks.Hooked = true;
}

void UIObjectFunctionCallCapture(UIObject* self, const char* function, unsigned int numArgs, ig::InvokeDataValue* args)
{
	int i;
	LOG("UICall %s argsCount %d", function, numArgs);
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
	LOG("");
	auto vmt = *reinterpret_cast<UIObject::VMT**>(self);
	auto handler = OriginalUIObjectCallHandlers.find(vmt);
	if (handler != OriginalUIObjectCallHandlers.end()) {
		handler->second(self, function, numArgs, args);
	}
	else {
		WARN("Couldn't find original OnFunctionCalled handler for UI object");
	}

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

END_SE()
