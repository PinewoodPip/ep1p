#pragma once

#include <pch.h>
#include <Utils.h>
#include <GameDefinitions/Base/BaseUtilities.h>
#include <GameDefinitions/Base/BaseMemory.h>

BEGIN_SE()

struct CharacterDynamicStat : public ProtectedGameObject<CharacterDynamicStat>
{
    int InstanceID_m;
    undefined field1_0x4;
    bool field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    undefined1 CDivinityStatsRef_m;
    undefined field6_0x9;
    undefined field7_0xa;
    undefined field8_0xb;
    undefined field9_0xc;
    undefined field10_0xd;
    undefined field11_0xe;
    undefined field12_0xf;
    int Strength;
    int Speed;
    int Intelligence;
    int Movement;
    int MovementSpeed;
    int Dexterity;
    int Perception;
    int Constitution;
    int FireResistance;
    int EarthResistance;
    int WaterResistance;
    int AirResistance;
    int PoisonResistance;
    int PiercingResistance;
    int CrushingResistance;
    int SlashingResistance;
    int TenebriumResistance;
    int Sight;
    int Hearing;
    int FoV;
    int APMaximum;
    int APStart;
    int APRecovery;
    int CriticalChance;
    int Initiative;
    int Vitality;
    int MagicPoints;
    int Level;
    int Gain;
    int Armor;
    int ArmorBoost;
    int OffenseRating;
    int DefenseRating;
    int MaxResistance;
    int Weight;
    undefined1 ChanceToHitBoost;
    undefined field49_0x9d;
    undefined field50_0x9e;
    undefined field51_0x9f;
    int DamageBoost;
    int APCostBoost;
    int WarriorLore;
    int RangerLore;
    int RogueLore;
    int SingleHanded;
    int TwoHanded;
    int Blackrock;
    int Bow;
    int Crossbow;
    int Shield;
    int Reflexes;
    int ArmorMastery;
    int Sourcery;
    int Telekinesis;
    int Willpower;
    int FireSpecialist;
    int WaterSpecialist;
    int AirSpecialist;
    int EarthSpecialist;
    int Repair;
    int Sneaking;
    int Pickpocket;
    int Lockpicking;
    int Loremaster;
    int Crafting;
    int Barter;
    int Charm;
    int Intimidate;
    int Reason;
    int Charisma;
    int Leadership;
    int Luck;
    int Bodybuilding;
    int DualWielding;
    int Wand;
    int Throwing;
    undefined field89_0x134;
    undefined field90_0x135;
    undefined field91_0x136;
    undefined field92_0x137;
    undefined field93_0x138;
    undefined field94_0x139;
    undefined field95_0x13a;
    undefined field96_0x13b;
    undefined field97_0x13c;
    undefined field98_0x13d;
    undefined field99_0x13e;
    undefined field100_0x13f;
    short TraitsArray;
    undefined field102_0x142;
    undefined field103_0x143;
    undefined field104_0x144;
    undefined field105_0x145;
    undefined field106_0x146;
    undefined field107_0x147;
    undefined field108_0x148;
    undefined field109_0x149;
    undefined field110_0x14a;
    undefined field111_0x14b;
    undefined field112_0x14c;
    undefined field113_0x14d;
    undefined field114_0x14e;
    undefined field115_0x14f;
    undefined field116_0x150;
    undefined field117_0x151;
    undefined field118_0x152;
    undefined field119_0x153;
    undefined field120_0x154;
    undefined field121_0x155;
    undefined field122_0x156;
    undefined field123_0x157;
    undefined field124_0x158;
    undefined field125_0x159;
    undefined field126_0x15a;
    undefined field127_0x15b;
    undefined field128_0x15c;
    undefined field129_0x15d;
    undefined field130_0x15e;
    undefined field131_0x15f;
    undefined field132_0x160;
    undefined field133_0x161;
    undefined field134_0x162;
    undefined field135_0x163;
    undefined1 Flags;
    undefined field137_0x165;
    undefined field138_0x166;
    undefined field139_0x167;
    int BoostConditions;
    undefined field141_0x16c;
    undefined field142_0x16d;
    undefined field143_0x16e;
    undefined field144_0x16f;
    struct FixedString SomeFS;
    undefined1 HasReflection_m;
    undefined field147_0x179;
    undefined field148_0x17a;
    undefined field149_0x17b;
    undefined field150_0x17c;
    undefined field151_0x17d;
    undefined field152_0x17e;
    undefined field153_0x17f;
    undefined field154_0x180;
    undefined field155_0x181;
    undefined field156_0x182;
    undefined field157_0x183;
    undefined field158_0x184;
    undefined field159_0x185;
    undefined field160_0x186;
    undefined field161_0x187;
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

struct ItemDynamicStat
{
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
    undefined field64_0x40;
    undefined field65_0x41;
    undefined field66_0x42;
    undefined field67_0x43;
    undefined field68_0x44;
    undefined field69_0x45;
    undefined field70_0x46;
    undefined field71_0x47;
    undefined field72_0x48;
    undefined field73_0x49;
    undefined field74_0x4a;
    undefined field75_0x4b;
    undefined field76_0x4c;
    undefined field77_0x4d;
    undefined field78_0x4e;
    undefined field79_0x4f;
    undefined field80_0x50;
    undefined field81_0x51;
    undefined field82_0x52;
    undefined field83_0x53;
    undefined field84_0x54;
    undefined field85_0x55;
    undefined field86_0x56;
    undefined field87_0x57;
    undefined field88_0x58;
    undefined field89_0x59;
    undefined field90_0x5a;
    undefined field91_0x5b;
    undefined field92_0x5c;
    undefined field93_0x5d;
    undefined field94_0x5e;
    undefined field95_0x5f;
    undefined field96_0x60;
    undefined field97_0x61;
    undefined field98_0x62;
    undefined field99_0x63;
    undefined field100_0x64;
    undefined field101_0x65;
    undefined field102_0x66;
    undefined field103_0x67;
    undefined field104_0x68;
    undefined field105_0x69;
    undefined field106_0x6a;
    undefined field107_0x6b;
    undefined field108_0x6c;
    undefined field109_0x6d;
    undefined field110_0x6e;
    undefined field111_0x6f;
    undefined field112_0x70;
    undefined field113_0x71;
    undefined field114_0x72;
    undefined field115_0x73;
    undefined field116_0x74;
    undefined field117_0x75;
    undefined field118_0x76;
    undefined field119_0x77;
    undefined field120_0x78;
    undefined field121_0x79;
    undefined field122_0x7a;
    undefined field123_0x7b;
    undefined field124_0x7c;
    undefined field125_0x7d;
    undefined field126_0x7e;
    undefined field127_0x7f;
    undefined field128_0x80;
    undefined field129_0x81;
    undefined field130_0x82;
    undefined field131_0x83;
    undefined field132_0x84;
    undefined field133_0x85;
    undefined field134_0x86;
    undefined field135_0x87;
    undefined field136_0x88;
    undefined field137_0x89;
    undefined field138_0x8a;
    undefined field139_0x8b;
    undefined field140_0x8c;
    undefined field141_0x8d;
    undefined field142_0x8e;
    undefined field143_0x8f;
    undefined field144_0x90;
    undefined field145_0x91;
    undefined field146_0x92;
    undefined field147_0x93;
    undefined field148_0x94;
    undefined field149_0x95;
    undefined field150_0x96;
    undefined field151_0x97;
    undefined field152_0x98;
    undefined field153_0x99;
    undefined field154_0x9a;
    undefined field155_0x9b;
    undefined field156_0x9c;
    undefined field157_0x9d;
    undefined field158_0x9e;
    undefined field159_0x9f;
    undefined field160_0xa0;
    undefined field161_0xa1;
    undefined field162_0xa2;
    undefined field163_0xa3;
    undefined field164_0xa4;
    undefined field165_0xa5;
    undefined field166_0xa6;
    undefined field167_0xa7;
    undefined field168_0xa8;
    undefined field169_0xa9;
    undefined field170_0xaa;
    undefined field171_0xab;
    undefined field172_0xac;
    undefined field173_0xad;
    undefined field174_0xae;
    undefined field175_0xaf;
    undefined field176_0xb0;
    undefined field177_0xb1;
    undefined field178_0xb2;
    undefined field179_0xb3;
    undefined field180_0xb4;
    undefined field181_0xb5;
    undefined field182_0xb6;
    undefined field183_0xb7;
    undefined field184_0xb8;
    undefined field185_0xb9;
    undefined field186_0xba;
    undefined field187_0xbb;
    undefined field188_0xbc;
    undefined field189_0xbd;
    undefined field190_0xbe;
    undefined field191_0xbf;
    undefined field192_0xc0;
    undefined field193_0xc1;
    undefined field194_0xc2;
    undefined field195_0xc3;
    undefined field196_0xc4;
    undefined field197_0xc5;
    undefined field198_0xc6;
    undefined field199_0xc7;
    undefined field200_0xc8;
    undefined field201_0xc9;
    undefined field202_0xca;
    undefined field203_0xcb;
    undefined field204_0xcc;
    undefined field205_0xcd;
    undefined field206_0xce;
    undefined field207_0xcf;
    undefined field208_0xd0;
    undefined field209_0xd1;
    undefined field210_0xd2;
    undefined field211_0xd3;
    undefined field212_0xd4;
    undefined field213_0xd5;
    undefined field214_0xd6;
    undefined field215_0xd7;
    undefined field216_0xd8;
    undefined field217_0xd9;
    undefined field218_0xda;
    undefined field219_0xdb;
    undefined field220_0xdc;
    undefined field221_0xdd;
    undefined field222_0xde;
    undefined field223_0xdf;
    undefined field224_0xe0;
    undefined field225_0xe1;
    undefined field226_0xe2;
    undefined field227_0xe3;
    undefined field228_0xe4;
    undefined field229_0xe5;
    undefined field230_0xe6;
    undefined field231_0xe7;
    undefined field232_0xe8;
    undefined field233_0xe9;
    undefined field234_0xea;
    undefined field235_0xeb;
    undefined field236_0xec;
    undefined field237_0xed;
    undefined field238_0xee;
    undefined field239_0xef;
    undefined field240_0xf0;
    undefined field241_0xf1;
    undefined field242_0xf2;
    undefined field243_0xf3;
    uint Flags;
};

struct CDivinityStats_Item {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    int Level; /* Created by retype action */
    undefined field9_0xc;
    undefined field10_0xd;
    undefined field11_0xe;
    undefined field12_0xf;
    undefined field13_0x10;
    undefined field14_0x11;
    undefined field15_0x12;
    undefined field16_0x13;
    undefined field17_0x14;
    undefined field18_0x15;
    undefined field19_0x16;
    undefined field20_0x17;
    undefined field21_0x18;
    undefined field22_0x19;
    undefined field23_0x1a;
    undefined field24_0x1b;
    undefined field25_0x1c;
    undefined field26_0x1d;
    undefined field27_0x1e;
    undefined field28_0x1f;
    undefined field29_0x20;
    undefined field30_0x21;
    undefined field31_0x22;
    undefined field32_0x23;
    undefined field33_0x24;
    undefined field34_0x25;
    undefined field35_0x26;
    undefined field36_0x27;
    undefined field37_0x28;
    undefined field38_0x29;
    undefined field39_0x2a;
    undefined field40_0x2b;
    undefined field41_0x2c;
    undefined field42_0x2d;
    undefined field43_0x2e;
    undefined field44_0x2f;
    undefined field45_0x30;
    undefined field46_0x31;
    undefined field47_0x32;
    undefined field48_0x33;
    undefined field49_0x34;
    undefined field50_0x35;
    undefined field51_0x36;
    undefined field52_0x37;
    undefined field53_0x38;
    undefined field54_0x39;
    undefined field55_0x3a;
    undefined field56_0x3b;
    undefined field57_0x3c;
    undefined field58_0x3d;
    undefined field59_0x3e;
    undefined field60_0x3f;
    undefined field61_0x40;
    undefined field62_0x41;
    undefined field63_0x42;
    undefined field64_0x43;
    undefined field65_0x44;
    undefined field66_0x45;
    undefined field67_0x46;
    undefined field68_0x47;
    undefined field69_0x48;
    undefined field70_0x49;
    undefined field71_0x4a;
    undefined field72_0x4b;
    undefined field73_0x4c;
    undefined field74_0x4d;
    undefined field75_0x4e;
    undefined field76_0x4f;
    undefined field77_0x50;
    undefined field78_0x51;
    undefined field79_0x52;
    undefined field80_0x53;
    undefined field81_0x54;
    undefined field82_0x55;
    undefined field83_0x56;
    undefined field84_0x57;
    undefined field85_0x58;
    undefined field86_0x59;
    undefined field87_0x5a;
    undefined field88_0x5b;
    undefined field89_0x5c;
    undefined field90_0x5d;
    undefined field91_0x5e;
    undefined field92_0x5f;
    undefined field93_0x60;
    undefined field94_0x61;
    undefined field95_0x62;
    undefined field96_0x63;
    undefined field97_0x64;
    undefined field98_0x65;
    undefined field99_0x66;
    undefined field100_0x67;
    undefined field101_0x68;
    undefined field102_0x69;
    undefined field103_0x6a;
    undefined field104_0x6b;
    undefined field105_0x6c;
    undefined field106_0x6d;
    undefined field107_0x6e;
    undefined field108_0x6f;
    undefined field109_0x70;
    undefined field110_0x71;
    undefined field111_0x72;
    undefined field112_0x73;
    undefined field113_0x74;
    undefined field114_0x75;
    undefined field115_0x76;
    undefined field116_0x77;
    undefined field117_0x78;
    undefined field118_0x79;
    undefined field119_0x7a;
    undefined field120_0x7b;
    undefined field121_0x7c;
    undefined field122_0x7d;
    undefined field123_0x7e;
    undefined field124_0x7f;
    undefined field125_0x80;
    undefined field126_0x81;
    undefined field127_0x82;
    undefined field128_0x83;
    undefined field129_0x84;
    undefined field130_0x85;
    undefined field131_0x86;
    undefined field132_0x87;
    undefined field133_0x88;
    undefined field134_0x89;
    undefined field135_0x8a;
    undefined field136_0x8b;
    undefined field137_0x8c;
    undefined field138_0x8d;
    undefined field139_0x8e;
    undefined field140_0x8f;
    undefined field141_0x90;
    undefined field142_0x91;
    undefined field143_0x92;
    undefined field144_0x93;
    undefined field145_0x94;
    undefined field146_0x95;
    undefined field147_0x96;
    undefined field148_0x97;
    undefined field149_0x98;
    undefined field150_0x99;
    undefined field151_0x9a;
    undefined field152_0x9b;
    undefined field153_0x9c;
    undefined field154_0x9d;
    undefined field155_0x9e;
    undefined field156_0x9f;
    undefined field157_0xa0;
    undefined field158_0xa1;
    undefined field159_0xa2;
    undefined field160_0xa3;
    undefined field161_0xa4;
    undefined field162_0xa5;
    undefined field163_0xa6;
    undefined field164_0xa7;
    undefined field165_0xa8;
    undefined field166_0xa9;
    undefined field167_0xaa;
    undefined field168_0xab;
    undefined field169_0xac;
    undefined field170_0xad;
    undefined field171_0xae;
    undefined field172_0xaf;
    undefined field173_0xb0;
    undefined field174_0xb1;
    undefined field175_0xb2;
    undefined field176_0xb3;
    undefined field177_0xb4;
    undefined field178_0xb5;
    undefined field179_0xb6;
    undefined field180_0xb7;
    undefined field181_0xb8;
    undefined field182_0xb9;
    undefined field183_0xba;
    undefined field184_0xbb;
    undefined field185_0xbc;
    undefined field186_0xbd;
    undefined field187_0xbe;
    undefined field188_0xbf;
    struct CRPGStats_Object* StatsObject;
    undefined field190_0xc8;
    undefined field191_0xc9;
    undefined field192_0xca;
    undefined field193_0xcb;
    undefined field194_0xcc;
    undefined field195_0xcd;
    undefined field196_0xce;
    undefined field197_0xcf;
    undefined field198_0xd0;
    undefined field199_0xd1;
    undefined field200_0xd2;
    undefined field201_0xd3;
    undefined field202_0xd4;
    undefined field203_0xd5;
    undefined field204_0xd6;
    undefined field205_0xd7;
    undefined field206_0xd8;
    undefined field207_0xd9;
    undefined field208_0xda;
    undefined field209_0xdb;
    undefined field210_0xdc;
    undefined field211_0xdd;
    undefined field212_0xde;
    undefined field213_0xdf;
    undefined field214_0xe0;
    undefined field215_0xe1;
    undefined field216_0xe2;
    undefined field217_0xe3;
    undefined field218_0xe4;
    undefined field219_0xe5;
    undefined field220_0xe6;
    undefined field221_0xe7;
    undefined field222_0xe8;
    undefined field223_0xe9;
    undefined field224_0xea;
    undefined field225_0xeb;
    undefined field226_0xec;
    undefined field227_0xed;
    undefined field228_0xee;
    undefined field229_0xef;
    undefined field230_0xf0;
    undefined field231_0xf1;
    undefined field232_0xf2;
    undefined field233_0xf3;
    undefined field234_0xf4;
    undefined field235_0xf5;
    undefined field236_0xf6;
    undefined field237_0xf7;
    int** RequirementsSet; /* Created by retype action */
    undefined field239_0x100;
    undefined field240_0x101;
    undefined field241_0x102;
    undefined field242_0x103;
    undefined field243_0x104;
    undefined field244_0x105;
    undefined field245_0x106;
    undefined field246_0x107;
    undefined field247_0x108;
    undefined field248_0x109;
    undefined field249_0x10a;
    undefined field250_0x10b;
    undefined field251_0x10c;
    undefined field252_0x10d;
    undefined field253_0x10e;
    undefined field254_0x10f;
    undefined field255_0x110;
    undefined field256_0x111;
    undefined field257_0x112;
    undefined field258_0x113;
    undefined field259_0x114;
    undefined field260_0x115;
    undefined field261_0x116;
    undefined field262_0x117;
    undefined field263_0x118;
    undefined field264_0x119;
    undefined field265_0x11a;
    undefined field266_0x11b;
    undefined field267_0x11c;
    undefined field268_0x11d;
    undefined field269_0x11e;
    undefined field270_0x11f;
    undefined field271_0x120;
    undefined field272_0x121;
    undefined field273_0x122;
    undefined field274_0x123;
    undefined field275_0x124;
    undefined field276_0x125;
    undefined field277_0x126;
    undefined field278_0x127;
    undefined field279_0x128;
    undefined field280_0x129;
    undefined field281_0x12a;
    undefined field282_0x12b;
    undefined field283_0x12c;
    undefined field284_0x12d;
    undefined field285_0x12e;
    undefined field286_0x12f;
    undefined field287_0x130;
    undefined field288_0x131;
    undefined field289_0x132;
    undefined field290_0x133;
    undefined field291_0x134;
    undefined field292_0x135;
    undefined field293_0x136;
    undefined field294_0x137;
    undefined field295_0x138;
    undefined field296_0x139;
    undefined field297_0x13a;
    undefined field298_0x13b;
    undefined field299_0x13c;
    undefined field300_0x13d;
    undefined field301_0x13e;
    undefined field302_0x13f;
    int IdentifiedState; /* 0 for unidentified */
    undefined field304_0x144;
    undefined field305_0x145;
    undefined field306_0x146;
    undefined field307_0x147;
    undefined field308_0x148;
    undefined field309_0x149;
    undefined field310_0x14a;
    undefined field311_0x14b;
    undefined field312_0x14c;
    undefined field313_0x14d;
    undefined field314_0x14e;
    undefined field315_0x14f;
    bool field316_0x150;
    undefined field317_0x151;
    bool CustomRequirements; /* Created by retype action */
    undefined field319_0x153;
    int Durability; /* Created by retype action */
    int DurabilityCounter; /* Created by retype action */
    undefined1 RepairDurabilityPenalty; /* Created by retype action */
    undefined field323_0x15d;
    undefined field324_0x15e;
    undefined field325_0x15f;
    FixedString ItemType; /* Created by retype action */
    std::vector<ItemDynamicStat*> DynamicStats;
};

END_NS()