#pragma once

#include <GameDefinitions/Base/Base.h>
#include <GameDefinitions/Enumerations.h>
#include <GameDefinitions/EntitySystem.h>
#include <GameDefinitions/RPGStats.h>
//#include <GameDefinitions/GameObjects/Status.h>
//#include <GameDefinitions/Sound.h>
//#include <GameDefinitions/GameObjects/RootTemplates.h>
//#include <GameDefinitions/GameObjects/Ai.h>
//#include <GameDefinitions/GameObjects/Plan.h>

BEGIN_SE()

struct OsirisCharacterEventManager { /* Size correct, but might actually be OsirisEventManager */
	undefined field0_0x0;
	undefined field1_0x1;
	undefined field2_0x2;
	undefined field3_0x3;
	undefined field4_0x4;
	undefined field5_0x5;
	undefined field6_0x6;
	undefined field7_0x7;
	undefined1 OsirisInterface; /* Created by retype action */
	undefined field9_0x9;
	undefined field10_0xa;
	undefined field11_0xb;
	undefined field12_0xc;
	undefined field13_0xd;
	undefined field14_0xe;
	undefined field15_0xf;
	undefined1 COsiris; /* Created by retype action */
	undefined field17_0x11;
	undefined field18_0x12;
	undefined field19_0x13;
	undefined field20_0x14;
	undefined field21_0x15;
	undefined field22_0x16;
	undefined field23_0x17;
	void* RegisteredFunctionsArray_m; /* Created by retype action */
	undefined field25_0x20;
	undefined field26_0x21;
	undefined field27_0x22;
	undefined field28_0x23;
	undefined field29_0x24;
	undefined field30_0x25;
	undefined field31_0x26;
	undefined field32_0x27;
	void* RegisteredFunctions; /* Created by retype action */
	undefined field34_0x30;
	undefined field35_0x31;
	undefined field36_0x32;
	undefined field37_0x33;
	uint RegisteredFunctionsAmount; /* Created by retype action */
	undefined field39_0x38;
	undefined field40_0x39;
	undefined field41_0x3a;
	undefined field42_0x3b;
	undefined field43_0x3c;
	undefined field44_0x3d;
	undefined field45_0x3e;
	undefined field46_0x3f;
	void* SomeImportantPtr; /* Created by retype action */
	undefined1 RegisteredObjects; /* Created by retype action */
	undefined field49_0x49;
	undefined field50_0x4a;
	undefined field51_0x4b;
	undefined field52_0x4c;
	undefined field53_0x4d;
	undefined field54_0x4e;
	undefined field55_0x4f;
	undefined field56_0x50;
	undefined field57_0x51;
	undefined field58_0x52;
	undefined field59_0x53;
	undefined1 RegisteredObjectsCount; /* Created by retype action */
	undefined field61_0x55;
	undefined field62_0x56;
	undefined field63_0x57;
	undefined field64_0x58;
	undefined field65_0x59;
	undefined field66_0x5a;
	undefined field67_0x5b;
	undefined field68_0x5c;
	undefined field69_0x5d;
	undefined field70_0x5e;
	undefined field71_0x5f;
	undefined field72_0x60;
	undefined field73_0x61;
	undefined field74_0x62;
	undefined field75_0x63;
	undefined field76_0x64;
	undefined field77_0x65;
	undefined field78_0x66;
	undefined field79_0x67;
	undefined field80_0x68;
	undefined field81_0x69;
	undefined field82_0x6a;
	undefined field83_0x6b;
	undefined field84_0x6c;
	undefined field85_0x6d;
	undefined field86_0x6e;
	undefined field87_0x6f;
	undefined field88_0x70;
	undefined field89_0x71;
	undefined field90_0x72;
	undefined field91_0x73;
	undefined field92_0x74;
	undefined field93_0x75;
	undefined field94_0x76;
	undefined field95_0x77;
	void* SightLostEvent; /* Array-like, elements of 0x40 bytes, 0x400 static size */
	undefined field97_0x80;
	undefined field98_0x81;
	undefined field99_0x82;
	undefined field100_0x83;
	undefined field101_0x84;
	undefined field102_0x85;
	undefined field103_0x86;
	undefined field104_0x87;
	undefined field105_0x88;
	undefined field106_0x89;
	undefined field107_0x8a;
	undefined field108_0x8b;
	undefined field109_0x8c;
	undefined field110_0x8d;
	undefined field111_0x8e;
	undefined field112_0x8f;
	undefined field113_0x90;
	undefined field114_0x91;
	undefined field115_0x92;
	undefined field116_0x93;
	undefined field117_0x94;
	undefined field118_0x95;
	undefined field119_0x96;
	undefined field120_0x97;
	undefined field121_0x98;
	undefined field122_0x99;
	undefined field123_0x9a;
	undefined field124_0x9b;
	undefined field125_0x9c;
	undefined field126_0x9d;
	undefined field127_0x9e;
	undefined field128_0x9f;
	void* field129_0xa0;
	undefined field130_0xa8;
	undefined field131_0xa9;
	undefined field132_0xaa;
	undefined field133_0xab;
	undefined field134_0xac;
	undefined field135_0xad;
	undefined field136_0xae;
	undefined field137_0xaf;
	undefined field138_0xb0;
	undefined field139_0xb1;
	undefined field140_0xb2;
	undefined field141_0xb3;
	undefined field142_0xb4;
	undefined field143_0xb5;
	undefined field144_0xb6;
	undefined field145_0xb7;
	undefined field146_0xb8;
	undefined field147_0xb9;
	undefined field148_0xba;
	undefined field149_0xbb;
	undefined field150_0xbc;
	undefined field151_0xbd;
	undefined field152_0xbe;
	undefined field153_0xbf;
	undefined field154_0xc0;
	undefined field155_0xc1;
	undefined field156_0xc2;
	undefined field157_0xc3;
	undefined field158_0xc4;
	undefined field159_0xc5;
	undefined field160_0xc6;
	undefined field161_0xc7;
	void* field162_0xc8;
	undefined field163_0xd0;
	undefined field164_0xd1;
	undefined field165_0xd2;
	undefined field166_0xd3;
	undefined field167_0xd4;
	undefined field168_0xd5;
	undefined field169_0xd6;
	undefined field170_0xd7;
	undefined field171_0xd8;
	undefined field172_0xd9;
	undefined field173_0xda;
	undefined field174_0xdb;
	undefined field175_0xdc;
	undefined field176_0xdd;
	undefined field177_0xde;
	undefined field178_0xdf;
	undefined field179_0xe0;
	undefined field180_0xe1;
	undefined field181_0xe2;
	undefined field182_0xe3;
	undefined field183_0xe4;
	undefined field184_0xe5;
	undefined field185_0xe6;
	undefined field186_0xe7;
	undefined field187_0xe8;
	undefined field188_0xe9;
	undefined field189_0xea;
	undefined field190_0xeb;
	undefined field191_0xec;
	undefined field192_0xed;
	undefined field193_0xee;
	undefined field194_0xef;
	undefined field195_0xf0;
	undefined field196_0xf1;
	undefined field197_0xf2;
	undefined field198_0xf3;
	undefined field199_0xf4;
	undefined field200_0xf5;
	undefined field201_0xf6;
	undefined field202_0xf7;
	undefined field203_0xf8;
	undefined field204_0xf9;
	undefined field205_0xfa;
	undefined field206_0xfb;
	undefined field207_0xfc;
	undefined field208_0xfd;
	undefined field209_0xfe;
	undefined field210_0xff;
	undefined field211_0x100;
	undefined field212_0x101;
	undefined field213_0x102;
	undefined field214_0x103;
	undefined field215_0x104;
	undefined field216_0x105;
	undefined field217_0x106;
	undefined field218_0x107;
	undefined field219_0x108;
	undefined field220_0x109;
	undefined field221_0x10a;
	undefined field222_0x10b;
	undefined field223_0x10c;
	undefined field224_0x10d;
	undefined field225_0x10e;
	undefined field226_0x10f;
	undefined field227_0x110;
	undefined field228_0x111;
	undefined field229_0x112;
	undefined field230_0x113;
	undefined field231_0x114;
	undefined field232_0x115;
	undefined field233_0x116;
	undefined field234_0x117;
	undefined field235_0x118;
	undefined field236_0x119;
	undefined field237_0x11a;
	undefined field238_0x11b;
	undefined field239_0x11c;
	undefined field240_0x11d;
	undefined field241_0x11e;
	undefined field242_0x11f;
	undefined field243_0x120;
	undefined field244_0x121;
	undefined field245_0x122;
	undefined field246_0x123;
	undefined field247_0x124;
	undefined field248_0x125;
	undefined field249_0x126;
	undefined field250_0x127;
	undefined field251_0x128;
	undefined field252_0x129;
	undefined field253_0x12a;
	undefined field254_0x12b;
	undefined field255_0x12c;
	undefined field256_0x12d;
	undefined field257_0x12e;
	undefined field258_0x12f;
	undefined field259_0x130;
	undefined field260_0x131;
	undefined field261_0x132;
	undefined field262_0x133;
	undefined field263_0x134;
	undefined field264_0x135;
	undefined field265_0x136;
	undefined field266_0x137;
	undefined field267_0x138;
	undefined field268_0x139;
	undefined field269_0x13a;
	undefined field270_0x13b;
	undefined field271_0x13c;
	undefined field272_0x13d;
	undefined field273_0x13e;
	undefined field274_0x13f;
	undefined field275_0x140;
	undefined field276_0x141;
	undefined field277_0x142;
	undefined field278_0x143;
	undefined field279_0x144;
	undefined field280_0x145;
	undefined field281_0x146;
	undefined field282_0x147;
	undefined field283_0x148;
	undefined field284_0x149;
	undefined field285_0x14a;
	undefined field286_0x14b;
	undefined field287_0x14c;
	undefined field288_0x14d;
	undefined field289_0x14e;
	undefined field290_0x14f;
	undefined field291_0x150;
	undefined field292_0x151;
	undefined field293_0x152;
	undefined field294_0x153;
	undefined field295_0x154;
	undefined field296_0x155;
	undefined field297_0x156;
	undefined field298_0x157;
	undefined field299_0x158;
	undefined field300_0x159;
	undefined field301_0x15a;
	undefined field302_0x15b;
	undefined field303_0x15c;
	undefined field304_0x15d;
	undefined field305_0x15e;
	undefined field306_0x15f;
	undefined field307_0x160;
	undefined field308_0x161;
	undefined field309_0x162;
	undefined field310_0x163;
	undefined field311_0x164;
	undefined field312_0x165;
	undefined field313_0x166;
	undefined field314_0x167;
	undefined field315_0x168;
	undefined field316_0x169;
	undefined field317_0x16a;
	undefined field318_0x16b;
	undefined field319_0x16c;
	undefined field320_0x16d;
	undefined field321_0x16e;
	undefined field322_0x16f;
	void* field323_0x170;
	undefined field324_0x178;
	undefined field325_0x179;
	undefined field326_0x17a;
	undefined field327_0x17b;
	undefined field328_0x17c;
	undefined field329_0x17d;
	undefined field330_0x17e;
	undefined field331_0x17f;
	undefined field332_0x180;
	undefined field333_0x181;
	undefined field334_0x182;
	undefined field335_0x183;
	undefined field336_0x184;
	undefined field337_0x185;
	undefined field338_0x186;
	undefined field339_0x187;
	undefined field340_0x188;
	undefined field341_0x189;
	undefined field342_0x18a;
	undefined field343_0x18b;
	undefined field344_0x18c;
	undefined field345_0x18d;
	undefined field346_0x18e;
	undefined field347_0x18f;
	undefined field348_0x190;
	undefined field349_0x191;
	undefined field350_0x192;
	undefined field351_0x193;
	undefined field352_0x194;
	undefined field353_0x195;
	undefined field354_0x196;
	undefined field355_0x197;
	undefined field356_0x198;
	undefined field357_0x199;
	undefined field358_0x19a;
	undefined field359_0x19b;
	undefined field360_0x19c;
	undefined field361_0x19d;
	undefined field362_0x19e;
	undefined field363_0x19f;
	undefined field364_0x1a0;
	undefined field365_0x1a1;
	undefined field366_0x1a2;
	undefined field367_0x1a3;
	undefined field368_0x1a4;
	undefined field369_0x1a5;
	undefined field370_0x1a6;
	undefined field371_0x1a7;
	undefined field372_0x1a8;
	undefined field373_0x1a9;
	undefined field374_0x1aa;
	undefined field375_0x1ab;
	undefined field376_0x1ac;
	undefined field377_0x1ad;
	undefined field378_0x1ae;
	undefined field379_0x1af;
	void* field380_0x1b0;
	undefined field381_0x1b8;
	undefined field382_0x1b9;
	undefined field383_0x1ba;
	undefined field384_0x1bb;
	undefined field385_0x1bc;
	undefined field386_0x1bd;
	undefined field387_0x1be;
	undefined field388_0x1bf;
	undefined field389_0x1c0;
	undefined field390_0x1c1;
	undefined field391_0x1c2;
	undefined field392_0x1c3;
	undefined field393_0x1c4;
	undefined field394_0x1c5;
	undefined field395_0x1c6;
	undefined field396_0x1c7;
	undefined field397_0x1c8;
	undefined field398_0x1c9;
	undefined field399_0x1ca;
	undefined field400_0x1cb;
	undefined field401_0x1cc;
	undefined field402_0x1cd;
	undefined field403_0x1ce;
	undefined field404_0x1cf;
	undefined field405_0x1d0;
	undefined field406_0x1d1;
	undefined field407_0x1d2;
	undefined field408_0x1d3;
	undefined field409_0x1d4;
	undefined field410_0x1d5;
	undefined field411_0x1d6;
	undefined field412_0x1d7;
	undefined field413_0x1d8;
	undefined field414_0x1d9;
	undefined field415_0x1da;
	undefined field416_0x1db;
	undefined field417_0x1dc;
	undefined field418_0x1dd;
	undefined field419_0x1de;
	undefined field420_0x1df;
	undefined field421_0x1e0;
	undefined field422_0x1e1;
	undefined field423_0x1e2;
	undefined field424_0x1e3;
	undefined field425_0x1e4;
	undefined field426_0x1e5;
	undefined field427_0x1e6;
	undefined field428_0x1e7;
	undefined field429_0x1e8;
	undefined field430_0x1e9;
	undefined field431_0x1ea;
	undefined field432_0x1eb;
	undefined field433_0x1ec;
	undefined field434_0x1ed;
	undefined field435_0x1ee;
	undefined field436_0x1ef;
	undefined field437_0x1f0;
	undefined field438_0x1f1;
	undefined field439_0x1f2;
	undefined field440_0x1f3;
	undefined field441_0x1f4;
	undefined field442_0x1f5;
	undefined field443_0x1f6;
	undefined field444_0x1f7;
	undefined field445_0x1f8;
	undefined field446_0x1f9;
	undefined field447_0x1fa;
	undefined field448_0x1fb;
	undefined field449_0x1fc;
	undefined field450_0x1fd;
	undefined field451_0x1fe;
	undefined field452_0x1ff;
	undefined field453_0x200;
	undefined field454_0x201;
	undefined field455_0x202;
	undefined field456_0x203;
	undefined field457_0x204;
	undefined field458_0x205;
	undefined field459_0x206;
	undefined field460_0x207;
	undefined field461_0x208;
	undefined field462_0x209;
	undefined field463_0x20a;
	undefined field464_0x20b;
	undefined field465_0x20c;
	undefined field466_0x20d;
	undefined field467_0x20e;
	undefined field468_0x20f;
	undefined field469_0x210;
	undefined field470_0x211;
	undefined field471_0x212;
	undefined field472_0x213;
	undefined field473_0x214;
	undefined field474_0x215;
	undefined field475_0x216;
	undefined field476_0x217;
	undefined field477_0x218;
	undefined field478_0x219;
	undefined field479_0x21a;
	undefined field480_0x21b;
	undefined field481_0x21c;
	undefined field482_0x21d;
	undefined field483_0x21e;
	undefined field484_0x21f;
	undefined field485_0x220;
	undefined field486_0x221;
	undefined field487_0x222;
	undefined field488_0x223;
	undefined field489_0x224;
	undefined field490_0x225;
	undefined field491_0x226;
	undefined field492_0x227;
	undefined field493_0x228;
	undefined field494_0x229;
	undefined field495_0x22a;
	undefined field496_0x22b;
	undefined field497_0x22c;
	undefined field498_0x22d;
	undefined field499_0x22e;
	undefined field500_0x22f;
	undefined field501_0x230;
	undefined field502_0x231;
	undefined field503_0x232;
	undefined field504_0x233;
	undefined field505_0x234;
	undefined field506_0x235;
	undefined field507_0x236;
	undefined field508_0x237;
	undefined field509_0x238;
	undefined field510_0x239;
	undefined field511_0x23a;
	undefined field512_0x23b;
	undefined field513_0x23c;
	undefined field514_0x23d;
	undefined field515_0x23e;
	undefined field516_0x23f;
	undefined field517_0x240;
	undefined field518_0x241;
	undefined field519_0x242;
	undefined field520_0x243;
	undefined field521_0x244;
	undefined field522_0x245;
	undefined field523_0x246;
	undefined field524_0x247;
	undefined field525_0x248;
	undefined field526_0x249;
	undefined field527_0x24a;
	undefined field528_0x24b;
	undefined field529_0x24c;
	undefined field530_0x24d;
	undefined field531_0x24e;
	undefined field532_0x24f;
	undefined field533_0x250;
	undefined field534_0x251;
	undefined field535_0x252;
	undefined field536_0x253;
	undefined field537_0x254;
	undefined field538_0x255;
	undefined field539_0x256;
	undefined field540_0x257;
	undefined field541_0x258;
	undefined field542_0x259;
	undefined field543_0x25a;
	undefined field544_0x25b;
	undefined field545_0x25c;
	undefined field546_0x25d;
	undefined field547_0x25e;
	undefined field548_0x25f;
	undefined field549_0x260;
	undefined field550_0x261;
	undefined field551_0x262;
	undefined field552_0x263;
	undefined field553_0x264;
	undefined field554_0x265;
	undefined field555_0x266;
	undefined field556_0x267;
	undefined field557_0x268;
	undefined field558_0x269;
	undefined field559_0x26a;
	undefined field560_0x26b;
	undefined field561_0x26c;
	undefined field562_0x26d;
	undefined field563_0x26e;
	undefined field564_0x26f;
	undefined field565_0x270;
	undefined field566_0x271;
	undefined field567_0x272;
	undefined field568_0x273;
	undefined field569_0x274;
	undefined field570_0x275;
	undefined field571_0x276;
	undefined field572_0x277;
	void* field573_0x278;
};

