#pragma once

BEGIN_SE()

// TODO check
enum ObjectHandleType
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
	/*MeshProxy,
	SoundVolumeTrigger,
	Scene,
	GrannyFile,*/
	/*ServerCharacter,
	ServerItem,
	ServerProjectile,
	ServerInventory,
	ServerInventoryView,
	ServerParty,*/
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