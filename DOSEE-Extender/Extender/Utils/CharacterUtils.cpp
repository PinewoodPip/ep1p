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

CompactSet<esv::Character*>* ServerCharacterUtils::GetPartyMembers()
{
	auto mainParty = (*GetStaticSymbols().esv_PartyManager)->Components[0]; // TODO are multiple parties ever used in DOS1?
	return &mainParty->CharacterSet;
}

esv::Inventory* ServerCharacterUtils::GetInventory(esv::Character* character)
{
	return (*GetStaticSymbols().esv_InventoryFactory)->Get(character->InventoryHandle);
}

bool ServerCharacterUtils::HasItemWithUseAction(esv::Character* character, eoc::IActionData::ActionType actionType)
{
	auto inventory = ServerCharacterUtils::GetInventory(character);
	if (inventory) // TODO make this recursive?
	{
		for (auto itemHandle : inventory->Items)
		{
			esv::Item* item = (*gStaticSymbols->ObjectFactory__esv_Item)->Get(itemHandle);
			if (item)
			{
				eoc::ItemTemplate* itemTemplate = (eoc::ItemTemplate*)item->GetCurrentTemplate();
				for (auto action : itemTemplate->BaseActionData)
				{
					if (action->Type == actionType)
					{
						return true;
					}
				}
			}
		}
	}
	else
	{
		WARN("Player character has no inventory?");
	}
	return false;
}

int SharedCharacterUtils::GetLoremaster(CDivinityStats_Character* stats)
{
	int loremaster = 0;
	for (CharacterDynamicStat* dynStat : stats->DynamicStats)
	{
		loremaster += dynStat->Loremaster;
	}
	// TODO check for traits (Materialistic higher than Spiritual)
	return loremaster;
}

END_SE()
