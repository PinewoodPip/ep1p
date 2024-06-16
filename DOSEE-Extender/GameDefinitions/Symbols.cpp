#pragma once

#include <pch.h>
//#include <GameDefinitions/Components/Character.h>
//#include <GameDefinitions/Components/Projectile.h>
//#include <GameDefinitions/GameObjects/GameAction.h>
//#include <GameDefinitions/Components/Inventory.h>
//#include <GameDefinitions/GameObjects/Level.h>
//#include <GameDefinitions/CustomStats.h>
//#include <GameDefinitions/Input.h>
//#include <GameDefinitions/Misc.h>
//#include <GameDefinitions/Osiris.h>
//#include <GameDefinitions/GameObjects/ActionMachine.h>
#include <GameDefinitions/UI.h>
//#include <GameDefinitions/GameObjects/Surface.h>
//#include <GameDefinitions/GameObjects/AiHelpers.h>
//#include <GameDefinitions/GameObjects/Controllers.h>
//#include <GameDefinitions/GameObjects/Camera.h>
//#include <GameDefinitions/GameObjects/Material.h>
//#include <GameDefinitions/GameObjects/Vision.h>
#include <GameDefinitions/EntitySystem.h>
#include <GameDefinitions/RPGStats.h>

namespace dse
{
	//enum class EsvGlobalEoCApp {
	//	EsvLSDialogEventManager = 0,
	//	EsvStoryDialogEventManager = 1,
	//	EsvStoryItemEventManager = 2,
	//	EsvStoryCharacterEventManager = 3,
	//	// 4
	//	// 5-6 event visitor
	//	// 7-8 game event visitor
	//	ServerLevelManager = 9,
	//	PartyManager = 10,
	//	EsvCharacterFactory = 11,
	//	// 12
	//	EsvProjectileFactory = 13,
	//	EsvEoCTriggerFactory = 14,
	//	EsvItemFactory = 15,
	//	EsvSkillFactory = 16,
	//	EsvSkillStatePool = 17,
	//	EsvInventoryFactory = 18,
	//	EsvInventoryViewFactory = 19,
	//	StoryImplementation = 20,
	//	AlignmentFactory = 21,
	//	AlignmentContainer = 22,
	//	OsirisVariableHelper = 23,
	//	// 24
	//	OverheadTextFactory = 25,
	//	SurfaceActionFactory = 26,
	//	CustomBookManager = 27,
	//	// 28
	//	GameControl = 29,
	//	// 30
	//	CharacterCreationManager = 31,
	//	MarkerManager = 32,
	//	OsirisTaskFactory = 33,
	//	EnvironmentalInfluencesPool = 34,
	//	CombatFormationManager = 35,
	//	DivinityStats = 36,
	//	PlanManager = 37,
	//	// 38
	//	ActivationManager = 39
	//};

	//enum class EsvGlobalEoCPlugin {
	//	EsvSavegameManager = 0,
	//	EsvEoCServer = 1,
	//	EsvCacheTemplateManager = 2,
	//	EsvAiFactory = 3,
	//	EsvGameObjectFactory = 4,
	//	EsvLSDialogEventManager = 5,
	//	EsvStoryDialogEventManager = 6,
	//	EsvStoryItemEventManager = 7,
	//	EsvStoryCharacterEventManager = 8,
	//	// 9, 10-11, 12-13 event visitors
	//	ServerLevelManager = 14,
	//	PartyManager = 15,
	//	EsvCharacterFactory = 16,
	//	EsvProjectileFactory = 17,
	//	EsvEoCTriggerFactory = 18,
	//	EsvItemFactory = 19,
	//	EsvSkillFactory = 20,
	//	EsvSkillStatePool = 21,
	//	EsvInventoryFactory = 22,
	//	EsvInventoryViewFactory = 23,
	//	StoryImplementation = 24,
	//	AlignmentFactory = 25,
	//	OsirisVariableHelper = 26,
	//	// 27
	//	OverheadTextFactory = 28,
	//	SurfaceActionFactory = 29,
	//	CustomBookManager = 30,
	//	// 31
	//	GameControl = 32,
	//	// 33
	//	CharacterCreationManager = 34,
	//	MarkerManager = 35,
	//	OsirisTaskFactory = 36,
	//	EnvironmentalInfluencesPool = 37,
	//	CombatFormationManager = 38,
	//	DivinityStats = 39,
	//	PlanManager = 40,
	//	ActivationManager = 41
	//};

	struct StaticSymbols : Noncopyable<StaticSymbols>
	{
		struct EoCLibraryInfo
		{
			uint8_t const* initFunc;
			uint8_t const* freeFunc;
			uint32_t refs;
		};

		EoCAllocFunc EoCAlloc{ nullptr };
		EoCFreeFunc EoCFree{ nullptr };
		CrtAllocFunc CrtAlloc{ nullptr };
		CrtFreeFunc CrtFree{ nullptr };

