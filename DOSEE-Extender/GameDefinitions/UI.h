#pragma once

#include <GameDefinitions/Base/Base.h>
//#include <GameDefinitions/Enumerations.h>
//#include <GameDefinitions/EntitySystem.h>

// TODO remove
#define UIObjectFlags int

namespace dse
{
	namespace ig
	{
		enum class DataType : int32_t
		{
			None = 0x1,
			Null = 0x2,
			Bool = 0x3,
			Double = 0x4,
			String = 0x5,
			WString = 0x6,
			Array = 0xA,
			Object = 0xB,
			Object2 = 0xC,
			Function = 0x10,
			UserData = 0x11,
			UserData2 = 0x12,
		};

		struct InvokeDataValue
		{
			DataType TypeId;
			undefined _Padding1[4];
			STDString StringVal;
			STDWString WStringVal;
			bool BoolVal;
			//void* PointerVal;
			//void* unknown1;
			undefined _Padding2[15];
			float DoubleVal;
		};

		struct IggyValuePath
		{
			void* Iggy;
			IggyValuePath* Parent;
			void* Name;
			void* Ref;
			int32_t ArrayIndex;
			int32_t Type;
		};

		struct FlashInvokeName
		{
			void* IggyFastPathRef;
			char* Name;
		};

		struct IggyDataValue
		{
			DataType TypeId;
			int field_4;
			int field_8;
			int field_C;
			union {
				int32_t Int32;
				int64_t Int64;
				float Float;
				double Double;
				char* String;
				wchar_t* WString;
				void* Object;
			};
			int StringLength;
			int field_1C;
		};

		using ValuePathMakeNameRefProc = int (*)(IggyValuePath* path, IggyValuePath* parent, char const* name);
		using ValuePathMakeArrayRefProc = int (*)(IggyValuePath* path, IggyValuePath* parent, int index, void* iggy);
		using ValuePathSetArrayIndexProc = void (*)(IggyValuePath* path, int index);

		using ValueGetTypeProc = int (*)(IggyValuePath const* path, void* nameRef, char const* name, DataType* type);
		using ValueGetArrayLengthProc = int (*)(IggyValuePath const* path, void* nameRef, char const* name, uint32_t* result);

		using ValueGetBooleanProc = int (*)(IggyValuePath const* path, void* nameRef, char const* name, uint32_t* result);
		using ValueGetF64Proc = int (*)(IggyValuePath const* path, void* nameRef, char const* name, double* result);
		using ValueGetStringUTF8Proc = int (*)(IggyValuePath const* path, void* nameRef, char const* name, int maxLength, char* result, int* resultLength);

		using ValueSetBooleanProc = int (*)(IggyValuePath const* path, void* nameRef, char const* name, uint32_t value);
		using ValueSetF64Proc = int (*)(IggyValuePath const* path, void* nameRef, char const* name, double value);
		using ValueSetStringUTF8Proc = int (*)(IggyValuePath const* path, void* nameRef, char const* name, char const* value, int length);

		using PlayerCreateFastNameUTF8 = void* (*)(void* player, char const* name, int length);
		using PlayerCallMethod = int (*)(void* player, IggyDataValue* retval, IggyValuePath const* objectPath, void* methodName, int numArgs, IggyDataValue const* args);

		struct FlashObject : ProtectedGameObject<FlashObject>
		{
			virtual void Destroy() = 0;
			virtual void SetX() = 0;
			virtual void SetY() = 0;
			virtual void SetScaleX() = 0;
			virtual void SetScaleY() = 0;
			virtual void SetRotation() = 0;
			virtual void SetAlpha() = 0;
			virtual void SetWidth() = 0;
			virtual void SetHeight() = 0;
			virtual void SetVisible() = 0;
			virtual void SetValue(char const* path, InvokeDataValue const& value, int arrayIndex = -1) = 0;
			virtual unsigned GetX() = 0;
			virtual unsigned GetY() = 0;
			virtual unsigned GetScaleX() = 0;
			virtual unsigned GetScaleY() = 0;
			virtual float GetRotation() = 0;
			virtual float GetAlpha() = 0;
			virtual unsigned GetWidth() = 0;
			virtual unsigned GetHeight() = 0;
			virtual bool GetVisible() = 0;
			virtual bool GetValue(char const* path, DataType desiredType, InvokeDataValue& value, int arrayIndex = -1) = 0;

			IggyValuePath* IggyValue;
			void* ValuePathRef2;
			void* StrX;
			void* StrY;
			void* StrScaleX;
			void* StrScaleY;
			void* StrRotation;
			void* StrAlpha;
			void* StrWidth;
			void* StrHeight;
			void* StrVisible;

			bool GetValueWorkaround(char const* path, DataType desiredType, InvokeDataValue& value, int arrayIndex = -1);
		};




		struct FlashInvoke
		{
			__int64 field_0;
			int field_8;
			__int64 field_10;
			__int64 field_18;
			void* IggyDataValue;
			__int64 field_28;
		};


		struct FlashInputEvent
		{
			uint64_t Unknown;
			char const* EventName;
		};


		struct FlashInvokeDefinition
		{
			void* IggyName;
			char const* Name;
		};

		struct FlashPlayerProperties
		{
			int Width;
			int Height;
			int ints[4];
			long longs[3];
		};

		struct FlashPlayer : ProtectedGameObject<FlashPlayer>
		{
			struct VMT
			{
				typedef bool (*Invoke6Proc)(FlashPlayer* self, int64_t invokeEnum, InvokeDataValue* a3, InvokeDataValue* a4, InvokeDataValue* a5, InvokeDataValue* a6, InvokeDataValue* a7, InvokeDataValue* a8);
				typedef bool (*Invoke5Proc)(FlashPlayer* self, int64_t invokeEnum, InvokeDataValue* a3, InvokeDataValue* a4, InvokeDataValue* a5, InvokeDataValue* a6, InvokeDataValue* a7);
				typedef bool (*Invoke4Proc)(FlashPlayer* self, int64_t invokeEnum, InvokeDataValue* a3, InvokeDataValue* a4, InvokeDataValue* a5, InvokeDataValue* a6);
				typedef bool (*Invoke3Proc)(FlashPlayer* self, int64_t invokeEnum, InvokeDataValue* a3, InvokeDataValue* a4, InvokeDataValue* a5);
				typedef bool (*Invoke2Proc)(FlashPlayer* self, int64_t invokeEnum, InvokeDataValue* a3, InvokeDataValue* a4);
				typedef bool (*Invoke1Proc)(FlashPlayer* self, int64_t invokeEnum, InvokeDataValue* a3);
				typedef bool (*Invoke0Proc)(FlashPlayer* self, int64_t invokeEnum);
				typedef bool (*InvokeArgsProc)(FlashPlayer* self, int64_t invokeEnum, InvokeDataValue* args, unsigned numArgs);
				typedef bool (*GetFlashMoviePropertiesProc)(FlashPlayer* self, ig::FlashPlayerProperties* out);

