#pragma once

#include <Hooks/Wrappers.h>
#include <GameDefinitions/Symbols.h>
#include <GameDefinitions/UI.h>

BEGIN_SE()

class EngineHooks
{
public:
#define HOOK_DEFN(name, sym, defn) enum class name##Tag {}; \
	WrappableFunction<name##Tag, defn> name;
#include <Hooks/EngineHooks.inl>
#undef HOOK_DEFN

	void HookAll();
	void UnhookAll();
};

END_SE()
