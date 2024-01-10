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

END_NS()

BEGIN_NS(ecl)

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

// : public IEoCClientReplicatedObject ?
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
