#include "pch.h"
#include "DeadPartyXP.h"
#include <Extender/ScriptExtender.h>

using namespace dse;
using namespace epip;

void DeadPartyXP::Setup()
{
	bool applied = true;
	// Remove check for tactician/honour mode
	applied = applied && gExtender->GetLibraryManager().ApplyCodePatch("esv::Character::AddExperience patch");
	applied = applied && gExtender->GetLibraryManager().ApplyCodePatch("ecl::Character::AddExperience patch");

	if (!applied)
	{
		LOG("Not all XP patches succeeded"); // TODO show error for user, undo patches
	}
}
