#pragma once
BEGIN_SE()

class ClientCharacterUtils
{
public:
	static ecl::Character* GetCharacter(ComponentHandle handle);
	static CompactSet<ecl::Character*>* GetPartyMembers(ComponentHandle partyHandle);
	static ecl::Character* GetPlayerCharacter(short playerID = 1);
};

class ServerCharacterUtils
{
public:
	static esv::Character* GetCharacter(ComponentHandle handle);
	static CompactSet<esv::Character*>* GetPartyMembers(ComponentHandle partyHandle);
};

END_SE();