END_SE()

BEGIN_NS(eoc)

struct PlayerUpgrade : public ProtectedGameObject<PlayerUpgrade>
{
	stats::Character* Stats;
	uint32_t AttributePoints;
	uint32_t CombatAbilityPoints;
	uint32_t CivilAbilityPoints;
	uint32_t TalentPoints;
	uint32_t Unknown;
	ObjectSet<int> Attributes;
	ObjectSet<int> Abilities;
	//stats::TalentArray Talents; // TODO
	ObjectSet<uint16_t> Traits;
	bool IsCustom;
};

struct PlayerCustomData : public ProtectedGameObject<PlayerCustomData>
{
	void* VMT;
	bool Initialized;
	bool CustomLookEnabled;
	STDWString Name;
	TranslatedString NameTranslated;
	FixedString ClassType;
	uint32_t SkinColor;
	uint32_t HairColor;
	uint32_t ClothColor1;
	uint32_t ClothColor2;
	uint32_t ClothColor3;
	bool IsMale;
	FixedString Race;
	FixedString OriginName;
	FixedString Icon;
	FixedString MusicInstrument;
	FixedString OwnerProfileID;
	FixedString ReservedProfileID;
	FixedString AiPersonality;
	FixedString Speaker;
	ScratchBuffer CustomIconImg;
};

