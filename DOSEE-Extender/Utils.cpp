#include "pch.h"
#include "Utils.h"
#include <iostream>

BEGIN_SE()

STDString ToUTF8(WStringView s)
{
	int size = WideCharToMultiByte(CP_UTF8, 0, s.data(), (int)s.size(), NULL, 0, NULL, NULL);
	STDString converted;
	converted.resize(size);
	WideCharToMultiByte(CP_UTF8, 0, s.data(), (int)s.size(), converted.data(), (int)converted.size(), NULL, NULL);
	return converted;
}

STDWString FromUTF8(StringView s)
{
	int size = MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), NULL, 0);
	STDWString converted;
	converted.resize(size);
	MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), converted.data(), (int)converted.size());
	return converted;
}

std::wstring FromStdUTF8(StringView s)
{
	int size = MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), NULL, 0);
	std::wstring converted;
	converted.resize(size);
	MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), converted.data(), (int)converted.size());
	return converted;
}

END_SE()

// "Cannot overload functions distinguished only by return type" ?
//std::string ToUTF8(std::wstring_view s)
//{
//	int size = WideCharToMultiByte(CP_UTF8, 0, s.data(), (int)s.size(), NULL, 0, NULL, NULL);
//	std::string converted;
//	converted.resize(size);
//	WideCharToMultiByte(CP_UTF8, 0, s.data(), (int)s.size(), converted.data(), (int)converted.size(), NULL, NULL);
//	return converted;
//}
//
//std::wstring FromUTF8(std::string_view s)
//{
//	int size = MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), NULL, 0);
//	std::wstring converted;
//	converted.resize(size);
//	MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), converted.data(), (int)converted.size());
//	return converted;
//}

[[noreturn]]
void Fail(char const* reason)
{
#if defined(_DEBUG)
	if (IsDebuggerPresent()) {
		DebugBreak();
	}
#endif
	MessageBoxA(NULL, reason, "Script Extender Error", MB_OK | MB_ICONERROR);
	TerminateProcess(GetCurrentProcess(), 1);
}

//template <typename... Args>
//void Log(char const* msg, Args... args)
//{
//	char buf[1024];
//	_snprintf_s(buf, std::size(buf), _TRUNCATE, msg, args...);
//	std::cout << msg << buf << std::endl; // TODO coloring
//}

std::optional<std::string> GetExeResource(int resourceId)
{
	auto hResource = FindResource(gThisModule, MAKEINTRESOURCE(resourceId), L"SCRIPT_EXTENDER");

	if (hResource) {
		auto hGlobal = LoadResource(gThisModule, hResource);
		if (hGlobal) {
			auto resourceData = LockResource(hGlobal);
			if (resourceData) {
				DWORD resourceSize = SizeofResource(gThisModule, hResource);
				std::string contents;
				contents.resize(resourceSize);
				memcpy(contents.data(), resourceData, resourceSize);
				return contents;
			}
		}
	}

	ERR("Could not get bootstrap resource %d!", resourceId);
	return {};
}