				void (*Destroy)(FlashPlayer* self);
				/*void (*OnWTCompletion)(FlashPlayer* self);
				void (*OnWTCanceled)(FlashPlayer* self);
				void (*ExecuteWTKernel)(FlashPlayer* self);
				int (*GetHeuristic)(FlashPlayer* self);*/
				/*void (*OnInputEvent)(FlashPlayer* self);*/
				void (*FireEvent)(FlashPlayer* self);
				uint16_t* (*OnInputEventText)(FlashPlayer* self, uint16_t* retval, FlashInputEvent* event);
				/*void (*SetModifierStates)(FlashPlayer* self, bool, bool, bool);*/
				void (*Unknown)(FlashPlayer* self);
				Invoke6Proc Invoke6;
				Invoke5Proc Invoke5;
				Invoke4Proc Invoke4;
				Invoke3Proc Invoke3;
				Invoke2Proc Invoke2;
				Invoke1Proc Invoke1;
				Invoke0Proc Invoke0;
				InvokeArgsProc InvokeArgs;
				bool (*HasFreeStringScratchArea)(FlashPlayer* self, uint64_t size);
				bool (*HasFreeWStringScratchArea)(FlashPlayer* self, uint64_t size);
				void (*Unknown1)(FlashPlayer* self);
				void (*Unknown2)(FlashPlayer* self);
				void (*Unknown3)(FlashPlayer* self);
				//bool (*HasInvokes)(FlashPlayer* self);
				//void (*field_A8)(FlashPlayer* self);
				//void (*InvokeByName)(FlashPlayer* self, char const* name, uint64_t unknown, InvokeDataValue* arg);
				void (*SetRenderRectangle)(FlashPlayer* self);
				void (*FireResolutionEvents)(FlashPlayer* self);
				void (*SetSize)(FlashPlayer* self, glm::ivec2 const& size);
				void (*GetDisplaySize)(FlashPlayer* self); // TODO return type
				//int* (*GetSize)(FlashPlayer* self);
				//void (*Unknown)(FlashPlayer* self);
				void (*Render)(FlashPlayer* self);
				void (*field_E0)(FlashPlayer* self);
				void (*field_E8)(FlashPlayer* self);
				GetFlashMoviePropertiesProc GetFlashMovieProperties;
				void (*GotoFrame)(FlashPlayer* self, uint64_t frame);
				void (*ForceGotoFrame)(FlashPlayer* self, uint64_t frame);
				FlashObject* (*CreateFlashObject)(FlashPlayer* self, char const* path, int arrayIndex);
				ig::FlashObject* (*GetRootObject)(FlashPlayer* self);
				void (*SetFrameRate)(FlashPlayer* self, uint32_t frameRate);
				void (*SetPath)(FlashPlayer* self, Path* path);
				void (*OnFunctionCalled)(FlashPlayer* self);
				void (*Tick)(FlashPlayer* self);
				void (*field_138)(FlashPlayer* self);
				void (*Init)(FlashPlayer* self);
				void (*OnEventTerminate)(FlashPlayer* self);
				void (*Activate)(FlashPlayer* self);
				void (*Deactivate)(FlashPlayer* self);
				void (*GainFocus)(FlashPlayer* self);
				void (*LoseFocus)(FlashPlayer* self);
				void (*CopyEditableValue)(FlashPlayer* self);
				void (*PasteEditableValue)(FlashPlayer* self);
				void (*Cut)(FlashPlayer* self);
				void (*SetFlashMousePosition)(FlashPlayer* self);
				void (*SetupEventMapping)(FlashPlayer* self);
				void (*SetStageSize)(FlashPlayer* self);
				void (*AddInvokeName)(FlashPlayer* self, int index, char const* name);
				void (*field_1A8)(FlashPlayer* self);
				void (*LoadTextureFile)(FlashPlayer* self, Path* path);
				void (*EnableMouseProcessing)(FlashPlayer* self);
			};

			virtual void Destroy() = 0;
			/*virtual void OnWTCompletion() = 0;
			virtual void OnWTCanceled() = 0;*/
			/*virtual void ExecuteWTKernel() = 0;
			virtual int GetHeuristic() = 0;*/
			/*virtual void OnInputEvent() = 0;*/
			virtual void FireEvent() = 0;
			virtual uint16_t* OnInputEventText(uint16_t* retval, FlashInputEvent* event) = 0;
			/*virtual void SetModifierStates(bool, bool, bool) = 0;*/
			virtual void Unknown() = 0;
			virtual bool Invoke6(int64_t invokeEnum, InvokeDataValue* a3, InvokeDataValue* a4, InvokeDataValue* a5, InvokeDataValue* a6, InvokeDataValue* a7, InvokeDataValue* a8) = 0;
			virtual bool Invoke5(int64_t invokeEnum, InvokeDataValue* a3, InvokeDataValue* a4, InvokeDataValue* a5, InvokeDataValue* a6, InvokeDataValue* a7) = 0;
			virtual bool Invoke4(int64_t invokeEnum, InvokeDataValue* a3, InvokeDataValue* a4, InvokeDataValue* a5, InvokeDataValue* a6) = 0;
			virtual bool Invoke3(int64_t invokeEnum, InvokeDataValue* a3, InvokeDataValue* a4, InvokeDataValue* a5) = 0;
			virtual bool Invoke2(int64_t invokeEnum, InvokeDataValue* a3, InvokeDataValue* a4) = 0;
			virtual bool Invoke1(int64_t invokeEnum, InvokeDataValue* a3) = 0;
			virtual bool Invoke0(int64_t invokeEnum) = 0;
			virtual bool InvokeArgs(int64_t invokeEnum, InvokeDataValue* args, unsigned numArgs) = 0;

			virtual bool HasFreeStringScratchArea(uint64_t size) = 0;
			virtual bool HasFreeWStringScratchArea(uint64_t size) = 0;
			virtual bool HasInvokes() = 0;
			virtual void field_A8() = 0;
			virtual void InvokeByName(char const* name, uint64_t unknown, InvokeDataValue* arg) = 0;

			virtual void SetRenderRectangle(glm::ivec2 const& topLeft, glm::ivec2 const& size, uint8_t type) = 0;
			//virtual void SetPosition(glm::ivec2 const& position) = 0;
			virtual void FireResolutionEvents(int* resolution) = 0;
			//virtual glm::ivec2 const& GetPosition() = 0;
			virtual void GetSomething() = 0;
			virtual void GetDisplaySize() = 0;
			virtual void Render() = 0;
			virtual void field_E0() = 0;
			virtual void field_E8() = 0;
			virtual void GetFlashMovieProperties() = 0;
			virtual void GotoFrame(uint64_t frame) = 0;
			virtual void ForceGotoFrame(uint64_t frame) = 0;

			virtual FlashObject* CreateFlashObject(char const* path, int arrayIndex) = 0;
			virtual ig::FlashObject* GetRootObject() = 0;
			virtual void SetFrameRate(uint32_t frameRate) = 0;
			virtual void SetPath(Path* path) = 0;
			//virtual void OnFunctionCalled() = 0;
			virtual void Tick() = 0;

			virtual void field_138() = 0;
			virtual void Init() = 0;

			virtual void OnEventTerminate() = 0;
			virtual void UpdateMousePosition() = 0;

			virtual void Activate() = 0; // TODO
			virtual void Deactivate() = 0; // TODO

			virtual void GainFocus() = 0;
			virtual void SetMousePosition() = 0;

			/*virtual void CopyEditableValue() = 0;
			virtual void PasteEditableValue() = 0;
			virtual void Cut() = 0;
			virtual void SetFlashMousePosition() = 0;*/
			virtual void SetupEventMapping() = 0;
			virtual void SetStageSize(unsigned width, unsigned height) = 0;
			virtual void AddInvokeName(int index, char const* name) = 0;
			virtual void field_1A8() = 0;
			virtual void LoadTextureFile(Path* path) = 0;
			virtual void EnableMouseProcessing() = 0;

