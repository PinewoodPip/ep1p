#include <pch.h>
#include <Extender/ScriptExtender.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <psapi.h>
#include <regex>
#include <Epip/Epip.h>

#undef DEBUG_SERVER_CLIENT

BEGIN_SE()

void InitCrashReporting();
void ShutdownCrashReporting();
void DumpCurrentStack();

END_SE()

namespace dse
{
	std::unique_ptr<ScriptExtender> gExtender;

	ScriptExtender::ScriptExtender()
		/*: server_(config_),
		client_(config_),
		hitProxy_(*this)*/
	{
	}

	void ScriptExtender::Initialize()
	{
		/*if (config_.SendCrashReports) {
			InitCrashReporting();
		}*/

		GameVersionInfo gameVersion;
		if (Libraries.GetGameVersion(gameVersion)) {
			// TODO check version
		}
		else {
			ERR("Failed to retrieve game version info.");
		}

		/*Log("ScriptExtender::Initialize: Starting");*/
		auto initStart = std::chrono::high_resolution_clock::now();

		InitStaticSymbols();

		if (!Libraries.FindLibraries(gameVersion.Revision)) {
			ERR("ScriptExtender::Initialize: Could not load libraries; skipping scripting extension initialization.");
			extensionsEnabled_ = false;
		}

		/*server_.Initialize();
		client_.Initialize();*/

		auto initEnd = std::chrono::high_resolution_clock::now();
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(initEnd - initStart).count();
		/*Log("Library startup took %d ms", ms);*/

		PostStartup();

		gEpip->Startup();
		GetLibraryManager().ApplyCodePatches();
	}

	void ScriptExtender::Shutdown()
	{
		/*Log("ScriptExtender::Shutdown: Exiting");*/
		/*server_.Shutdown();
		client_.Shutdown();*/
		engineHooks_.UnhookAll();

		/*ResetExtensionStateServer();
		ResetExtensionStateClient();
		Wrappers.Shutdown();*/
	}

	/*ExtensionStateBase* ScriptExtender::GetCurrentExtensionState()
	{
		if (server_.IsInServerThread()) {
			if (server_.HasExtensionState()) {
				return &server_.GetExtensionState();
			}
			else {
				return nullptr;
			}
		}
		else if (client_.IsInClientThread()) {
			if (client_.HasExtensionState()) {
				return &client_.GetExtensionState();
			}
			else {
				return nullptr;
			}
		}
		else {
			WARN("Called from unknown thread %d?", GetCurrentThreadId());
			if (client_.HasExtensionState()) {
				return &client_.GetExtensionState();
			}
			else {
				return nullptr;
			}
		}
	}*/

	void ScriptExtender::OnBaseModuleLoaded(void* self)
	{
	}

	void ScriptExtender::OnIggyTraceCallback(void* unknown1, void* unknown2, char const* msg)
	{
		LOG("[IGGY] TRACE:", msg);
	}

	void ScriptExtender::OnIggyWarningCallback(void* unknown1, void* unknown2, int warningType, char const* msg)
	{
		if (warningType == 201 || warningType == 408)
		{
			return;
		}
		if (warningType == 503) {
			STDString errmsg(msg);
			// These warnings are spammed for every UI that doesn't catch these events.
			if (errmsg.find("onEventResolution") != std::string::npos
				|| errmsg.find("onEventResize") != std::string::npos) {
				return;
			}
		}
		LOG("[IGGY] WARNING:", std::to_string(warningType).c_str(), msg);
	}

	void ScriptExtender::RegisterIggyCallbacks()
	{
		auto const& symbols = GetStaticSymbols();
		if (symbols.IgSetTraceCallbackUTF8)
		{
			symbols.IgSetTraceCallbackUTF8(&OnIggyTraceCallback, nullptr);
		}
		if (symbols.IgSetWarningCallback)
		{
			symbols.IgSetWarningCallback(&OnIggyWarningCallback, nullptr);
		}
	}

	void ScriptExtender::PostStartup()
	{
		if (postStartupDone_) return;

		if (Libraries.PostStartupFindLibraries()) {
			/*gExtender->GetServer().Osiris().GetWrappers().InitializeDeferredExtensions();*/
			// FunctionLibrary.PostStartup();
			engineHooks_.HookAll();
			if (!gExtender->GetLibraryManager().CriticalInitializationFailed()) {
				hooks_.Startup();
			}

			/*server_.PostStartup();
			client_.PostStartup();*/

			/*luaBuiltinBundle_.SetResourcePath(config_.LuaBuiltinResourceDirectory);
			if (!luaBuiltinBundle_.LoadBuiltinResource(IDR_LUA_BUILTIN_BUNDLE)) {
				ERR("Failed to load Lua builtin resource bundle!");
			}*/
		}

		// TODO check version
		/*GameVersionInfo gameVersion;
		if (Libraries.GetGameVersion(gameVersion) && !gameVersion.IsSupported()) {
			std::wstringstream ss;
			ss << L"Your game version (v" << gameVersion.Major << L"." << gameVersion.Minor << L"." << gameVersion.Revision << L"." << gameVersion.Build
				<< L") is not supported by the Script Extender; please upgrade to at least v3.6.54";
			Libraries.ShowStartupError(ss.str().c_str(), true, false);
		}
		else if (Libraries.CriticalInitializationFailed()) {
			Libraries.ShowStartupError(L"A severe error has occurred during Script Extender initialization. Extension features will be unavailable.", true, false);
		}
		else if (Libraries.InitializationFailed()) {
			Libraries.ShowStartupError(L"An error has occurred during Script Extender initialization. Some extension features might be unavailable.", true, false);
		}*/

		postStartupDone_ = true;
	}
}
