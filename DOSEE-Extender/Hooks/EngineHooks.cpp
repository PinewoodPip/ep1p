#include <pch.h>
#include <Hooks/EngineHooks.h>
#include <Extender/ScriptExtender.h>

BEGIN_SE()

std::unordered_set<void*> gRegisteredTrampolines; // Was in crash reporter in DOS2 extender

#define HOOK_DEFN(name, sym, defn) decltype(EngineHooks::name) * decltype(EngineHooks::name)::gHook;
#include <Hooks/EngineHooks.inl>
#undef HOOK_DEFN

void EngineHooks::HookAll()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	auto& sym = GetStaticSymbols();

#define HOOK_DEFN(name, sym, defn) if (GetStaticSymbols().sym != nullptr) { name.Wrap(GetStaticSymbols().sym); }
#include <Hooks/EngineHooks.inl>
#undef HOOK_DEFN

	DetourTransactionCommit();
}

void EngineHooks::UnhookAll()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

#define HOOK_DEFN(name, sym, defn) name.Unwrap();
#include <Hooks/EngineHooks.inl>
#undef HOOK_DEFN

	DetourTransactionCommit();
}

END_SE()