			undefined unknown[0x20];
			ig::FlashObject* FlashRoot; // 0x28
			ig::IggyValuePath* Parent;
			undefined unknown2[8];
			CompactSet<ig::FlashInvokeName> Invokes;

//			__int64 field_8;
//			glm::ivec2 Position;
//			glm::ivec2 RenderRectangeleSize;
//			glm::ivec2 RenderRectangeleSize2;
//			__int16 field_28;
//			void* IggyPlayer;
//			IggyValuePath* IggyPlayerRootPath;
//			ObjectSet<FlashInvokeDefinition> Invokes;
//			int FlashInvokePool;
//			int field_64;
//#if !defined(OSI_EOCAPP)
//			char const* PoolName;
//#endif
//			/*CRITICAL_SECTION CriticalSection;*/
//			char Invoked_M;
//			char field_99;
//			ObjectSet<FlashInvoke*> QueuedInvokes;
//			ObjectSet<FlashInvoke*> Invokes2;
//			ObjectSet<InvokeDataValue> InvokeValues;
//			ObjectSet<FlashPlayer*> FlashPlayers;
//			__int64 field_120;
//			__int64 field_128;
//			ig::FlashObject* RootFlashObject;
//			RefMap<uint32_t, uint32_t> InputEvents;
//			ScratchBuffer* ScratchString1;
//			ScratchBuffer* ScratchStringW;
//			ScratchBuffer* ScratchString2;
//			Path Path;
//			__int64 field_188;
//			__int64 field_190;
		};

		struct IggyBinding
		{
			virtual ~IggyBinding() = 0;
			virtual void BeginRendering() = 0;
			virtual void EndRendering() = 0;
			virtual bool Init(void* gDrawContext) = 0;
			virtual void CleanupDeadFlashPlayers() = 0;
			virtual void StartFlashRenderFrame(void* d3d11Renderer) = 0;
			virtual void EndFlashRenderFrame(void* d3d11Renderer) = 0;
			virtual void Render(void* d3d11Renderer, void* unknown) = 0;
			virtual ComponentHandle* GetRenderTargetTextureHandle(ComponentHandle& handle) = 0;
			virtual void ResizeRenderTarget(void*, void*) = 0;
			virtual void LoadFlashMovieFromFile(Path const& path, uint32_t* scratchPoolSizes, uint32_t flags, uint32_t* invokePoolSize, uint32_t fontCacheBitmapWidth, uint32_t fontCacheBitmapHeight) = 0;
			virtual void LoadFlashMovieFromMemory(void* buf, uint64_t bufSize, uint32_t* scratchPoolSizes, uint32_t flags, uint32_t* invokePoolSize, uint32_t fontCacheBitmapWidth, uint32_t fontCacheBitmapHeight) = 0;
			virtual int64_t LoadLibraryFromFile(char const* libraryName, Path const& flashPath, Path const& resourcePath) = 0;
			virtual int64_t LoadLibraryFromMemory(char const* libraryName, void* flashBuf, uint64_t flashSize, void* resourceBuf, uint64_t resourceSize) = 0;
			virtual void DestroyLibrary(int64_t handle) = 0;
			virtual void DestroyAllLibraries() = 0;
			virtual bool InstallFont(char const* name, Path const& path, uint8_t flags) = 0;
			virtual bool SetFallbackFont(char const* name, uint8_t flags) = 0;
			virtual bool LoadTTFFontLibrary(Path const& path) = 0;
			virtual void SetSomething(uint64_t unknown) = 0;
			virtual void* GetFlashWorkerThread() = 0;
			virtual void RemoveError(int errorCode) = 0;
			virtual void AddError(int errorCode) = 0;

			/*CRITICAL_SECTION CriticalSection;*/
			void* VMT_FileFormatIO;
			void* SomeContextPtr;
			ObjectSet<FlashPlayer*> FlashPlayers;
			ObjectSet<void*> TextureSubstitutionDestroyCallbacks;
			void* FlashWorkerThread;
			std::array<int32_t, 15> Libraries;
			glm::ivec4 RenderFrameViewport;
			bool Initialized;
			bool IsRendering;
			bool FlashRenderFrameStarted;
			ComponentHandle RenderTargetTextureHandle;
			uint64_t field_E0;
			void* GDraw;
			ObjectSet<Path> FontPaths;
			ObjectSet<STDString> FontNames;
			ObjectSet<void*> Fonts;
			ObjectSet<uint32_t> FlashErrorValues;
		};

		typedef void (*TraceCallbackProc)(void*, void*, char const*);
		typedef void (*WarningCallbackProc)(void*, void*, int, char const*);
		typedef void (*SetWarningCallbackProc)(WarningCallbackProc, void*);
		typedef void (*SetTraceCallbackUTF8Proc)(TraceCallbackProc, void*);
	}

	BY_VAL(ig::InvokeDataValue);

	struct UIObject : Noncopyable<UIObject>
	{
		/*static constexpr auto ObjectTypeIndex = ObjectHandleType::UIObject;
		static constexpr auto ProtectedFlags = UIObjectFlags::OF_Load
			| UIObjectFlags::OF_Loaded
			| UIObjectFlags::OF_RequestDelete
			| UIObjectFlags::OF_DeleteOnChildDestroy;*/

		typedef void(*OnFunctionCalledProc)(UIObject* self, const char*, unsigned int, ig::InvokeDataValue*);
		typedef void(*CustomDrawCallbackProc)(UIObject* self, void*);
		typedef float (GetUIScaleMultiplierProc)(UIObject* self);
		typedef void (RaiseFlagProc)(UIObject* self, UIObjectFlags flags);

		enum class TypeID : int
		{
			ActionProgression = 0,
			OptionsSettings0 = 1,
			Book = 2,
			Overhead = 4,
			ChatLog = 5,
			CombatLog = 6,
			CombatTurn = 7,
			ContainerInventory = 8,
			ContextMenu = 9,
			ControllerContextMenu = 10,
			OptionsInput = 11,
			Dialog = 12,
			DummyOverhead = 13,
			Equipment = 14,
			Fade = 15,
			OptionsSettings_Gameplay = 16,
			MsgBox = 17,
			InGameMenu = 18,
			Inventory = 20,
			ItemSplitter = 21,
			Journal = 22,
			LoadingScreen = 23,
			ServerList = 24,
			MainMenu = 26,
			MessageBox = 27,
			Minimap = 28,
			MouseIcon = 29,
			Subtitles = 30,
			MultiplayerInGameMenu = 31,
			ControllerInGameMenu = 32,
			TextDisplay = 32,
			OptionsSettings1 = 33,
			Pickpocket = 35,
			PlayerPortraits = 36,
			SaveLoad = 37,
			SkillBar = 38,
			Skills = 39,
			Stats = 40,
			TargetInfo = 41,
			TextDisplay_2 = 42,
			Tooltip = 43,
			OptionsSettings2 = 44,
			Trade = 45,
			Waypoints = 46,
			WorldTooltip = 47,
			Mods = 48,
			UserProfile = 51,
			CharacterAssign = 52,
			Credits = 53,
			ItemStackCombine = 55,
			TutorialBox = 56,
			TutorialLog = 57,
			ControllerBottomBar = 62,
			ControllerMinimap = 63,
			StatsPanel_c = 67,
			ControllerEquipmentPanel = 68,
			CharacterCreation = 76,
			ControllerJournal = 77,
			ControllerMainMenu = 79,
			Trade_c = 80,
			SaveLoad_c = 81,
			ControllerMessageBox = 82,
			MsgBox_c = 83,
			GameMenu_c = 84,
			Waypoints_c = 85,
			ControllerSortBy = 86,
			Installation = 87,
			ControllerPartyManagement = 89,
			ControllerPanelSelect = 90,
			ControllerItemAction = 93,
			ControllerCharacterAssign = 99,
			TutorialBox_c = 102,
			ControllerObjectContextMenu = 104,
			Saving = 105,
			FullscreenHUD = 106,
			KeyboardCraft = 108,
			Mods_c = 109,
			Examine = 110
		};

