#include "pch.h"
#include "CharacterUtils.h"

#include <Extender/ScriptExtender.h>
#include <Extender/Utils/CharacterUtils.h>

BEGIN_SE()

ecl::Character* ClientCharacterUtils::GetCharacter(ComponentHandle handle)
{
	ComponentFactory<ecl::Character>* factory = *GetStaticSymbols().ObjectFactory__ecl_Character;

	return factory->Get(handle);
}

END_SE()