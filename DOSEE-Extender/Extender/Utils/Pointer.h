#pragma once
#include "GameDefinitions/UI.h"

BEGIN_SE()

class PointerUtils
{
public:
	static ecl::Character* GetLastPickerCharacter();
	static ecl::Character* GetCurrentPickerCharacter();
};

END_SE()