		enum class UIFlags
		{
			Loaded = 0x1,
			RequestDelete_m = 0x4,
			Visible = 0x8,
			Activated = 0x10,
		};

		struct VMT
		{
			OnFunctionCalledProc OnFunctionCalled;
			CustomDrawCallbackProc CustomDrawCallback;
			void (*Destroy)(UIObject* self, bool);
			void(*SetHandle)(UIObject* self, ComponentHandle*);
			ComponentHandle* (*GetHandle)(UIObject* self, ComponentHandle*);
			void(*ReleaseChildMenuHandle)(UIObject* self);
			void(*RequestDelete)(UIObject* self);
			void(*SetOwnerPlayerId)(UIObject* self, uint64_t);
			void(*SetPos)(UIObject* self, glm::ivec2 const&);
			//void(*KeepWithin)(UIObject* self, int, int);
			void(*Show)(UIObject* self);
			void(*Hide)(UIObject* self);
			const char* (*GetDebugName)(UIObject* self);
			bool(*IsControllerUI)(UIObject* self);
			void(*Init)(UIObject* self);
			//void(*InitAPI)(UIObject* self);
			void(*Update)(UIObject* self, float);
			//void(*PostUpdate)(UIObject* self, float);
			void(*Render)(UIObject* self, void*, void*);
			void(*RegisterInvokeNames)(UIObject* self);
			void(*Resize)(UIObject* self);
			void* (*OnInputEvent)(UIObject* self, void*, void*);
			//uint8_t* (*SendEventToFlash)(UIObject* self, uint8_t* a2, void* a3, unsigned int a4);
			void* (*OnInputEventText)(UIObject* self, void*, void*);
			uint16_t* (*OnUnlinkedInput)(UIObject* self, uint16_t*, uint32_t, uint16_t);
			//void(*SetModifierStates)(UIObject* self, bool, bool, bool, bool);
			bool(*OnAPIPreResetDevice)(UIObject* self, void*);
			bool(*OnAPIPostResetDevice)(UIObject* self, void*);
			void(*OnControllerModeChanged)(UIObject* self);
			void(*OnPlayerDisconnect)(UIObject* self, int);
			void(*ReleaseRenderData)(UIObject* self);
			//void(*PrepareRenderData)(UIObject* self);
			//void(*DoPrepareRenderData)(UIObject* self);
			void(*Activate)(UIObject* self);
			void(*Deactivate)(UIObject* self);
			//void(*LoseFocus)(UIObject* self);
			int64_t(*GetBitmapHeight)(UIObject* self);
			int64_t(*GetBitmapWidth)(UIObject* self);
			void* (*GetCharacter)(UIObject* self);
			bool (*SetPlayerHandle)(UIObject* self, ComponentHandle* handle);
			ComponentHandle* (*GetPlayerHandle)(UIObject* self, ComponentHandle* handle);
			bool (*Unknown1)(UIObject* self);
			void(*Unknown2)(UIObject* self);
			void* (*Unknown3)(UIObject* self);
			//void (*Unknown4)(UIObject* self, void* a1);
		};

		virtual void OnFunctionCalled(const char* a1, unsigned int a2, ig::InvokeDataValue* a3);
		virtual void CustomDrawCallback(void* a1);
		virtual void Destroy(bool a1);
		virtual void SetHandle(ComponentHandle* a1);
		virtual ComponentHandle* GetHandle(ComponentHandle*);
		virtual void RequestDelete();
		virtual void SetOwnerPlayerId(uint64_t a1);
		virtual void SetPos(glm::ivec2 const& a1);
		virtual void KeepWithin(int a1, int a2);
		virtual void Show();
		virtual void Hide();
		virtual const char* GetDebugName();
		virtual bool IsControllerUI();
		virtual void Init();
		virtual void InitAPI();
		virtual void Update(float a1);
		virtual void PostUpdate(float a1);
		virtual void Render(void* a1, void* a2);
		virtual void RegisterInvokeNames();
		virtual void Resize();
		virtual void* OnInputEvent(void* a1, void* a2);
		virtual uint8_t* SendEventToFlash(uint8_t* a2, void* a3, unsigned int a4);
		virtual void* OnInputEventText(void* a1, void* a2);
		virtual uint16_t* OnUnlinkedInput(uint16_t* a1, uint32_t a2, uint16_t a3);
		virtual void SetModifierStates(bool a1, bool a2, bool a3, bool a4);
		virtual bool OnAPIPreResetDevice(void*);
		virtual bool OnAPIPostResetDevice(void*);
		virtual void OnControllerModeChanged();
		virtual void OnPlaeyerDisconnect(int a1);
		virtual void ReleaseRenderData();
		virtual void PrepareRenderData();
		virtual void DoPrepareRenderData();
		virtual void Activate();
		virtual void Deactivate();
		virtual void LoseFocus();
		virtual int64_t GetBitmapHeight();
		virtual int64_t GetBitmapWidth();
		virtual void* GetCharacter();
		virtual bool SetPlayerHandle(ComponentHandle* handle);
		virtual ComponentHandle* GetPlayerHandle(ComponentHandle* handle);
		virtual bool Unknown1();
		virtual void Unknown2();
		virtual void* Unknown3();
		// Not in DOS1?
		/*virtual void Unknown4(void* a1);
		virtual bool Visit(ObjectVisitor* visitor);*/

		char unknown0[12];

		int Flags;
		ig::FlashPlayer* FlashPlayer;
		Path Path;
		bool isDragging_m;
		ComponentHandle ChildUIHandle;
		ComponentHandle ParentUIHandle;

		char unknown1[20];

		uint32_t Layer;
		uint32_t RenderOrder;
		int MovieLayout;

		float McSizeWidth;
		float McSizeHeight;
		float FlashMovieSizeWidth;
		float FlashMovieSizeHeight;

		char unknown2[4];

		float UIScaleMultiplier;
		char unknown3[4];
		FixedString AnchorID;
		char unknown4[8];
		ObjectHandle SomeHandle;
		uint32_t TypeId;
		short OwnerPlayerID;

		char unknown5[6];
		bool unknown6;
		bool unknown7;
		bool HasTooltip_m;
		char unknown8;
		/*int BufferSizes;
		int field_C;
		int field_10;
		UIObjectFlags Flags;
		ig::FlashPlayer* FlashPlayer;
		Path Path;
		bool IsDragging;
		glm::vec2 FlashSize;
		glm::vec2 MovieClipSize;
		glm::vec2 FlashMovieSize;
		glm::ivec2 SysPanelPosition;
		glm::vec2 SysPanelSize;
		float Left;
		float Top;
		float Right;
		glm::vec2 MinSize;
		float UIScale;
		float CustomScale;
		FixedString AnchorObjectName;
		STDString AnchorId;
		STDString AnchorTarget;
		STDString AnchorPos;
		STDString AnchorTPos;
		bool UIScaling;
		bool IsUIMoving;
		bool IsDragging2;
		bool IsMoving2;
		bool RenderDataPrepared;
		bool InputFocused;
		bool HasAnchorPos;
		ComponentHandle UIObjectHandle;
		int Type;
		PlayerId PlayerId;*/

