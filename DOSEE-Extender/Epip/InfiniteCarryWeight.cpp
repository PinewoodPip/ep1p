#include "pch.h"
#include "InfiniteCarryWeight.h"
#include "Extender/ScriptExtender.h"
#include "Epip/EpipSettings.h"

using namespace dse;
using namespace epip;

void InfiniteCarryWeight::Setup()
{
	if (gSettings->InfiniteCarryWeight)
	{
		bool applied = gExtender->GetLibraryManager().ApplyCodePatch("esv::Character::UpdateOverEncumbered patch");
		if (!applied)
		{
			LOG("Failed to patch overencumbered status apply");
		}
	}
}
