#pragma once

BEGIN_SE()

// TODO check
enum class ObjectHandleType
{
    _Unknown, // Unused?
    Light,
    Visual,
    _UIObject,
    Decal,
    Dummy,
    Reference,
    Text3D,
    Effect,
    Trigger,
    TerrainObject,
    // TODO:
	/*MeshProxy,
	SoundVolumeTrigger,
	Scene,
	GrannyFile,*/
	ClientCharacter = 11,
	/* Following types should be correct assuming types are assigned sequentially */
	ClientItem,
	ClientProjectile,
	ClientScenery,
	ClientWallConstruction,
	ClientWallPiece,
	ClientWallIntersection,
	ClientInventory,
	ClientAlignment,
	ClientAlignmentData,
	ClientGameAction,
	ClientSkill,
	ClientStatus,
	ClientParty,
    ServerCharacter = 25,
    ServerItem,
    ServerProjectile,
    ServerInventory,
    ServerInventoryView,
    ServerParty,
};

enum class Difficulty
{
    Explorer,
    Classic,
    Tactician,
    Honour = 3,
};

enum class AbilityType : int
{
	WarriorLore = 0,
	RangerLore = 1,
	RogueLore = 2,
	SingleHanded = 3,
	TwoHanded = 4,
	Blackrock = 5,
	Bow = 6,
	Crossbow = 7,
	Shield = 8,
	Reflexes = 9,
	ArmorMastery = 10,
	Sourcery = 11,
	Telekinesis = 12,
	Willpower = 13,
	FireSpecialist = 14,
	WaterSpecialist = 15,
	AirSpecialist = 16,
	EarthSpecialist = 17,
	Repair = 18,
	Sneaking = 19,
	Pickpocket = 20,
	Lockpicking = 21,
	Loremaster = 22,
	Crafting = 23,
	Barter = 24,
	Charm = 25,
	Intimidate = 26,
	Reason = 27,
	Charisma = 28,
	Leadership = 29,
	Luck = 30,
	Bodybuilding = 31,
	DualWielding = 32,
	Wand = 33,
	Throwing = 34,
};

enum class TalentType : int
{
    None = 0,
    ItemMovement = 1,
    ItemCreation = 2,
    Flanking = 3,
    AttackOfOpportunity = 4,
    Backstab = 5,
    Trade = 6,
    Lockpick = 7,
    ChanceToHitRanged = 8,
    ChanceToHitMelee = 9,
    Damage = 10,
    ActionPoints = 11,
    ActionPoints2 = 12,
    Criticals = 13,
    IncreasedArmor = 14,
    Sight = 15,
    ResistFear = 16,
    ResistKnockdown = 17,
    ResistStun = 18,
    ResistPoison = 19,
    ResistSilence = 20,
    ResistDead = 21,
    Carry = 22,
    Throwing = 23,
    Repair = 24,
    ExpGain = 25,
    ExtraStatPoints = 26,
    ExtraSkillPoints = 27,
    Durability = 28,
    Awareness = 29,
    Vitality = 30,
    FireSpells = 31,
    WaterSpells = 32,
    AirSpells = 33,
    EarthSpells = 34,
    Charm = 35,
    Intimidate = 36,
    Reason = 37,
    Luck = 38,
    Initiative = 39,
    InventoryAccess = 40,
    AvoidDetection = 41,
    AnimalEmpathy = 42,
    Escapist = 43,
    StandYourGround = 44,
    SurpriseAttack = 45,
    LightStep = 46,
    ResurrectToFullHealth = 47,
    Scientist = 48,
    Raistlin = 49,
    MrKnowItAll = 50,
    WhatARush = 51,
    FaroutDude = 52,
    Leech = 53,
    ElementalAffinity = 54,
    FiveStarRestaurant = 55,
    Bully = 56,
    ElementalRanger = 57,
    LightningRod = 58,
    Politician = 59,
    WeatherProof = 60,
    LoneWolf = 61,
    Zombie = 62,
    Demon = 63,
    IceKing = 64,
    Courageous = 65,
    GoldenMage = 66,
    WalkItOff = 67,
    FolkDancer = 68,
    SpillNoBlood = 69,
    Stench = 70,
    Kickstarter = 71,
    WarriorLoreNaturalArmor = 72,
    WarriorLoreNaturalHealth = 73,
    WarriorLoreNaturalResistance = 74,
    RangerLoreArrowRecover = 75,
    RangerLoreEvasionBonus = 76,
    RangerloreRangedAPBonus = 77,
    RogueLoreDaggerAPBonus = 78,
    RogueLoreDaggerBackStab = 79,
    RogueLoreMovementBonus = 80,
    RogueLoreHoldResistance = 81,
    NoAttackOfOpportunity = 82,
    WarriorLoreGrenadeRange = 83,
    RogueLoreGrenadePrecision = 84,
    WandCharge = 85,
    DualWieldingDodging = 86
};

namespace esv
{
	enum EntityComponentIndex
	{
		TurnManager = 3, // TOOD check
	};

	enum GameState
	{
		// TODO
	};
}

END_SE()