struct SkillBarItem : public ProtectedGameObject<SkillBarItem>
{
	//SkillBarItemType Type; // TODO
	FixedString SkillOrStatId;
	ComponentHandle ItemHandle;
};

END_NS()

BEGIN_NS(esv)

struct Character
{
	static constexpr auto ObjectTypeIndex = ObjectHandleType::ServerCharacter;
	typedef enum Flags : char {
		Unknown = 0,
		Running = 8 /* As in, sprinting. */,
		IsBoss = 128
	};
	void** VMT; // TODO EocServerObject
	undefined1 Translate;
	undefined field2_0x9;
	undefined field3_0xa;
	undefined field4_0xb;
	undefined field5_0xc;
	undefined field6_0xd;
	undefined field7_0xe;
	undefined field8_0xf;
	undefined field9_0x10;
	undefined field10_0x11;
	undefined field11_0x12;
	undefined field12_0x13;
	ObjectHandle MyHandle;
	uint Flags0;
	undefined field15_0x1c;
	undefined field16_0x1d;
	undefined field17_0x1e;
	undefined field18_0x1f;
	FixedString CurrentLevelName;
	undefined1 Rotate;
	undefined field21_0x29;
	undefined field22_0x2a;
	undefined field23_0x2b;
	undefined field24_0x2c;
	undefined field25_0x2d;
	undefined field26_0x2e;
	undefined field27_0x2f;
	undefined field28_0x30;
	undefined field29_0x31;
	undefined field30_0x32;
	undefined field31_0x33;
	undefined field32_0x34;
	undefined field33_0x35;
	undefined field34_0x36;
	undefined field35_0x37;
	undefined field36_0x38;
	undefined field37_0x39;
	undefined field38_0x3a;
	undefined field39_0x3b;
	undefined field40_0x3c;
	undefined field41_0x3d;
	undefined field42_0x3e;
	undefined field43_0x3f;
	undefined field44_0x40;
	undefined field45_0x41;
	undefined field46_0x42;
	undefined field47_0x43;
	undefined field48_0x44;
	undefined field49_0x45;
	undefined field50_0x46;
	undefined field51_0x47;
	undefined field52_0x48;
	undefined field53_0x49;
	undefined field54_0x4a;
	undefined field55_0x4b;
	undefined1 Scale;
	undefined field57_0x4d;
	undefined field58_0x4e;
	undefined field59_0x4f;
	undefined field60_0x50;
	undefined field61_0x51;
	undefined field62_0x52;
	undefined field63_0x53;
	undefined field64_0x54;
	undefined field65_0x55;
	undefined field66_0x56;
	undefined field67_0x57;
	undefined field68_0x58;
	undefined field69_0x59;
	undefined field70_0x5a;
	undefined field71_0x5b;
	undefined field72_0x5c;
	undefined field73_0x5d;
	undefined field74_0x5e;
	undefined field75_0x5f;
	undefined field76_0x60;
	undefined field77_0x61;
	undefined field78_0x62;
	undefined field79_0x63;
	undefined field80_0x64;
	undefined field81_0x65;
	undefined field82_0x66;
	undefined field83_0x67;
	undefined field84_0x68;
	undefined field85_0x69;
	undefined field86_0x6a;
	undefined field87_0x6b;
	undefined field88_0x6c;
	undefined field89_0x6d;
	undefined field90_0x6e;
	undefined field91_0x6f;
	undefined field92_0x70;
	undefined field93_0x71;
	undefined field94_0x72;
	undefined field95_0x73;
	undefined field96_0x74;
	undefined field97_0x75;
	undefined field98_0x76;
	undefined field99_0x77;
	undefined field100_0x78;
	undefined field101_0x79;
	undefined field102_0x7a;
	undefined field103_0x7b;
	undefined field104_0x7c;
	undefined field105_0x7d;
	undefined field106_0x7e;
	undefined field107_0x7f;
	undefined field108_0x80;
	undefined field109_0x81;
	undefined field110_0x82;
	undefined field111_0x83;
	undefined field112_0x84;
	undefined field113_0x85;
	undefined field114_0x86;
	undefined field115_0x87;
	undefined field116_0x88;
	undefined field117_0x89;
	undefined field118_0x8a;
	undefined field119_0x8b;
	undefined field120_0x8c;
	undefined field121_0x8d;
	undefined field122_0x8e;
	undefined field123_0x8f;
	Flags Flags;
	undefined1 MoreFlags;
	undefined field126_0x92;
	undefined field127_0x93;
	undefined field128_0x94;
	undefined field129_0x95;
	undefined field130_0x96;
	undefined field131_0x97;
	undefined field132_0x98;
	undefined field133_0x99;
	undefined field134_0x9a;
	undefined field135_0x9b;
	undefined field136_0x9c;
	undefined field137_0x9d;
	undefined field138_0x9e;
	undefined field139_0x9f;
	void* SomethingScaleRelated;
	undefined field141_0xa8;
	undefined field142_0xa9;
	undefined field143_0xaa;
	undefined field144_0xab;
	undefined field145_0xac;
	undefined field146_0xad;
	undefined field147_0xae;
	undefined field148_0xaf;
	undefined1 AnimationOverride;
	undefined field150_0xb1;
	undefined field151_0xb2;
	undefined field152_0xb3;
	undefined field153_0xb4;
	undefined field154_0xb5;
	undefined field155_0xb6;
	undefined field156_0xb7;
	undefined1 SomeRefCount;
	char ScriptForceUpdate;
	undefined1 ForceSynch;
	undefined field160_0xbb;
	undefined field161_0xbc;
	undefined field162_0xbd;
	undefined field163_0xbe;
	undefined field164_0xbf;
	CDivinityStats_Character* Stats;
	ObjectHandle InventoryHandle;
	undefined field167_0xcc;
	undefined field168_0xcd;
	undefined field169_0xce;
	undefined field170_0xcf;
	undefined field171_0xd0;
	undefined field172_0xd1;
	undefined field173_0xd2;
	undefined field174_0xd3;
	undefined field175_0xd4;
	undefined field176_0xd5;
	undefined field177_0xd6;
	undefined field178_0xd7;
	undefined field179_0xd8;
	undefined field180_0xd9;
	undefined field181_0xda;
	undefined field182_0xdb;
	undefined field183_0xdc;
	undefined field184_0xdd;
	undefined field185_0xde;
	undefined field186_0xdf;
	undefined field187_0xe0;
	undefined field188_0xe1;
	undefined field189_0xe2;
	undefined field190_0xe3;
	undefined field191_0xe4;
	undefined field192_0xe5;
	undefined field193_0xe6;
	undefined field194_0xe7;
	undefined field195_0xe8;
	undefined field196_0xe9;
	undefined field197_0xea;
	undefined field198_0xeb;
	undefined field199_0xec;
	undefined field200_0xed;
	undefined field201_0xee;
	undefined field202_0xef;
	undefined1 Supervisor;
	undefined field204_0xf1;
	undefined field205_0xf2;
	undefined field206_0xf3;
	undefined field207_0xf4;
	undefined field208_0xf5;
	undefined field209_0xf6;
	undefined field210_0xf7;
	undefined field211_0xf8;
	undefined field212_0xf9;
	undefined field213_0xfa;
	undefined field214_0xfb;
	undefined field215_0xfc;
	undefined field216_0xfd;
	undefined field217_0xfe;
	undefined field218_0xff;
	void* OsirisTaskController; // TODO
	undefined1 SomeController1;
	undefined field221_0x109;
	undefined field222_0x10a;
	undefined field223_0x10b;
	undefined field224_0x10c;
	undefined field225_0x10d;
	undefined field226_0x10e;
	undefined field227_0x10f;
	undefined1 SomeController2;
	undefined field229_0x111;
	undefined field230_0x112;
	undefined field231_0x113;
	undefined field232_0x114;
	undefined field233_0x115;
	undefined field234_0x116;
	undefined field235_0x117;
	undefined1 SomeController3;
	undefined field237_0x119;
	undefined field238_0x11a;
	undefined field239_0x11b;
	undefined field240_0x11c;
	undefined field241_0x11d;
	undefined field242_0x11e;
	undefined field243_0x11f;
	undefined1 SomeController4;
	undefined field245_0x121;
	undefined field246_0x122;
	undefined field247_0x123;
	undefined field248_0x124;
	undefined field249_0x125;
	undefined field250_0x126;
	undefined field251_0x127;
	void* StatusMachine; // TODO
	void* SkillManager; // TODO
	undefined1 VariableManager;
	undefined field255_0x139;
	undefined field256_0x13a;
	undefined field257_0x13b;
	undefined field258_0x13c;
	undefined field259_0x13d;
	undefined field260_0x13e;
	undefined field261_0x13f;
	undefined field262_0x140;
	undefined field263_0x141;
	undefined field264_0x142;
	undefined field265_0x143;
	undefined field266_0x144;
	undefined field267_0x145;
	undefined field268_0x146;
	undefined field269_0x147;
	undefined field270_0x148;
	undefined field271_0x149;
	undefined field272_0x14a;
	undefined field273_0x14b;
	undefined field274_0x14c;
	undefined field275_0x14d;
	undefined field276_0x14e;
	undefined field277_0x14f;
	undefined field278_0x150;
	undefined field279_0x151;
	undefined field280_0x152;
	undefined field281_0x153;
	undefined field282_0x154;
	undefined field283_0x155;
	undefined field284_0x156;
	undefined field285_0x157;
	undefined field286_0x158;
	undefined field287_0x159;
	undefined field288_0x15a;
	undefined field289_0x15b;
	undefined field290_0x15c;
	undefined field291_0x15d;
	undefined field292_0x15e;
	undefined field293_0x15f;
	undefined field294_0x160;
	bool IsInCombat;
	undefined field296_0x162;
	undefined field297_0x163;
	undefined field298_0x164;
	undefined field299_0x165;
	undefined field300_0x166;
	undefined field301_0x167;
	undefined field302_0x168;
	undefined field303_0x169;
	undefined field304_0x16a;
	undefined field305_0x16b;
	float SurfaceDistanceCheck;
	float SurfaceTimerCheck;
	undefined field308_0x174;
	undefined field309_0x175;
	undefined field310_0x176;
	undefined field311_0x177;
	undefined field312_0x178;
	undefined field313_0x179;
	undefined field314_0x17a;
	undefined field315_0x17b;
	ObjectHandle SomeOtherCharacterHandle;
	ObjectHandle SomeCharacterHandle;
	undefined field318_0x184;
	undefined field319_0x185;
	undefined field320_0x186;
	undefined field321_0x187;
	undefined field322_0x188;
	undefined field323_0x189;
	undefined field324_0x18a;
	undefined field325_0x18b;
	undefined field326_0x18c;
	undefined field327_0x18d;
	undefined field328_0x18e;
	undefined field329_0x18f;
	undefined field330_0x190;
	undefined field331_0x191;
	undefined field332_0x192;
	undefined field333_0x193;
	undefined field334_0x194;
	undefined field335_0x195;
	undefined field336_0x196;
	undefined field337_0x197;
	undefined field338_0x198;
	undefined field339_0x199;
	undefined field340_0x19a;
	undefined field341_0x19b;
	undefined field342_0x19c;
	undefined field343_0x19d;
	undefined field344_0x19e;
	undefined field345_0x19f;
	undefined field346_0x1a0;
	undefined field347_0x1a1;
	undefined field348_0x1a2;
	undefined field349_0x1a3;
	undefined field350_0x1a4;
	undefined field351_0x1a5;
	undefined field352_0x1a6;
	undefined field353_0x1a7;
	undefined field354_0x1a8;
	undefined field355_0x1a9;
	undefined field356_0x1aa;
	undefined field357_0x1ab;
	undefined field358_0x1ac;
	undefined field359_0x1ad;
	undefined field360_0x1ae;
	undefined field361_0x1af;
	esv::PlanManager* PlanManager;
	undefined field363_0x1b8;
	undefined field364_0x1b9;
	undefined field365_0x1ba;
	undefined field366_0x1bb;
	uint8_t RemainingAoOCharges;
	undefined field368_0x1bd;
	undefined field369_0x1be;
	undefined field370_0x1bf;
	undefined field371_0x1c0;
	undefined field372_0x1c1;
	undefined field373_0x1c2;
	undefined field374_0x1c3;
	undefined field375_0x1c4;
	undefined field376_0x1c5;
	undefined field377_0x1c6;
	undefined field378_0x1c7;
	undefined field379_0x1c8;
	undefined field380_0x1c9;
	undefined field381_0x1ca;
	undefined field382_0x1cb;
	undefined field383_0x1cc;
	undefined field384_0x1cd;
	undefined field385_0x1ce;
	undefined field386_0x1cf;
	undefined field387_0x1d0;
	undefined field388_0x1d1;
	undefined field389_0x1d2;
	undefined field390_0x1d3;
	undefined field391_0x1d4;
	undefined field392_0x1d5;
	undefined field393_0x1d6;
	undefined field394_0x1d7;
	undefined field395_0x1d8;
	undefined field396_0x1d9;
	undefined field397_0x1da;
	undefined field398_0x1db;
	undefined field399_0x1dc;
	undefined field400_0x1dd;
	undefined field401_0x1de;
	undefined field402_0x1df;
	undefined field403_0x1e0;
	undefined field404_0x1e1;
	undefined field405_0x1e2;
	undefined field406_0x1e3;
	undefined field407_0x1e4;
	undefined field408_0x1e5;
	undefined field409_0x1e6;
	undefined field410_0x1e7;
	void* PlayerData; // TODO
	int ServerControlCount;
	undefined field413_0x1f4;
	undefined field414_0x1f5;
	undefined field415_0x1f6;
	undefined field416_0x1f7;
	undefined field417_0x1f8;
	undefined field418_0x1f9;
	undefined field419_0x1fa;
	undefined field420_0x1fb;
	undefined field421_0x1fc;
	undefined field422_0x1fd;
	undefined field423_0x1fe;
	undefined field424_0x1ff;
	undefined1 CombatData;
	undefined field426_0x201;
	undefined field427_0x202;
	undefined field428_0x203;
	undefined field429_0x204;
	undefined field430_0x205;
	undefined field431_0x206;
	undefined field432_0x207;
	undefined field433_0x208;
	undefined field434_0x209;
	undefined field435_0x20a;
	undefined field436_0x20b;
	undefined field437_0x20c;
	undefined field438_0x20d;
	undefined field439_0x20e;
	undefined field440_0x20f;
	undefined field441_0x210;
	undefined field442_0x211;
	undefined field443_0x212;
	undefined field444_0x213;
	undefined field445_0x214;
	undefined field446_0x215;
	undefined field447_0x216;
	undefined field448_0x217;
	undefined1 AnimationSetOverride;
	undefined field450_0x219;
	undefined field451_0x21a;
	undefined field452_0x21b;
	undefined field453_0x21c;
	undefined field454_0x21d;
	undefined field455_0x21e;
	undefined field456_0x21f;
	ComponentHandle PartyHandle;
	undefined1 MovementLock;
	undefined field459_0x225;
	undefined field460_0x226;
	undefined field461_0x227;
	undefined1 Treasures_m;
};

