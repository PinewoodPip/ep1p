// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#define NOMINMAX

// Windows Header Files:
#include <windows.h>
#include <synchapi.h>

#include <memory>
#include <cstdint>
#include <array>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <cassert>
#include <optional>
#include <unordered_map>
#include <functional>
#include <thread>
#include <utility>

#include <GameDefinitions/Base/Base.h>
#include <GameDefinitions/Base/BaseString.h>
#include "Utils.h"

#endif //PCH_H
