#include "pch.h"
#include "Text.h"
#include <format>

std::string Text::Colorize(std::string str, std::string hexColor)
{
	return std::format("<font color='{}'>{}</font>", hexColor, str);
}