struct Party
{
	static constexpr auto ObjectTypeIndex = ObjectHandleType::ServerParty;

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
	CompactSet<Character*> CharacterSet; // TODO which set type is this exactly?
};


struct PartyManager : ComponentFactory<esv::Party>
{

};

struct PlanManager {
	struct ScriptParam
	{
		typedef enum ParamFlags : char {
			Set_m = 1,
			Readable = 128
		};
		typedef enum ParamType : char {
			WILDCARD = 0,
			INTEGER = 1,
			FLOAT = 2,
			STRING = 3,
			FIXEDSTRING = 4,
			Character = 5,
			Item = 6,
			Trigger = 7,
			RELATION_TYPE = 8,
			SKILL_ID = 9,
			SURFACE_TYPE = 10,
			STATUS_TYPE = 11,
			CHARACTERSTAT_TYPE = 12,
			ITEMSTAT_TYPE = 13,
			WEAPON_TYPE = 14,
			DAMAGE_TYPE = 15,
			TALENT_TYPE = 16,
			COMPARE_TYPE = 17,
			COMPARE_FUNCTION_TYPE = 18,
			FLOAT3 = 19,
			NOISE_TYPE = 20,
			CHARACTERTEMPLATE = 21,
			ITEMTEMPLATE = 22,
			PROJECTILETEMPLATE = 23,
			POTION_ID = 24,
			ABILITY = 25,
			DEATHTYPE = 26
		};
		void** VMT;
		uint16_t RefCount;
		ParamFlags Flags; /* Created by retype action */
		undefined Padding1;
		ParamType Type; /* Created by retype action */
		undefined Padding2[3];

