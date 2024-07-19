#pragma once

#include <Hooks/DataLibraries.h>
#include <Hooks/EngineHooks.h>
#include <Hooks/Hooks.h>
#include <GameDefinitions/Symbols.h>

#include <thread>
#include <mutex>
#include <shared_mutex>

BEGIN_SE()

class ScriptExtender
{
public:
	ScriptExtender(HMODULE handle);

	void Initialize();
	void PostStartup();
	void Shutdown();
	void RegisterIggyCallbacks();

	inline bool WasInitialized() const
	{
		return postStartupDone_;
	}

	/*inline ExtenderConfig& GetConfig()
	{
		return config_;
	}*/

	/*void LogLuaError(std::string_view msg);
	void LogOsirisError(std::string_view msg);
	void LogOsirisWarning(std::string_view msg);
	void LogOsirisMsg(std::string_view msg);*/

	/*inline esv::ScriptExtender& GetServer()
	{
		return server_;
	}

	inline ecl::ScriptExtender& GetClient()
	{
		return client_;
	}*/

	inline LibraryManager const& GetLibraryManager() const
	{
		return Libraries;
	}

	inline LibraryManager& GetLibraryManager()
	{
		return Libraries;
	}

	/*ExtensionStateBase* GetCurrentExtensionState();*/

	//bool HasFeatureFlag(char const*) const;

	inline EngineHooks& GetEngineHooks()
	{
		return engineHooks_;
	}

	inline Hooks& GetHooks()
	{
		return hooks_;
	}

	inline HMODULE GetModuleHandle()
	{
		return _ModuleHandle;
	}

private:
	/*esv::ScriptExtender server_;
	ecl::ScriptExtender client_;*/
	LibraryManager Libraries;
	EngineHooks engineHooks_;
	Hooks hooks_;
	std::recursive_mutex globalStateLock_;
	std::shared_mutex pathOverrideMutex_;
	std::unordered_map<STDString, STDString> pathOverrides_;

	/*ExtenderConfig config_;*/
	bool extensionsEnabled_{ false };
	bool postStartupDone_{ false };
	HMODULE _ModuleHandle;

	void OnBaseModuleLoaded(void* self);
	static void OnIggyTraceCallback(void* unknown1, void* unknown2, char const* msg);
	static void OnIggyWarningCallback(void* unknown1, void* unknown2, int warningType, char const* msg);
};

extern std::unique_ptr<ScriptExtender> gExtender;

END_SE()
