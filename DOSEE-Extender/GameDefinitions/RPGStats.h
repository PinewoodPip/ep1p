#pragma once

#include <pch.h>
#include <Utils.h>
#include <GameDefinitions/Base/BaseUtilities.h>
#include <GameDefinitions/Base/BaseMemory.h>

BEGIN_SE()

struct CharacterDynamicStat : public ProtectedGameObject<CharacterDynamicStat>
{
	char unknown[16];
	int32_t Strength;
	int32_t Speed;
	int32_t Intelligence;
	int32_t Movement;
	int32_t MovementSpeed;
	int32_t Dexterity;
	int32_t Perception;
	int32_t Constitution;
	int32_t FireResistance;
	int32_t EarthResistance;
	int32_t WaterResistance;
	int32_t AirResistance;
	int32_t PoisonResistance;
	int32_t PiercingResistance;
	int32_t CrushingResistance;
	int32_t SlashingResistance;
	int32_t TenebriumResistance;
	int32_t Sight;
	int32_t Hearing;
	int32_t FoV;
};

struct CDivinityStats_Character
{
	void* VMT_m;
	uint32_t Level;
	char unknown[40];
	float SomeFloat;
	char unknown1[244];
	uint32_t CurrentHP;
	uint32_t CurrentMP;
	uint32_t CurrentAP;
	uint32_t BonusAP;
	uint32_t Experience_m;
	uint32_t Reputation;
	uint8_t Flanked;
	uint32_t Karma;
	char unknown2[31];
	int32_t unknownInt;
	char unknown3[20];
	int32_t MaxResistance;
	//char unknown4[20];
	//CharacterDynamicStat** test[10];
	char unknownA[16];
	//CharacterDynamicStat** DynamicStats;
	Vector<CharacterDynamicStat*> DynamicStats;
	char unknown5[74];
	uint32_t unknownInt2;
	uint32_t unknownInt3;
	uint32_t unknownInt4;
	char unknown6[32];
	uint32_t MaxHP;
	uint32_t unknownInt5;
};

END_NS()