		void* ScriptParamBuffer;
		uint64_t MoreFlags;;
		FixedString Name;
		Path ScriptPath;
	};
	struct PlanAction
	{
		//void** VMT; // TODO
		undefined field1_0x8;
		undefined field2_0x9;
		undefined field3_0xa;
		undefined field4_0xb;
		undefined field5_0xc;
		undefined field6_0xd;
		undefined field7_0xe;
		undefined field8_0xf;
		CompactSet<ScriptParam*> ScriptParams; // Set type unconfirmed
		undefined field10_0x18;
		undefined field11_0x19;

		virtual void dtor();
		virtual void unknown();
		virtual void Update(void* executionStruct, void* unknown, int* unknown2);
		virtual void unknown2();
		virtual void toScratchString();
		virtual void unknown3();
		virtual int GetType();
		virtual char* GetName();
	};
	struct PlanEvent
	{
		typedef enum Type : int32_t
		{
			OnInit = 0,
			OnLoaded = 1,
			OnShutdown = 2,
			OnCombatStarted = 3,
			OnCombatSwitched = 4,
			OnCombatEnded = 5,
			OnTurn = 6,
			OnTurnEnded = 7,
			OnVitalityChanged = 8,
			OnAttackOfOpportunity = 9,
			OnDamage = 10,
			OnBlock = 11,
			OnMiss = 12,
			OnCriticalHit = 13,
			OnDie = 14,
			OnCharacterStatus = 15,
			OnCharacterStatusRemoved = 16,
			OnItemStatus = 17,
			OnItemStatusRemoved = 18,
			OnSight = 19,
			OnLostSight = 20,
			OnCharacterEvent = 21,
			OnCharacterItemEvent = 22,
			OnItemEvent = 23,
			OnGlobalEventSet = 24,
			OnGlobalEventCleared = 25,
			OnUseItem = 26,
			OnPickupItem = 27,
			OnTimer = 28,
			OnItemDropped = 29,
			OnHeardCharacterNoise = 30,
			OnHeardItemNoise = 31,
			OnHeardMiscNoise = 32,
			OnIterateCharacter = 33,
			OnIterateItem = 34,
			OnStatusCreateVisuals = 35,
			OnStatusDestroyVisuals = 36,
			OnItemDestroyed = 37,
			OnItemOpened = 38,
			OnStoryOverride = 39,
			OnTriggerEnter = 40,
			OnTriggerLeave = 41,
			OnEnemyChanged = 42,
			OnTalentUnlocked = 43,
			OnCharacterClassChanged = 44,
			OnCharacterCreationStarted = 45,
			OnCharacterCreationStopped = 46,
			OnFunction = 47,
			OnSkillCast = 48,
			OnSkillCombatComment = 49,
			OnGrenadeLand = 50,
			OnCharacterApplyStatus = 51,
			OnItemApplyStatus = 52,
			OnActivate = 53,
			OnDeactivate = 54
		};
		undefined field0_0x0;
		undefined field1_0x1;
		undefined field2_0x2;
		undefined field3_0x3;
		undefined field4_0x4;
		undefined field5_0x5;
		undefined field6_0x6;
		undefined field7_0x7;
		Type EventType;
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
		CompactSet<ScriptParam*> Params; // Set type unconfirmed
	};
	struct Plan
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
		CompactSet<PlanAction*> PlanActionsSet;
		undefined field26_0x24;
		undefined field27_0x25;
		undefined field28_0x26;
		undefined field29_0x27;
		int NextActionIndex_m;
		undefined field31_0x2c;
		undefined field32_0x2d;
		undefined field33_0x2e;
		undefined field34_0x2f;
		FixedString Name;
		undefined field36_0x38;
		undefined field37_0x39;
		undefined field38_0x3a;
		undefined field39_0x3b;
		undefined field40_0x3c;
		undefined field41_0x3d;
		undefined field42_0x3e;
		undefined field43_0x3f;
		undefined field44_0x40;
		undefined field45_0x41;
		undefined field46_0x42;
		undefined field47_0x43;
		undefined field48_0x44;
		undefined field49_0x45;
		undefined field50_0x46;
		undefined field51_0x47;
		undefined field52_0x48;
		undefined field53_0x49;
		undefined field54_0x4a;
		undefined field55_0x4b;
		undefined field56_0x4c;
		undefined field57_0x4d;
		undefined field58_0x4e;
		undefined field59_0x4f;
		undefined field60_0x50;
		undefined field61_0x51;
		undefined field62_0x52;
		undefined field63_0x53;
		undefined field64_0x54;
		undefined field65_0x55;
		undefined field66_0x56;
		undefined field67_0x57;
		undefined field68_0x58;
		undefined field69_0x59;
		undefined field70_0x5a;
		undefined field71_0x5b;
		undefined field72_0x5c;
		undefined field73_0x5d;
		undefined field74_0x5e;
		undefined field75_0x5f;
		CompactSet<PlanEvent*> PlanEventsSet;
	};
	struct ScriptHolderEvent
	{
		void* VMT_m;
		CompactSet<Plan*> Plans;
		undefined field5_0x1c;
		undefined field6_0x1d;
		undefined field7_0x1e;
		undefined field8_0x1f;
	};
	struct ScriptHolder
	{
		ScriptHolderEvent Events[55];
	};
	struct PlanReaction
	{
		undefined field0_0x0;
		undefined field1_0x1;
		undefined field2_0x2;
		undefined field3_0x3;
		undefined field4_0x4;
		undefined field5_0x5;
		undefined field6_0x6;
		undefined field7_0x7;
		CompactSet<Plan*> PlanSet; // Set type unconfirmed
	};
	struct Script
	{
		// TODO!
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
		PlanReaction** PlanReactions; // Might be wrong?
		undefined field73_0x50;
		undefined field74_0x51;
		undefined field75_0x52;
		undefined field76_0x53;
		undefined1 PlanReactionsAmount;
		undefined field78_0x55;
		undefined field79_0x56;
		undefined field80_0x57;
		undefined field81_0x58;
		undefined field82_0x59;
		undefined field83_0x5a;
		undefined field84_0x5b;
		undefined field85_0x5c;
		undefined field86_0x5d;
		undefined field87_0x5e;
		undefined field88_0x5f;
		ScriptHolder* Plans; /* Ptr to static array? */
	};

	undefined field0_0x0;
	undefined field1_0x1;
	undefined field2_0x2;
	undefined field3_0x3;
	undefined field4_0x4;
	undefined field5_0x5;
	undefined field6_0x6;
	undefined field7_0x7;
	ObjectHandle GameObjectHandle;
	ObjectHandle EntityHandle; // Purpose unknown, often 0xbadfood
	void* SomePtr;
	undefined field11_0x18;
	undefined field12_0x19;
	undefined field13_0x1a;
	undefined field14_0x1b;
	undefined field15_0x1c;
	undefined field16_0x1d;
	undefined field17_0x1e;
	undefined field18_0x1f;
	undefined1 PlanReactionSet; /* Created by retype action */
	undefined field20_0x21;
	undefined field21_0x22;
	undefined field22_0x23;
	undefined field23_0x24;
	undefined field24_0x25;
	undefined field25_0x26;
	undefined field26_0x27;
	undefined field27_0x28;
	undefined field28_0x29;
	undefined field29_0x2a;
	undefined field30_0x2b;
	uint field31_0x2c;
	undefined field32_0x30;
	undefined field33_0x31;
	undefined field34_0x32;
	undefined field35_0x33;
	undefined field36_0x34;
	undefined field37_0x35;
	undefined field38_0x36;
	undefined field39_0x37;
	Script* Script;
	undefined1 Timer; /* Created by retype action */
	undefined field42_0x41;
	undefined field43_0x42;
	undefined field44_0x43;
	undefined field45_0x44;
	undefined field46_0x45;
	undefined field47_0x46;
	undefined field48_0x47;
	bool IsActive;
	bool Initialized;
	undefined field51_0x4a;
	undefined field52_0x4b;
	int SomeMode;
};

