#include "pch.h"
#include "InfiniteCarryWeight.h"
#include "Extender/ScriptExtender.h"

using namespace dse;
using namespace epip;

void InfiniteCarryWeight::Setup()
{
	bool applied = gExtender->GetLibraryManager().ApplyCodePatch("esv::Character::UpdateOverEncumbered patch");
	if (!applied)
	{
		LOG("Failed to patch overencumbered status apply");
	}
}
