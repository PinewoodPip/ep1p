# Patchnotes

## v1.1.0.0 - 4/10/2025 - 1st anniversary-ish update!
Surprise!!! Ep1p is epiback with more DOS1 goodies!!!

This patch adds various new hotkeys & features that I somehow didn't think about last year, including a plethora of usability improvements to dialogues in multiplayer, making them less of a pain for players listening!

!!! info ""
    Note that the files in the `Data/Public/Game/GUI` folder have changed; when updating, make sure to copy all its files and replace previous ones if necessary.

### Hotkeys
- Added a hotkey to chain/unchain all your controlled characters ("*Toggle Party Chain*"), unbound by default.
- Added a hotkey to sneak/unsneak all your controlled characters ("*Toggle Party Sneak*"), unbound by default.
- Ep1p hotkeys can now be set through within the in-game control settings UI; they'll display at the top, prefixed with "*Ep1p*"
    - Currently, you can only set one binding per hotkey.

### Dialogue improvements
- Added a setting to allow rotating the camera while in dialogue ("*Allow rotating camera in dialogue*")
- Added a setting to automatically stop listening to dialogues in multiplayer when the dialogue ends ("*Automatically stop listening to dialogues*")
- Added a setting to automatically scroll dialogues while listening when new lines are added ("*Automatically scroll listened dialogues*")

### Other additions & improvements
- The "*Examine*" hotkey now supports binding a modifier (++shift++/++ctrl++/++alt++)
- Added a setting to allow looting containers by clicking their world tooltips, like in Epip ("*Loot containers through world tooltips*" setting)
- Added context menu options to allow toggling helmet visibility while playing with controllers; within the equipment UI, open the context menu for the equipped helmet and select the new "*Hide helmet*", "*Always show helmet*" or "*Only show helmet in combat*" context menu options.
    - Due to technical limitations, the changes will only be reflected after you exit the UI.

### Fixes
- Fixed unbound keybinds not serializing properly in the settings json file (benign issue)

## v1.0.0.0 - 31/07/2024
This patch contains some requested changes to existing features:

- The auto-identify setting has been reworked into a dropdown with 3 modes: "*Disabled*", "*With requirements*", and "*Always*"
    - "*With requirements*" will auto-identify items only if any party member has enough loremaster and the party inventory has an identifying glass. The identifying glass must be in the character inventories (not bags).
    - "*Always*" works like the previous checkbox
    - If you had auto-identify enabled before, you must re-configure it
- Pressing the examine hotkey while hovering over the same character (or no character) will close the examine UI
- The target healthbar UI now shows armor and its physical damage reduction for player characters, instead of their pierce/slash/crush resistance
    - The physical damage reduction shown is against enemies of the same level as the character, like in the character sheet tooltip
- Equipment that is unrepairable is no longer affected by the "*Unlimited Equipment Durability*" setting

Since no large issues have been found I'm promoting the mod to v1.0 to make it look less scary.

## v0.9.0.1 - 21/07/2024
Reuploaded the mod without linking debug libraries so that the `.dll` runs without Visual Studio installed. Epic fail lol.

## v0.9.0.0 - 20/07/2024

Initial release for testing with the homies.