#pragma once
#include <GameDefinitions/RPGStats.h>
BEGIN_SE()

class ClientCharacterUtils
{
public:
	static ecl::Character* GetCharacter(ComponentHandle handle);
	static ecl::Character* GetCharacter(CDivinityStats_Character* stats);
	static CompactSet<ecl::Character*>* GetPartyMembers(ComponentHandle partyHandle);
	static ecl::Character* GetPlayerCharacter(short playerID = 1);
};

class ServerCharacterUtils
{
public:
	static esv::Character* GetCharacter(ComponentHandle handle);
	static esv::Character* GetCharacter(CDivinityStats_Character* stats);
	static CompactSet<esv::Character*>* GetPartyMembers(ComponentHandle partyHandle);
};

END_SE();