		typedef int (*CDivinityStats_Character__GetResistanceFunc)(CDivinityStats_Character* self, bool ignoreBoosts);
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetFireResistance{ nullptr };
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetEarthResistance{ nullptr };
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetWaterResistance{ nullptr };
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetAirResistance{ nullptr };
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetPoisonResistance{ nullptr };
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetPiercingResistance{ nullptr };
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetCrushingResistance{ nullptr };
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetSlashingResistance{ nullptr };
		CDivinityStats_Character__GetResistanceFunc CDivinityStats_Character__GetShadowResistance{ nullptr };

		ComponentFactory<ecl::Character>** ObjectFactory__ecl_Character{ nullptr };
		esv::PlanManager::ScriptParam** esv_ScriptParam_DontCare{ nullptr };

		//typedef void (*ecl_PickingHelper_DoPickFunc)(ecl::PickingHelper* self);
		//ecl_PickingHelper_DoPickFunc ecl_PickingHelper_DoPick{ nullptr };

		FixedString::CreateProc* ls__FixedString__Create{ nullptr };
		GlobalStringTable const** ls__GlobalStrings{ nullptr };

		Path::GetPrefixForRootProc* ls__Path__GetPrefixForRoot{ nullptr };
		STDString** ls__PathRoots{ nullptr };

		uint8_t const* ActivateClientSystemsHook{ nullptr };
		uint8_t const* ActivateServerSystemsHook{ nullptr };
		eoc::NetworkFixedStrings** NetworkFixedStrings{ nullptr };
		void* InitNetworkFixedStrings{ nullptr };


		/*UIObjectManager::RegisterUIObjectCreatorProc* UIObjectManager__RegisterUIObjectCreator{ nullptr };*/
		UIObjectManager::CreateUIObjectProc* UIObjectManager__CreateUIObject{ nullptr };
		UIObjectManager::GetUIObjectByTypeProc* UIObjectManager__GetUIObjectByType{ nullptr };
		UIObjectManager::GetInstanceProc* UIObjectManager__GetInstance{ nullptr };
		UIObjectManager** UIObjectManager__Instance{ nullptr };
		/*UIObjectManager::DestroyUIObjectProc* UIObjectManager__DestroyUIObject{ nullptr };
		UIObjectManager** UIObjectManager__Instance{ nullptr };
		ecl::EoCUI::ctor ecl__EoCUI__ctor{ nullptr };
		UIObject::VMT* ecl__EoCUI__vftable{ nullptr };
		UIObject::GetUIScaleMultiplierProc* ls__UIObject__GetUIScaleMultiplier{ nullptr };
		UIObject::RaiseFlagProc* ls__UIObject__RaiseFlag{ nullptr };
		UIObject::RaiseFlagProc* ls__UIObject__ClearFlag{ nullptr };*/

		/*ig::ValuePathMakeNameRefProc IgValuePathMakeNameRef{ nullptr };
		ig::ValuePathMakeArrayRefProc IgValuePathPathMakeArrayRef{ nullptr };
		ig::ValuePathSetArrayIndexProc IgValuePathSetArrayIndex{ nullptr };

		ig::ValueGetTypeProc IgValueGetType{ nullptr };
		ig::ValueGetArrayLengthProc IgValueGetArrayLength{ nullptr };

		ig::ValueGetBooleanProc IgValueGetBoolean{ nullptr };
		ig::ValueGetF64Proc IgValueGetF64{ nullptr };
		ig::ValueGetStringUTF8Proc IgValueGetStringUTF8{ nullptr };

		ig::ValueSetBooleanProc IgValueSetBoolean{ nullptr };
		ig::ValueSetF64Proc IgValueSetF64{ nullptr };
		ig::ValueSetStringUTF8Proc IgValueSetStringUTF8{ nullptr };

		ig::PlayerCreateFastNameUTF8 IgPlayerCreateFastNameUTF8{ nullptr };
		ig::PlayerCallMethod IgPlayerCallMethod{ nullptr };

		ig::SetWarningCallbackProc IgSetWarningCallback{ nullptr };
		ig::SetTraceCallbackUTF8Proc IgSetTraceCallbackUTF8{ nullptr };*/

		void* DUMMY1{ nullptr };
		std::map<uint8_t const*, EoCLibraryInfo> Libraries;

		uint8_t const* ServerRegisterFuncs[50]{ nullptr };
		uint8_t* const* ServerGlobals[50]{ nullptr };
		uint8_t const* EocRegisterFuncs[6]{ nullptr };
		uint8_t const** EocGlobals[6]{ nullptr };

		inline StaticSymbols() {}
		StaticSymbols(StaticSymbols const&) = delete;
		StaticSymbols& operator = (StaticSymbols const&) = delete;

		/*inline void RegisterUIObjectCreator(UIObjectManager* self, unsigned int index, UIObjectFunctor* creator)
		{
#if defined(OSI_EOCAPP)
			auto hashMap = (UIObjectManager*)((intptr_t)self + offsetof(UIObjectManager, UIObjectCreators));
			UIObjectManager__RegisterUIObjectCreator(hashMap, index, creator);
#else
			UIObjectManager__RegisterUIObjectCreator(self, index, creator);
#endif
		}*/
	};

	extern StaticSymbols* gStaticSymbols;

	void InitStaticSymbols();

	inline StaticSymbols& GetStaticSymbols()
	{
		return *gStaticSymbols;
	}
}
