#include "pch.h"
#include "AutoIdentify.h"
#include <Extender/ScriptExtender.h>
#include "Hooks/Hooks.h"

using namespace dse;
using namespace epip;

void AutoIdentify::Setup()
{
	auto& lib = gExtender->GetEngineHooks();
	lib.esv_ItemHelpers_GenerateTreasureItem.SetWrapper(&AutoIdentify::OnTreasureItemGenerated, this);
}

esv::Item* AutoIdentify::OnTreasureItemGenerated(StaticSymbols::esv_ItemHelpers_GenerateTreasureItemProc* next, void* request, int16_t unknown)
{
	esv::Item* item = next(request, unknown);
	if (item->Stats)
	{
		// Set newly-generated items to be identified. This happens before to-client sync.
		item->Stats->IdentifiedState = 1;
	}
	return item;
}