// TODO move!
struct ActivationManager
{
	struct EventList {
		void** VMT;
		CompactSet<PlanManager*> PlanManagers;
		undefined field12_0x1c;
		undefined field13_0x1d;
		undefined field14_0x1e;
		undefined field15_0x1f;
	};

	void** VMT;
	EventList EventLists[55];
};

END_NS()

BEGIN_NS(ecl)

struct PartyGroup
{

};

struct Party
{
	static constexpr auto ObjectTypeIndex = ObjectHandleType::ClientParty;

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
	Set<Character*> CharacterSet; // TODO which set type is this exactly?
	undefined field77_0x50;
	undefined field78_0x51;
	undefined field79_0x52;
	undefined field80_0x53;
	undefined field81_0x54;
	undefined field82_0x55;
	undefined field83_0x56;
	undefined field84_0x57;
	Set<PartyGroup*> PartyGroupSet;
};

struct PartyManager : ComponentFactory<ecl::Party>
{

};

struct PlayerCustomData : public eoc::PlayerCustomData {};

struct PlayerData : public ProtectedGameObject<PlayerData>
{
	ObjectSet<eoc::SkillBarItem> SkillBarItems;
	ObjectSet<uint32_t> LockedAbilities;
	Map<ComponentHandle, int> AttitudeOverrideMap;
	uint8_t SelectedSkillSet;
	__int64 field_60;
	char field_68;
	PlayerCustomData CustomData;
	char field_1C8;
	__int64 field_1D0;
	NetId PickpocketTargetNetID;
	NetId CorpseLootTargetNetID;
	bool HelmetOptionState;
	bool ArmorOptionState;
	int CachedTension;
	FixedString QuestSelected;
	ObjectSet<FixedString> MemorisedSkills;
	char field_210;
	char field_211;
	int NetID3;
	FixedString OriginalTemplate;
	FixedString Region;
};