		void RaiseFlags(UIObjectFlags flags);
		void ClearFlags(UIObjectFlags flags);

		UIObjectFlags LuaGetFlags();
		void LuaSetFlags(UIObjectFlags flags);
		bool LuaHasFlag(UIObjectFlags flag);
		void LuaSetFlag(UIObjectFlags flag, bool set);

		void LuaSetPosition(int x, int y);
		std::optional<glm::ivec2> LuaGetPosition();
		void LuaShow();
		void LuaHide();
		bool LuaInvoke(lua_State* L, STDString const& method);
		void LuaGotoFrame(int frame, std::optional<bool> force);
		std::optional<ig::InvokeDataValue> GetValue(lua_State* L, STDString const& path, std::optional<STDString> typeName, std::optional<int> arrayIndex);
		void SetValue(STDString const& path, ig::InvokeDataValue const& value, std::optional<int> arrayIndex);
		ComponentHandle LuaGetHandle();
		std::optional<ComponentHandle> LuaGetPlayerHandle();
		int GetTypeId();
		/*UserReturn LuaGetRoot(lua_State* L);
		void LuaDestroy();*/
		void LuaExternalInterfaceCall(lua_State* L, STDString const& method);
		void CaptureExternalInterfaceCalls();
		void CaptureInvokes();
		void EnableCustomDraw();
		void SetCustomIcon(STDWString const& element, STDString const& icon, int width, int height, std::optional<STDString> materialGuid);
		void ClearCustomIcon(STDWString const& element);
		float GetUIScaleMultiplier();
		void SetMovieClipSize(float width, float height, std::optional<float> scale);
	};

	struct UIDialog : UIObject
	{
		enum Invokes
		{
			setDiscussionWaitingTextVisible = 1,
			setAnchorId,
			setTradeBtnTooltip,
			setDiscussionLabels,
			clearAll,
			skipDiscussionAnimation,
			chooseAnswer,
			addText,
			setWaitingText,
			addAnswerHolder,
			addKeywordAnswer,
			setTradeBtnVisible,
			setTradeBtnDisabled,
			setDialogIsDualDialog,
			addAnswersDone,
			showDiscussion,
			hideDiscussion,
			setPlayerWonText,
			setDiscussionPlayersPoints,
			discussionShowBattle,
			enableRPSButtons,
			disableRPSButtons,
			setTalkingNPCIcon,
			setStopListenBtnVisible,
			setAlternativeScrollMode,
			setDiscussionPlayer,
			hideDialog,
			showDialog,
			clearAnswers,

			pipSetAlwaysAutoScroll,
			pipSetAutoStopListening,
		};
	};

	struct UIWorldTooltip : UIObject
	{
		enum Invokes
		{
			setWindow = 1,
			updateTooltips = 2, // Updates via arrays.
			clearAll = 3,
			setControllerMode = 4,
		};
		undefined unknown[31];
		bool HasHoveredItem;
		undefined unknown2[4];
		ComponentHandle HoveredItemHandle;
	};

	struct UIControlsMenu : UIObject
	{
		enum Invokes
		{
			setMenuTexts = 0, // This UI actually doesn't call the base RegisterInvokeNames() method, curiously.
			setButtonText,
			removeContent,
			addTab,
			selectTab,
			addEntry,
			setInput,
			closeMenu,
			popupShow,
			popupHide,
			hideOverlay,
			changeOverlayText,
			setButtonDisable,
			enableSaveButton,
			disableSaveButton,
			initDone,
			addTitle,
			setTitle,

			pipHideSecondInput,
		};
	};

	struct UIGameOptionsMenu : UIObject
	{
		enum Invokes
		{
			setTopTitle = 1,
			setTitle,
			setButtonText,
			addMenuLabel,
			addMenuDropDown,
			addMenuDropDownEntry,
			selectMenuDropDownEntry,
			setMenuDropDownEnabled,
			setMenuDropDownDisabledTooltip,
			addMenuCheckbox,
			setMenuCheckbox,
			addMenuSlider,
			addCheckBoxOptions,
			addBtnHint,
			clearBtnHints,
			addingDone,
		};
	};

	struct UIControllerEquipmentPanel : UIObject
	{
	};

	struct UIContextMenu : UIObject
	{
		enum Invokes
		{
			clearButtons = 1,
			close,
			open,
			setTitle,
			addButton,
			updateButtons,
		};
	};

	struct ecl::PickingHelper
	{
		char unknown1[104];
		ComponentHandle CurrentCharacterHandle;
		char unknown2[4];
		ComponentHandle CurrentItemHandle;
		ComponentHandle CurrentObjectHandle;
		undefined unknown3[9];
		char Flags;
	};

	struct ecl::EocUIControl
	{
		// TODO
	};

	struct UIKeyboardBottomBar : UIObject
	{
		enum class Invokes : int
		{
			setAnchor,
			setHPColour,
			setActiveAp,
			setmaxAp,
			setBonusAp,
			setAvailableAp,
			setGreyAp,
			setArmourBar,
			setArmourBarColour,
			setExp,
			setHealth,
			setSlotCooldown,
			updateSlots,
			setSlowPreviewEnabled,
			setSlotEnabled,
			setAllSlotsEnabled,
			showActiveSkill,
			clearAll,
			updateSlotData,
			setBarSelectorVisible,
			setSneakBtnState,
			setStanceBtnState,
			setBtnDisabled,
			setBtnTooltip,
			setBarSelectorText,

