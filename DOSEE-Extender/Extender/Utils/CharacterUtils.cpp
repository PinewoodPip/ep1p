#include "pch.h"
#include "CharacterUtils.h"

#include <Extender/ScriptExtender.h>
#include <Extender/Utils/CharacterUtils.h>

BEGIN_SE()

// CLIENT UTILS

ecl::Character* ClientCharacterUtils::GetCharacter(ComponentHandle handle)
{
	ComponentFactory<ecl::Character>* factory = *GetStaticSymbols().ObjectFactory__ecl_Character;

	return factory->Get(handle);
}

ecl::Character* ClientCharacterUtils::GetCharacter(CDivinityStats_Character* stats)
{
	auto factory = *gStaticSymbols->ObjectFactory__ecl_Character;
	for (auto character : factory->Components)
	{
		if (character->Stats == stats)
		{
			return character;
		}
	}
	return nullptr;
}

CompactSet<ecl::Character*>* ClientCharacterUtils::GetPartyMembers(ComponentHandle partyHandle)
{
	ecl::PartyManager* manager = *GetStaticSymbols().ecl_PartyManager;
	ecl::Party* party = manager->Get((ComponentHandle)partyHandle);
	return party ? &party->CharacterSet : nullptr;
}

ecl::Character* ClientCharacterUtils::GetPlayerCharacter(short playerID)
{
	ecl::PlayerManager* manager = *GetStaticSymbols().ecl_PlayerManager;
	return GetStaticSymbols().ecl_PlayerManager_GetCharacterByPlayerID(manager, playerID);
}

// SERVER UTILS

esv::Character* ServerCharacterUtils::GetCharacter(ComponentHandle handle)
{
	ComponentFactory<esv::Character>* factory = *GetStaticSymbols().ObjectFactory__esv_Character;

	return factory->Get(handle);
}

esv::Character* ServerCharacterUtils::GetCharacter(CDivinityStats_Character* stats)
{
	auto factory = *gStaticSymbols->ObjectFactory__esv_Character;
	for (auto character : factory->Components)
	{
		if (character->Stats == stats)
		{
			return character;
		}
	}
	return nullptr;
}

CompactSet<esv::Character*>* ServerCharacterUtils::GetPartyMembers(ComponentHandle partyHandle)
{
	esv::PartyManager* manager = *GetStaticSymbols().esv_PartyManager;
	auto party = manager->Get(partyHandle);
	return party ? &party->CharacterSet : nullptr;
}

END_SE()