struct Skill : public ProtectedGameObject<Skill>
{
	void* VMT;
	FixedString GUID_Unused;
	NetId NetID;
	ComponentHandle Handle;
	//SkillType Type; // TODO
	ComponentHandle OwnerHandle;
	FixedString SkillId;
	float ActiveCooldown;
	bool CanActivate;
	bool IsActivated;
	bool HasCooldown;
	bool IsLearned;
	bool ZeroMemory;
	int32_t CauseListSize;
	int32_t NumCharges;
	int32_t MaxCharges;
};


struct SkillManager : public ProtectedGameObject<SkillManager>
{
	using CheckSkillRequirementsProc = bool(SkillManager* self, stats::SkillPrototype* proto);

	SkillState* CurrentSkill;
	ComponentHandle OwnerHandle;
	Map<FixedString, Skill*> Skills;
};


struct CharacterBody : public ProtectedGameObject<CharacterBody>
{
	ComponentHandle CharacterHandle;
	Character* Character;
	FixedString NextAnimation;
	FixedString CurrentAnimation;
	std::array<FixedString, 2> AnimationOverride;
	float AnimRandom;
	float ClimbLoopDuration;
	FixedString QueuedAnimation;
	bool AnimationRunning;
	bool IsImmediate;
	bool WaitForLoad;
	float AnimationDuration;
	float SpeedScaledAnimationDuration;
	ActionState* ActionState;
};