			// PIP
			pipSetExtendedMode,
			pipSetDraggingLocked,
		};
		/*undefined field1_0xb4;
		undefined field2_0xb5;
		undefined field3_0xb6;
		undefined field4_0xb7;*/
		undefined field5_0xb8;
		undefined field6_0xb9;
		undefined field7_0xba;
		undefined field8_0xbb;
		undefined field9_0xbc;
		undefined field10_0xbd;
		undefined field11_0xbe;
		undefined field12_0xbf;
		undefined field13_0xc0;
		undefined field14_0xc1;
		undefined field15_0xc2;
		undefined field16_0xc3;
		undefined field17_0xc4;
		undefined field18_0xc5;
		undefined field19_0xc6;
		undefined field20_0xc7;
		undefined field21_0xc8;
		undefined field22_0xc9;
		undefined field23_0xca;
		undefined field24_0xcb;
		undefined field25_0xcc;
		undefined field26_0xcd;
		undefined field27_0xce;
		undefined field28_0xcf;
		undefined field29_0xd0;
		undefined field30_0xd1;
		undefined field31_0xd2;
		undefined field32_0xd3;
		undefined field33_0xd4;
		undefined field34_0xd5;
		undefined field35_0xd6;
		undefined field36_0xd7;
		int CurrentMaxAP;
		undefined field38_0xdc;
		undefined field39_0xdd;
		undefined field40_0xde;
		undefined field41_0xdf;
		undefined field42_0xe0;
		undefined field43_0xe1;
		undefined field44_0xe2;
		undefined field45_0xe3;
		int SomethingAPRelated;
		undefined field47_0xe8;
		undefined field48_0xe9;
		undefined field49_0xea;
		undefined field50_0xeb;
		undefined field51_0xec;
		undefined field52_0xed;
		undefined field53_0xee;
		undefined field54_0xef;
		undefined field55_0xf0;
		undefined field56_0xf1;
		undefined field57_0xf2;
		undefined field58_0xf3;
		undefined field59_0xf4;
		undefined field60_0xf5;
		undefined field61_0xf6;
		undefined field62_0xf7;
		undefined field63_0xf8;
		undefined field64_0xf9;
		undefined field65_0xfa;
		undefined field66_0xfb;
		undefined field67_0xfc;
		undefined field68_0xfd;
		undefined field69_0xfe;
		undefined field70_0xff;
		undefined field71_0x100;
		undefined field72_0x101;
		undefined field73_0x102;
		undefined field74_0x103;
		undefined field75_0x104;
		undefined field76_0x105;
		undefined field77_0x106;
		undefined field78_0x107;
		undefined field79_0x108;
		undefined field80_0x109;
		undefined field81_0x10a;
		undefined field82_0x10b;
		undefined field83_0x10c;
		undefined field84_0x10d;
		undefined field85_0x10e;
		undefined field86_0x10f;
		undefined field87_0x110;
		char CurrentRow;
		undefined1 HotbarFlags_m;
		undefined field90_0x113;
		undefined field91_0x114;
		undefined field92_0x115;
		undefined field93_0x116;
		undefined field94_0x117;
		undefined field95_0x118;
		undefined field96_0x119;
		undefined field97_0x11a;
		undefined field98_0x11b;
		undefined field99_0x11c;
		undefined field100_0x11d;
		undefined field101_0x11e;
		undefined field102_0x11f;
		undefined field103_0x120;
		undefined field104_0x121;
		undefined field105_0x122;
		undefined field106_0x123;
		undefined field107_0x124;
		undefined field108_0x125;
		undefined field109_0x126;
		undefined field110_0x127;
		undefined field111_0x128;
		undefined field112_0x129;
		undefined field113_0x12a;
		undefined field114_0x12b;
		undefined field115_0x12c;
		undefined field116_0x12d;
		undefined field117_0x12e;
		undefined field118_0x12f;
		undefined1 SlotIconsDrawStruct_m;
		undefined field120_0x131;
		undefined field121_0x132;
		undefined field122_0x133;
		undefined field123_0x134;
		undefined field124_0x135;
		undefined field125_0x136;
		undefined field126_0x137;
		undefined field127_0x138;
		undefined field128_0x139;
		undefined field129_0x13a;
		undefined field130_0x13b;
		undefined field131_0x13c;
		undefined field132_0x13d;
		undefined field133_0x13e;
		undefined field134_0x13f;
		undefined field135_0x140;
		undefined field136_0x141;
		undefined field137_0x142;
		undefined field138_0x143;
		undefined field139_0x144;
		undefined field140_0x145;
		undefined field141_0x146;
		undefined field142_0x147;
		undefined field143_0x148;
		undefined field144_0x149;
		undefined field145_0x14a;
		undefined field146_0x14b;
		undefined field147_0x14c;
		undefined field148_0x14d;
		undefined field149_0x14e;
		undefined field150_0x14f;
		undefined field151_0x150;
		undefined field152_0x151;
		undefined field153_0x152;
		undefined field154_0x153;
		undefined field155_0x154;
		undefined field156_0x155;
		undefined field157_0x156;
		undefined field158_0x157;
		undefined field159_0x158;
		undefined field160_0x159;
		undefined field161_0x15a;
		undefined field162_0x15b;
		undefined field163_0x15c;
		undefined field164_0x15d;
		undefined field165_0x15e;
		undefined field166_0x15f;
		uint field167_0x160;
		undefined field168_0x164;
		undefined field169_0x165;
		undefined field170_0x166;
		undefined field171_0x167;
		undefined field172_0x168;
		undefined field173_0x169;
		undefined field174_0x16a;
		undefined field175_0x16b;
		undefined field176_0x16c;
		undefined field177_0x16d;
		undefined field178_0x16e;
		undefined field179_0x16f;
		void* SlotDataSet;
		undefined field181_0x178;
		undefined field182_0x179;
		undefined field183_0x17a;
		undefined field184_0x17b;
		uint SlotDataSetcount;
		undefined field186_0x180;
		undefined field187_0x181;
		undefined field188_0x182;
		undefined field189_0x183;
		undefined field190_0x184;
		undefined field191_0x185;
		undefined field192_0x186;
		undefined field193_0x187;
		undefined field194_0x188;
		undefined field195_0x189;
		undefined field196_0x18a;
		undefined field197_0x18b;
		undefined field198_0x18c;
		undefined field199_0x18d;
		undefined field200_0x18e;
		undefined field201_0x18f;
		undefined1 SlotIconDrawStruct_m;
		undefined field203_0x191;
		undefined field204_0x192;
		undefined field205_0x193;
		undefined field206_0x194;
		undefined field207_0x195;
		undefined field208_0x196;
		undefined field209_0x197;
		undefined field210_0x198;
		undefined field211_0x199;
		undefined field212_0x19a;
		undefined field213_0x19b;
		int field214_0x19c;
		undefined field215_0x1a0;
		undefined field216_0x1a1;
		undefined field217_0x1a2;
		undefined field218_0x1a3;
		undefined field219_0x1a4;
		undefined field220_0x1a5;
		undefined field221_0x1a6;
		undefined field222_0x1a7;
		int field223_0x1a8;
		int LastHoveredSkillAPCost;
		undefined field225_0x1b0;
		undefined field226_0x1b1;
		undefined field227_0x1b2;
		undefined field228_0x1b3;
		int CurrentHoveredSlotIndex;
		undefined field230_0x1b8;
		undefined field231_0x1b9;
		undefined field232_0x1ba;
		undefined field233_0x1bb;
		char SomeFlags;
		undefined field235_0x1bd;
		undefined field236_0x1be;
		undefined field237_0x1bf;
		undefined field238_0x1c0;
		undefined field239_0x1c1;
		undefined field240_0x1c2;
		undefined field241_0x1c3;
		undefined field242_0x1c4;
		undefined field243_0x1c5;
		undefined field244_0x1c6;
		undefined field245_0x1c7;
		undefined field246_0x1c8;
		undefined field247_0x1c9;
		undefined field248_0x1ca;
		undefined field249_0x1cb;
		uint SomeSlotIndex;
		undefined1 SomeFlags2;
	};

	struct UIMainMenu : UIObject
	{
		enum class Invokes : int
		{
			setDebugText = 1,
			removeItems,
			setMenuTitle,
			addMenuButton,
			openMenu,
			setKickstarterBadgeVisible,
			addBtnHint,
			clearBtnHints,
			setSplashText,
			setSplashSingleText,
			openSplashScreen,
			hideSplashButtonHint,
			showSplashButtonHint,
			closeSplashScreen,
			setProfile,
			allowChange,
			setDifficulityMode, // Larian typo
			setCopyrightText,
			addLoadingElements,
			removeLoadingElements,
			clearLoadingElements,
			showLoadingIcon,
		};
	};

	struct UITargetInfo : UIObject
	{
		enum class Invokes : int
		{
			setHPColour = 1,
			hide,
			show,
			clearTweens,
			updateStatuses,
			setHPBars,
			setArmourBar,
			setArmourBarColour,
			setText,
			requestAnchorCombatTurn,
			requestAnchorScreen,

			// PIP
			pipSetHPBarText,
			pipSetResistances,
			pipSetInCombat,

		};
		char unknown1[64];
		ComponentHandle TargetObjectHandle;
		char unknown[18];
		bool ShowHP;
;	};

