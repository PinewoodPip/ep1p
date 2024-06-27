#include "pch.h"
#include "SkillRangeEffectFix.h"
#include "Extender/ScriptExtender.h"
#include "Epip/EpipSettings.h"
#include <cstring>

using namespace dse;

void SkillRangeEffectsFix::Setup()
{
	if (gSettings->FixSkillRangeGFX)
	{
		auto& lib = gExtender->GetEngineHooks();
		// Force all effects to render regardless of visibility check
		// TODO find a more proper way of doing this; wrapping IsVisible() and CheckVisible() produces artifacts, applying & undoing patches at runtime doesn't work as it likely interferes with the detour, as the check is very early in the function.
		gExtender->GetLibraryManager().ApplyCodePatch("ls::Effect::UpdateIsVisible patch");
	}
}