// : public IEoCClientReplicatedObject ? TODO inherit from IGameObject
struct Character
{
	//static constexpr auto ComponentPoolIndex = EntityComponentIndex::Character;
	static constexpr auto ObjectTypeIndex = ObjectHandleType::ClientCharacter;

	using CheckSkillRequirementsProc = uint64_t(Character* self, FixedString const& skillId, Item* item);
	using GetSkillRequirementsProc = void(Character* character, FixedString const& skillId, Item* item, uint32_t checkRequirementFlags, eoc::Text& requirementsText);

	virtual void SetLight(FixedString*) = 0;
	virtual void* GetLight() = 0;
	virtual void RemoveLight() = 0;
	virtual FixedString* GetPlayerRace(bool returnPolymorph, bool excludeUninitialized) = 0;
	virtual FixedString* GetPlayerOrigin(bool returnPolymorph, bool excludeUninitialized) = 0;

	Status* GetStatus(ComponentHandle statusHandle) const;
	Status* GetStatus(NetId handle) const;

	int unknownInt;
	char unknown1[12];
	int Flags1;
	char unknown2[4];
	FixedString SomeFS;
	char unknown3[40];
	FixedString SomeFS2;
	char unknown4[16];
	void* Visual;
	void* Physics;
	char unknown5[8];
	void* AI;
	char unknown6[48];
	short SomeShort;
	char unknown7[6];
	char unknown8[32];
	uint32_t ReservedPlayerID_m;
	char unknown9[20];
	CDivinityStats_Character* Stats;
	ObjectHandle InventoryHandle;
	char unknown10[76];
	void* StatusMachine;
	void* SkillManager;
	char unknown11[25];
	bool SomeBool;
	char unknown12[22];
	FixedString AnotherFS;
	char unknown13[8];
	PlayerData* PlayerData;
	char unknown14[36]; // TODO FollowCharacterHandle
	uint32_t Flags2;
	char unknown15[11];
	TranslatedString* DisplayNameOverride;
	char unknown16[8];
	FixedString YetAnotherFS;


	//glm::vec3 WorldPos;
	////CharacterFlags Flags; // TODO
	//float AIBoundSize;
	//FixedString CurrentLevel;
	//glm::mat3 WorldRot;
	//float Scale;
	//glm::vec3 Velocity;
	//glm::vec3 MovementStartPosition;
	//glm::vec3 LadderPosition;
	//glm::vec3 MovementTargetPosition;
	//PhysicsObject* Physics;
	//void* Light;
	//eoc::Ai* AI;
	//int field_70;
	//UserId UserID;
	//int16_t ReservedForPlayerId;
	//int16_t ReservedForPlayerId2;
	//NetId NetID2;
	//NetId NetID3;
	//CharacterTemplate* CurrentTemplate;
	//CharacterTemplate* OriginalTemplate;
	//stats::Character* Stats;
	//ComponentHandle InventoryHandle;
	//MovementMachine* MovementMachine;
	//ActionMachine* ActionMachine;
	//void* SteeringMachine;
	//void* BehaviorMachine;
	//InputController* InputController;
	//void* NetworkController;
	//StatusController* StatusController;
	//DialogController* DialogController;
	//void* CharacterSupervisor;
	//StatusMachine* StatusMachine;
	//SkillManager* SkillManager;
	//int AnimType;
	//__int64 field_108;
	//CharacterBody* CharacterBody;
	//ComponentHandle OwnerCharacterHandle;
	//ComponentHandle CorpseOwnerHandle;
	//ComponentHandle CorpseCharacterHandle;
	//ComponentHandle LootedByHandle;
	//int field_138;
	//ComponentHandle HighlightCircleEffect;
	//ComponentHandle OH7;
	//ComponentHandle ViewConeEffectHandle;
	//int FeetStatusId;
	//float FootStepEffectTimer;
	//float RemainingMoveDistance;
	//int FootStepMaterialType;
	//PlayerData* PlayerData;
	//eoc::PlayerUpgrade PlayerUpgrade;
	////ObjectSet<SurfacePathInfluence> SurfacePathInfluences; // TODO
	//ObjectSet<FixedString> Tags;
	//float field_248;
	//float LifeTime;
	//float field_250;
	//std::array<EntityHandle, 3> SoundComponents;
	//ComponentHandle OH9;
	//ComponentHandle FollowCharacterHandle;
	//// TODO
	///*CharacterFlags3 Flags3;
	//CharacterFlags2 Flags2;*/
	//uint32_t field_284;
	//uint8_t Color;
	//uint8_t Team;
	//TranslatedString* DisplayNameOverride;
	//TranslatedString StoryDisplayName;
	//TranslatedString OriginalDisplayName;
	//ComponentHandle TalkingIconEffect;
	//float AnimationSpeed;
	//int SoundBoneIndex;
	//int PhysicsBoneIndex;
	//ObjectSet<FixedString> VoiceSet;
	//FixedString AnimationSetOverride;
	//float WalkSpeedOverride;
	//float RunSpeedOverride;
	//float SneakCheckTimer;
	//float FadeTimer;
	//ComponentHandle PartyHandle;
	//int PhysicsPickingState;
	//int CrimeState;
	//void* SoftBodyCollisionTemplate;
	//bool HasCloth;
	//void* RagdollTemplate;
	//uint32_t GMState;
	//int64_t DamageCounter;
	//int64_t HealCounter;
	//int64_t KillCounter;
	//ComponentHandle MovingProjectileHandle;
	//FixedString Archetype;
	//FixedString EquipmentColor;
	//int DialogId;
	//bool IsDialogAiControlled;
	//ObjectSet<ComponentHandle> SummonHandles;
	//Map<ComponentHandle, int> AttitudeMaps;
	//uint64_t ImmuneFlags;
	//__int64 field_4E0;
	//ObjectSet<FixedString> ItemTags;
	////VisualSetIndices VisualSetIndices; // TODO
	//bool CorpseLootable;
};

END_NS()
