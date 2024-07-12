#include "pch.h"
#include <Extender/ScriptExtender.h>
#include "Pointer.h"
#include "CharacterUtils.h"

BEGIN_SE()

ecl::Character* PointerUtils::GetLastPickerCharacter()
{
	// TODO move the handle field here?
	return ClientCharacterUtils::GetCharacter(gExtender->GetHooks().LastPickerCharacterHandle);
}

ecl::Character* PointerUtils::GetCurrentPickerCharacter()
{
	// TODO move the handle field here?
	return ClientCharacterUtils::GetCharacter(gExtender->GetHooks().CurrentPickerCharacterHandle);
}

END_SE()
