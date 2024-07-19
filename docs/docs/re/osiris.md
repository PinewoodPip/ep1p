# Osiris

## Story Patching
Story patching is implemented directly within the Osiris dll (`ApplyPatchFile()` export), and thus likely present since Divine Divinity - just with a different way of triggering it per-game. In DOSEE, you can trigger it by manipulating version numbers within compiled stories:

1. Make a copy of `story.div.osi`, rename it to `StoryPatch.dat`
2. Open both files in a hex editor
3. Look for 1.6 text near the top (ignore "Version 1.5"), change that to 1.7 (or higher if you're patching a save 2nd time onwards) in both files
    - Each version digit appears to be uint8; using multiple digits should be safe as the game uses a string-split.
4. Repack the mod

During patching, two log files will be created in `Documents\Larian Studios\Divinity Original Sin Enhanced Edition\Temp` with the goals and DB migrations.

Interestingly, the game checks for the version number within `story.div.osi` to then decide if `StoryPatch.dat` should be loaded. Changing the version number only in `story.div.osi` appears to trigger patching but has a different execution flow; it's unknown what the difference is.