# Frequently-Asked Questions

## Why is the mod a .dll?
Ep1p uses code injection to make changes to the game that would not be possible with a regular `.pak` mod, similar to Norbyte's DOS2 Script Extender. The mod's repository is [available on GitHub](https://github.com/PinewoodPip/ep1p) and is buildable from source.

## Known issues
- When using the "Toggle Party Chain" hotkeys, the "Target group is too far away" notification can sometimes appear erroneously (benign issue).
- The "Fix skill range indicators" setting can cause seemingly random crashes on some PCs (at least on Nvidia setups)

## I have a GOG copy, can I use Ep1p?
Ep1p relies on finding patterns within game memory to make the necessary patches; these are different between the different builds of the game and were only reverse-engineered for the Steam build due to the massive time effort required.

However, if you have a GOG copy of the game, **replacing the executable (`EoCApp.exe`) with one from a Steam copy is enough to get Ep1p to work.**

## Can I rebind the new hotkeys?
As of v1.1.0.0 you can use the in-game settings menu to rebind hotkeys.

You can also rebind them by editing the mod's settings file (`Ep1pSettings.json`), which is created after modifying the settings at least once.

The relevant settings are the following; modifiers are set through separate settings suffixed with "`Modifier`":

- `ExamineHotkey`: hotkey to open the examine UI. Default is ++t++ (key #`55`)
- `TogglePartyChainKeybind`: hotkey to chain/unchain controlled characters.
- `TogglePartySneakKeybind`: hotkey to sneak/unsneak controlled characters.

Keys are identified by numerical IDs, as per the following table:

| Key name | ID |
| --------- | -------- |
| None | -1 |
| Return | 0 |
| Escape | 1 |
| Backspace | 2 |
| Tab | 3 |
| CapsLock | 4 |
| Space | 5 |
| PrintScreen | 6 |
| ScrollLock | 7 |
| Pause | 8 |
| Insert | 9 |
| Home | 10 |
| PageUp | 11 |
| Delete | 12 |
| End | 13 |
| PageDown | 14 |
| Comma | 15 |
| Minus | 16 |
| Dot | 17 |
| Slash | 18 |
| Semicolon | 19 |
| Equals | 20 |
| LeftSquareBracket | 21 |
| Backslash | 22 |
| RightSquareBracket | 23 |
| Backtick | 24 |
| Apostrophe | 25 |
| Num0 | 26 |
| Num1 | 27 |
| Num2 | 28 |
| Num3 | 29 |
| Num4 | 30 |
| Num5 | 31 |
| Num6 | 32 |
| Num7 | 33 |
| Num8 | 34 |
| Num9 | 35 |
| A | 36 |
| B | 37 |
| C | 38 |
| D | 39 |
| E | 40 |
| F | 41 |
| G | 42 |
| H | 43 |
| I | 44 |
| J | 45 |
| K | 46 |
| L | 47 |
| M | 48 |
| N | 49 |
| O | 50 |
| P | 51 |
| Q | 52 |
| R | 53 |
| S | 54 |
| T | 55 |
| U | 56 |
| V | 57 |
| W | 58 |
| X | 59 |
| Y | 60 |
| Z | 61 |
| F1 | 62 |
| F2 | 63 |
| F3 | 64 |
| F4 | 65 |
| F5 | 66 |
| F6 | 67 |
| F7 | 68 |
| F8 | 69 |
| F9 | 70 |
| F10 | 71 |
| F11 | 72 |
| F12 | 73 |
| F13 | 74 |
| F14 | 75 |
| F15 | 76 |
| F16 | 77 |
| F17 | 78 |
| F18 | 79 |
| F19 | 80 |
| F20 | 81 |
| F21 | 82 |
| F22 | 83 |
| F23 | 84 |
| F24 | 85 |
| Right | 86 |
| Left | 87 |
| Down | 88 |
| Up | 89 |
| NumLock | 90 |
| KP_Divide | 91 |
| KP_Multiply | 92 |
| KP_Minus | 93 |
| KP_Plus | 94 |
| KP_Enter | 95 |
| KP1 | 96 |
| KP2 | 97 |
| KP3 | 98 |
| KP4 | 99 |
| KP5 | 100 |
| KP6 | 101 |
| KP7 | 102 |
| KP8 | 103 |
| KP9 | 104 |
| KP0 | 105 |
| KP_Period | 106 |
| LCtrl | 107 |
| LShift | 108 |
| LAlt | 109 |
| LGUI | 110 |
| RCtrl | 111 |
| RShift | 112 |
| RAlt | 113 |
| RGUI | 114 |
| Mode | 115 |
| Left_2 | 116 |
| Middle | 117 |
| Right_2 | 118 |
| X1 | 119 |
| X2 | 120 |
| Motion | 121 |
| Motion_XNeg | 122 |
| Motion_YPos | 123 |
| Motion_XPos | 124 |
| Motion_YNeg | 125 |
| Wheel_XPos | 126 |
| Wheel_XNeg | 127 |
| Wheel_YPos | 128 |
| Wheel_YNeg | 129 |
| LeftStick_XNeg | 130 |
| LeftStick_YPos | 131 |
| LeftStick_XPos | 132 |
| LeftStick_YNeg | 133 |
| RightStick_XNeg | 134 |
| RightStick_YPos | 135 |
| RightStick_XPos | 136 |
| RightStick_YNeg | 137 |
| LeftTrigger | 138 |
| RightTrigger | 139 |
| A_2 | 140 |
| B_2 | 141 |
| X_2 | 142 |
| Y_2 | 143 |
| Back | 144 |
| Guide | 145 |
| Start | 146 |
| LeftStick | 147 |
| RightStick | 148 |
| LeftShoulder | 149 |
| RightShoulder | 150 |
| DPad_Up | 151 |
| DPad_Down | 152 |
| DPad_Left | 153 |
| DPad_Right | 154 |
| Touch_Tap | 155 |
| Touch_Hold | 156 |
| Touch_Pinch_In | 157 |
| Touch_Pinch_Out | 158 |
| Touch_Rotate | 159 |
| Touch_Flick | 160 |

## Older releases
For archival purposes, you can find all previous releases [here](https://drive.google.com/drive/folders/1KRuwsqnzpyH-EvKhXrqI357mbrriJehy?usp=drive_link). You can also use them in case of some *cathestrophe* where you need to downgrade. Ideally though, in such case you'd notify me what the issue is and I'd fix it.