	struct CustomDrawStruct
	{
		using UIClearIcon = void(CustomDrawStruct* drawStruct);
		using UICreateIconMesh = void(FixedString const& iconName, CustomDrawStruct* drawStruct, int width, int height, FixedString const& materialGuid);

		void* VMT{ nullptr };
		RenderableObject* IconMesh{ nullptr };
		FixedString IconName;
		ComponentHandle CustomTextureHandle;
		uint8_t DrawEffect{ 0 };
	};


	struct UIObjectFunctor
	{
		UIObject* (*CreateProc)(Path*);
		Path Path;
	};



	/*struct UIObjectManager : public ComponentFactory<UIObject>*/
	struct UIObjectManager // TODO
	{
		struct PlayerState
		{
			uint32_t DragOffsetX;
			uint32_t DragOffsetY;
			ComponentHandle ActiveUIObjectHandle;
			ComponentHandle MovingUIObjectHandle;
			bool IsDragging;
			bool UIUnderMouseCursor;
		};

		using RegisterUIObjectCreatorProc = void(UIObjectManager* self, unsigned int index, UIObjectFunctor* creator);
		using CreateUIObjectProc = ComponentHandle* (UIObjectManager* self, ComponentHandle* handle, unsigned int layerIndex, unsigned int creatorId, unsigned int flags,
			uint64_t resourceFlags, short playerID);
		using GetUIObjectByTypeProc = UIObject * (UIObjectManager* self, uint32_t typeID);
		using DestroyUIObjectProc = void(UIObjectManager* self, ComponentHandle* handle);
		using GetInstanceProc = UIObjectManager * ();

		//void* InputEventListenerVMT;
		//void* InputDeviceListenerVMT;
		//void* APIEventListenerVMT;

		///*CRITICAL_SECTION CriticalSection3;*/
		//int64_t WorkerThreadJobVMT;
		//int64_t field_D0;
		//Map<uint32_t, UIObjectFunctor*> UIObjectCreators;
		char unknown[256];
		UIObject** UIObjects; // TODO Set
		char set_internals[4];
		unsigned int UIObjectsCount;
		undefined field262_0x110;
		undefined field263_0x111;
		undefined field264_0x112;
		undefined field265_0x113;
		undefined field266_0x114;
		undefined field267_0x115;
		undefined field268_0x116;
		undefined field269_0x117;
		short RequestedSortFlags_m;
		undefined1 RenderObjects;
		undefined field272_0x11b;
		float field273_0x11c;
		undefined field274_0x120;
		undefined field275_0x121;
		undefined field276_0x122;
		undefined field277_0x123;
		undefined field278_0x124;
		undefined field279_0x125;
		undefined field280_0x126;
		undefined field281_0x127;
		uint UIObjectsAmount_m;
		undefined field283_0x12c;
		undefined field284_0x12d;
		undefined field285_0x12e;
		undefined field286_0x12f;
		undefined field287_0x130;
		undefined field288_0x131;
		undefined field289_0x132;
		undefined field290_0x133;
		undefined field291_0x134;
		undefined field292_0x135;
		undefined field293_0x136;
		undefined field294_0x137;
		undefined1 SomePlayerField;
		undefined field296_0x139;
		undefined field297_0x13a;
		undefined field298_0x13b;
		undefined field299_0x13c;
		undefined field300_0x13d;
		undefined field301_0x13e;
		undefined field302_0x13f;
		ObjectHandle SomeHandle1;
		ObjectHandle SomeHandle2;
		undefined field305_0x148;
		undefined field306_0x149;
		undefined field307_0x14a;
		undefined field308_0x14b;
		undefined field309_0x14c;
		undefined field310_0x14d;
		undefined field311_0x14e;
		undefined field312_0x14f;
		undefined field313_0x150;
		undefined field314_0x151;
		undefined field315_0x152;
		undefined field316_0x153;
		ObjectHandle field317_0x154;
		ObjectHandle field318_0x158;
		undefined field319_0x15c;
		undefined field320_0x15d;
		undefined field321_0x15e;
		undefined field322_0x15f;
		undefined field323_0x160;
		undefined field324_0x161;
		undefined field325_0x162;
		undefined field326_0x163;
		undefined field327_0x164;
		undefined field328_0x165;
		undefined field329_0x166;
		undefined field330_0x167;
		ObjectHandle field331_0x168;
		ObjectHandle field332_0x16c;
		undefined field333_0x170;
		undefined field334_0x171;
		undefined field335_0x172;
		undefined field336_0x173;
		undefined field337_0x174;
		undefined field338_0x175;
		undefined field339_0x176;
		undefined field340_0x177;
		undefined field341_0x178;
		undefined field342_0x179;
		undefined field343_0x17a;
		undefined field344_0x17b;
		ObjectHandle field345_0x17c;
		ObjectHandle field346_0x180;
		short field347_0x184;
		undefined field348_0x186;
		undefined field349_0x187;
		undefined field350_0x188;
		undefined field351_0x189;
		undefined field352_0x18a;
		undefined field353_0x18b;
		undefined field354_0x18c;
		undefined field355_0x18d;
		undefined field356_0x18e;
		undefined field357_0x18f;
		undefined field358_0x190;
		undefined field359_0x191;
		undefined field360_0x192;
		undefined field361_0x193;
		undefined field362_0x194;
		undefined field363_0x195;
		undefined field364_0x196;
		undefined field365_0x197;
		undefined field366_0x198;
		undefined field367_0x199;
		undefined field368_0x19a;
		undefined field369_0x19b;
		undefined field370_0x19c;
		undefined field371_0x19d;
		undefined field372_0x19e;
		undefined field373_0x19f;
		UIObjectFlags AggregateModalFlags_m;
		//bool ShouldPrepareRenderData;
		//bool SortNeeded;
		//bool RefreshTopNeeded;
		//bool IsRenderingObjects;
		//bool AllowRawInput;
		//bool LastInteractedWithUIObject;
		//int UIDesignedHeight;
		//int UIDesignedWidth;
		//Map<ComponentHandle, uint64_t>* LastFrameDirtyFlags;
		//Map<ComponentHandle, uint64_t>* CharacterDirtyFlags;
		///*CRITICAL_SECTION DirtyFlagsCriticalSection;*/
		//std::array<PlayerState, 4> PlayerStates;
		///*CRITICAL_SECTION PrecachedDataCriticalSection;*/
		//RefMap<STDString, uint32_t> PrecachedUIData;
		//ComponentHandle LastUIObjectUnderCursor;
		//UIObjectFlags ModalAggregateFlags;
		//UIObjectFlags TextInputAggregateFlags;

		//UIObject* GetByType(int typeId) const;
	};

	struct DragController
	{
		void* VMT;
		PlayerId PlayerId;
	};

	struct DragDropManager
	{
		using GetInstanceProc = DragDropManager * ();
		using StartDragStringProc = bool(DragDropManager* self, PlayerId playerId, FixedString const& objectId, bool setupStartDrag, uint64_t mousePos);
		using StartDragHandleProc = bool(DragDropManager* self, PlayerId playerId, ComponentHandle const& objectHandle, bool setupStartDrag, uint64_t mousePos);
		using StopDragProc = bool(DragDropManager* self, PlayerId playerId);

		struct PlayerDragInfo
		{
			ComponentHandle DragObject;
			EntityHandle DragEgg;
			FixedString DragId;
			glm::vec2 MousePos;
			bool IsDragging;
			bool IsActive;
			__int64 field_28;
			ObjectSet<DragController*> Controllers;
		};

