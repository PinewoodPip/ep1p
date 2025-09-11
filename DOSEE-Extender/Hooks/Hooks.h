#pragma once
#include "pch.h"
#include "GameDefinitions/Symbols.h"

BEGIN_SE()

class UIEventListener
{
public:
	virtual bool OnInvoke0(UIObject* ui, int64_t invokeEnum) { return false; };
	virtual void AfterInvoke0(UIObject* ui, int64_t invokeEnum) { };
	virtual bool OnInvoke1(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1) { return false; };
	virtual bool OnInvoke2(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2) { return false; };
	virtual bool OnInvoke3(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2, ig::InvokeDataValue* invokeData3) { return false; };
	virtual bool OnInvoke4(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2, ig::InvokeDataValue* invokeData3, ig::InvokeDataValue* invokeData4) { return false; };
	virtual bool OnInvoke5(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2, ig::InvokeDataValue* invokeData3, ig::InvokeDataValue* invokeData4, ig::InvokeDataValue* invokeData5) { return false; };
	virtual bool OnInvoke6(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1, ig::InvokeDataValue* invokeData2, ig::InvokeDataValue* invokeData3, ig::InvokeDataValue* invokeData4, ig::InvokeDataValue* invokeData5, ig::InvokeDataValue* invokeData6) { return false; };

	virtual bool OnFunctionCalled(const char* uiCall, int paramsCount, ig::InvokeDataValue* invokeData) { return false; };
};

class GameStateChangedEventListener
{
public:
	virtual void OnGameStateChanged(int newState) = 0;
};

class InputListener
{
public:
	virtual void OnRawInput(InputManager* self, InputRawChange* change, bool unknown) = 0;
};

class GetAbilityBoostListener
{
public:
	virtual int OnGetAbilityBoost(CDivinityStats_Character* stats, AbilityType ability, bool excludeBoosts) = 0; // Return non-zero to override vanilla behaviour.
};

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

class Hooks
{
public:
	void Startup();

	void OnCreateUIObject(UIObjectManager* self, ComponentHandle* handle, unsigned int layerIndex, unsigned int creatorId, unsigned int flags,
		uint64_t resourceFlags, short playerID, ComponentHandle* result);
	void OnPickingHelperDone(ecl::PickingHelper* self);
	void OnInjectInput(InputManager* self, InputRawChange* change, bool unknown);
	void OnGameStateChanged(void* eventManager, uint32_t unknown1, uint32_t unknown2);
	int OnCharacterStatsGetAbilityBoostFromPrimaryStat(StaticSymbols::CDivinityStats_Character_GetAbilityBoostFromPrimaryStatProc* next, CDivinityStats_Character* stats, AbilityType ability, bool excludeBoosts);

	void CaptureExternalInterfaceCalls(UIObject* uiObject);
	void RegisterUIListener(int typeID, UIEventListener* listener);
	void RegisterGameStateChangedListener(GameStateChangedEventListener* listener);
	void RegisterInputListener(InputListener* listener);
	void RegisterAbilityBoostListener(GetAbilityBoostListener* listener);

	std::unordered_map<UIObject::VMT*, UIObject::OnFunctionCalledProc>& GetOriginalUIObjectCallHandlers();
	FlashPlayerHooks& GetFlashPlayerHooks();

	ComponentHandle LastPickerCharacterHandle = {};
	ComponentHandle CurrentPickerCharacterHandle = {};

	std::unordered_map<int, std::vector<UIEventListener*>> EventListeners;
	std::set<GameStateChangedEventListener*> GameStateChangedListeners;
	std::vector<InputListener*> InputListeners;
	std::vector<GetAbilityBoostListener*> AbilityBoostListeners;
private:
	bool loaded_{ false };
};

END_SE()
