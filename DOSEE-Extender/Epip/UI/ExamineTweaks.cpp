#include "pch.h"
#include "Epip/EpipSettings.h"
#include "ExamineTweaks.h"
#include "Extender/ScriptExtender.h"

using namespace dse;
using namespace epip;

void ExamineTweaks::Setup()
{
	auto setting = gSettings->ExamineInformation;
	if (setting == EpipSettings::ExamineInformationChoices::FullInformation)
	{
		bool applied = gExtender->GetLibraryManager().ApplyCodePatch("ecl::UIExamine::SetupInformation Loremaster patch"); // SlotData iterator patch for icons
		if (!applied)
		{
			ERR("Examine UI patches failed");
		}
	}
	else if (setting == EpipSettings::ExamineInformationChoices::SharedLoremaster)
	{
		// TODO!
	}
}