		RefMap<PlayerId, PlayerDragInfo> PlayerDragDrops;

		bool StopDragging(PlayerId playerId);
		bool StartDraggingName(PlayerId playerId, FixedString const& objectId);
		bool StartDraggingObject(PlayerId playerId, ComponentHandle const& objectHandle, std::optional<bool> uiOnly);
	};


	namespace ecl
	{
		struct EoCUI : public UIObject
		{
			typedef void (*ctor)(EoCUI* self, dse::Path* path);

			EoCUI(dse::Path* path);

			bool field_150;
			bool field_151;
			bool field_152;
			bool field_153;
			bool field_154;
			bool SomeInitPerformed;
			__int16 field_156;
			ComponentHandle ObjHandle1;
			ComponentHandle TooltipHandle;
			uint64_t field_168;
			uint64_t field_170;
			STDString field_178;
		};

		struct FlashCustomDrawCallback
		{
			using CustomDrawObject = void(FlashCustomDrawCallback* callback, void* mesh);

			wchar_t* Name;
			uint64_t field_8;
			uint64_t field_10;
			uint64_t field_18;
			int field_20;
			float OpacityFade;
			uint64_t field_28;
			uint64_t field_30;
			float DrawRect[4];
			bool HasRect;
			bool SomeClippingFlag;
			bool SomeClippingFlag2;
			bool field_4B;
			glm::ivec2 TextureDimensions;
			glm::mat4 TransformMatrix;
			uint64_t field_98;
		};

		/*struct UIExamine : public EoCUI
		{
			uint64_t UIStatusIconHelper[3];
			void* NetEventManagerVMT;
			uint64_t field_1B8;
			void* GameEventManagerVMT;
			CustomDrawStruct field_1C8;
			CustomDrawStruct Icon;
			uint64_t field_218;
			uint64_t field_220;
			int field_228;
			char field_22C;
			char field_22D;
			char field_22E;
			char field_22F;
			uint64_t field_230;
			UserId UserID;
			ComponentHandle OH1;
			ComponentHandle ObjectBeingExamined;
			uint64_t field_250;
		};*/
		struct UIExamine : UIObject
		{
			undefined field1_0xb4;
			undefined field2_0xb5;
			undefined field3_0xb6;
			undefined field4_0xb7;
			undefined field5_0xb8;
			undefined field6_0xb9;
			undefined field7_0xba;
			undefined field8_0xbb;
			undefined field9_0xbc;
			undefined field10_0xbd;
			undefined field11_0xbe;
			undefined field12_0xbf;
			undefined field13_0xc0;
			undefined field14_0xc1;
			undefined field15_0xc2;
			undefined field16_0xc3;
			undefined field17_0xc4;
			undefined field18_0xc5;
			undefined field19_0xc6;
			undefined field20_0xc7;
			undefined field21_0xc8;
			undefined field22_0xc9;
			undefined field23_0xca;
			undefined field24_0xcb;
			undefined field25_0xcc;
			undefined field26_0xcd;
			undefined field27_0xce;
			undefined field28_0xcf;
			undefined field29_0xd0;
			undefined field30_0xd1;
			undefined field31_0xd2;
			undefined field32_0xd3;
			undefined field33_0xd4;
			undefined field34_0xd5;
			undefined field35_0xd6;
			undefined field36_0xd7;
			undefined field37_0xd8;
			undefined field38_0xd9;
			undefined field39_0xda;
			undefined field40_0xdb;
			undefined field41_0xdc;
			undefined field42_0xdd;
			undefined field43_0xde;
			undefined field44_0xdf;
			undefined field45_0xe0;
			undefined field46_0xe1;
			undefined field47_0xe2;
			undefined field48_0xe3;
			undefined field49_0xe4;
			undefined field50_0xe5;
			undefined field51_0xe6;
			undefined field52_0xe7;
			undefined field53_0xe8;
			undefined field54_0xe9;
			undefined field55_0xea;
			undefined field56_0xeb;
			undefined field57_0xec;
			undefined field58_0xed;
			undefined field59_0xee;
			undefined field60_0xef;
			undefined field61_0xf0;
			undefined field62_0xf1;
			undefined field63_0xf2;
			undefined field64_0xf3;
			undefined field65_0xf4;
			undefined field66_0xf5;
			undefined field67_0xf6;
			undefined field68_0xf7;
			undefined1 IconCustomDrawStruct;
			undefined field70_0xf9;
			undefined field71_0xfa;
			undefined field72_0xfb;
			undefined field73_0xfc;
			undefined field74_0xfd;
			undefined field75_0xfe;
			undefined field76_0xff;
			ObjectHandle CurrentObjectHandle;
		};

		struct UILoadingScreen : public EoCUI
		{
			float LoadProgress;
			float LastLoadProgress;
			float HintTimer;
			int HintId;
			bool field_1A8;
			bool RequestDelete;
			ComponentHandle SomeUIHandle;
			STDWString CurrentStatusText;
			STDWString NextStatusText;
		};

		struct PickPosition
		{
			glm::vec3 Position;
			glm::vec3 Position2;
		};

		struct PickingHelperBase : public ProtectedGameObject<PickingHelperBase>
		{
			virtual ~PickingHelperBase() = 0;
			PickPosition PlaceablePos;
			PickPosition HoverCharacterPos;
			PickPosition HoverItemPos;
			PickPosition WalkablePos;
			ComponentHandle HoverAliveCharacterHandle;
			ComponentHandle HoverDeadCharacterHandle;
			ComponentHandle HoverItemHandle;
			ComponentHandle HoverGameObjectHandle;
			ComponentHandle PlaceableObjectHandle;
			ComponentHandle OH6;
			uint64_t WalkableAiFlags;
			uint8_t WalkablePickFlags;
			uint8_t GameObjectPickFlags;
		};

		/*struct PickingHelper : public PickingHelperBase
		{
			struct GameObjectPicker
			{
				void* VMT;
				void* field_8;
				PickPosition WorldPos;
			};

			Level* Level;
			PlayerId PlayerId;
			ComponentHandle OH7;
			ObjectSet<ComponentHandle> OS_OH;
			void* field_E0;
			int field_E8;
			glm::vec2 ScreenPos;
			GameObjectPicker* GameObjectPick;
			void* PlaceablePick;
			void* WalkablePick;
			void* ControllerPointerManager;
		};*/

		struct PickingHelperManager
		{
			void* VMT;
			void* field_8;
			RefMap<PlayerId, PickingHelper*> PlayerHelpers;
			void* field_20;
			void* field_28;
		};

		struct UIDragController : public DragController
		{
			ComponentHandle DragObject;
			EntityHandle DragEgg;
			bool PreventWorldDrag;
		};

		struct DragDropManager
		{
			struct Controllers
			{
				ecl::UIDragController* UIDragController;
				DragController* WorldDragController;
				DragController* SkillDragController;
				DragController* EggDragController;
				DragController* CharacterDragController;
			};

			void* VMT;
			uint64_t field_8;
			RefMap<PlayerId, Controllers> PlayerControllers;
		};

		struct UICursorInfo : public EoCUI
		{
			int WorldScreenPositionX;
			int WorldScreenPositionY;
			bool IsActive;
			bool TooltipArrayUpdated;
			bool HasSurfaceText;
			bool RequestClearTooltipText;
			bool ForceClearTooltipText;
			int16_t SurfaceIndex;
			int SurfaceTurns;
			int16_t SurfaceIndex2;
			int SurfaceTurns2;
			STDString Text;
		};

	}
}
