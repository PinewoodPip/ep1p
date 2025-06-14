#pragma once
#include <GameDefinitions/RPGStats.h>
#include <GameDefinitions/Item.h>
#include <GameDefinitions/Character.h>

BEGIN_SE()

class ClientCharacterUtils
{
public:
	static ecl::Character* GetCharacter(ComponentHandle handle);
	static ecl::Character* GetCharacter(CDivinityStats_Character* stats);
	static CompactSet<ecl::Character*>* GetPartyMembers(ComponentHandle partyHandle);
	static ecl::Character* GetPlayerCharacter(short playerID = 1);
	static bool HasStatusType(ecl::Character* character, ecl::Status::StatusType statusType);
};

class ServerCharacterUtils
{
public:
	static esv::Character* GetCharacter(ComponentHandle handle);
	static esv::Character* GetCharacter(CDivinityStats_Character* stats);
	static CompactSet<esv::Character*>* GetPartyMembers(ComponentHandle partyHandle);
	static CompactSet<esv::Character*>* GetPartyMembers();
	static esv::Inventory* GetInventory(esv::Character* character);
	static bool HasItemWithUseAction(esv::Character* character, eoc::IActionData::ActionType actionType); // Not recursive
};

class SharedCharacterUtils
{
public:
	static int GetLoremaster(CDivinityStats_Character* stats);
};

END_SE();