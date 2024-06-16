#include "pch.h"
#include "SkillRangeEffectFix.h"
#include "Extender/ScriptExtender.h"
#include <cstring>

using namespace dse;

void SkillRangeEffectsFix::Setup()
{
	auto& lib = gExtender->GetEngineHooks();
	// Force all effects to render regardless of visibility check
	// TODO find a more proper way of doing this; wrapping IsVisible() and CheckVisible() produces artifacts, applying & undoing patches at runtime doesn't work as it likely interferes with the detour.
	gExtender->GetLibraryManager().ApplyCodePatch("ls::Effect::UpdateIsVisible patch");
}
