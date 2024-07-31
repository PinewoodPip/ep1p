# Patchnotes

## v1.0.0.0 - 31/07/2024
This patch contains some requested changes to existing features:

- The auto-identify setting has been reworked into a dropdown with 3 modes: "Disabled", "With requirements", and "Always"
    - "With requirements" will auto-identify items only if any party member has enough loremaster and the party inventory has an identifying glass. The identifying glass must be in the character inventories (not bags).
    - "Always" works like the previous checkbox
    - If you had auto-identify enabled before, you must re-configure it
- Pressing the examine hotkey while hovering over the same character (or no character) will close the examine UI
- The target healthbar UI now shows armor and its physical damage reduction for player characters, instead of their pierce/slash/crush resistance
    - The physical damage reduction shown is against enemies of the same level as the character, like in the character sheet tooltip
- Equipment that is unrepairable is no longer affected by the "Unlimited Equipment Durability" setting

Since no large issues have been found I'm promoting the mod to v1.0 to make it look less scary.

## v0.9.0.1 - 21/07/2024
Reuploaded the mod without linking debug libraries so that the `.dll` runs without Visual Studio installed. Epic fail lol.

## v0.9.0.0 - 20/07/2024

Initial release for testing with the homies.