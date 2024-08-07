#pragma once

#include <iostream>

extern HMODULE gThisModule;

#define BEGIN_SE() namespace dse {
#define END_SE() }

#define IDR_BINARY_MAPPINGS_EOCAPP      102
#define IDR_BINARY_MAPPINGS_EOCPLUGIN      109

inline std::string StringToUTF8(std::wstring_view s)
{
	int size = WideCharToMultiByte(CP_UTF8, 0, s.data(), (int)s.size(), NULL, 0, NULL, NULL);
	std::string converted;
	converted.resize(size);
	WideCharToMultiByte(CP_UTF8, 0, s.data(), (int)s.size(), converted.data(), (int)converted.size(), NULL, NULL);
	return converted;
}

inline std::wstring StringFromUTF8(std::string_view s)
{
	int size = MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), NULL, 0);
	std::wstring converted;
	converted.resize(size);
	MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), converted.data(), (int)converted.size());
	return converted;
}

std::optional<std::string> GetExeResource(int resourceId);

[[noreturn]]
void Fail(char const* reason);

template <typename... Args>
void Log(std::string msg, Args... args)
{
	char buf[1024];
	_snprintf_s(buf, std::size(buf), _TRUNCATE, msg, args...);
	std::cout << buf << std::endl;
	std::cout.flush();
}

template <typename... Args>
void Log(char const* msg, Args... args)
{
	char buf[1024];
	_snprintf_s(buf, std::size(buf), _TRUNCATE, msg, args...);
	std::cout << buf << std::endl;
	std::cout.flush();
}

template <typename... Args>
void Log(wchar_t const* msg, Args... args)
{
	wchar_t buf[1024];
	_snwprintf_s(buf, std::size(buf), _TRUNCATE, msg, args...);
	std::wcout << buf << std::endl; // TODO coloring
	std::wcout.flush();
}

template <typename... Args>
void _LogNoEndline(char const* msg, Args... args)
{
	char buf[1024];
	_snprintf_s(buf, std::size(buf), _TRUNCATE, msg, args...);
	std::cout << buf; // TODO coloring
	std::cout.flush();
}

#define OsiError(msg) { \
	std::stringstream ss; \
	ss << __FUNCTION__ "(): " msg; \
	std::string str = ss.str(); \
	ERR(str); \
}

// TODO coloring
//#define ERR(msg, ...) Log(msg, __VA_ARGS__)
//#define WARN(msg, ...) Log(msg, __VA_ARGS__)
#define ERR(msg, ...) Log(msg, __VA_ARGS__)
#define WARN(msg, ...) Log(msg, __VA_ARGS__)
#define LOG(msg, ...) Log(msg, __VA_ARGS__)
#define LOG_NO_ENDL(msg, ...) _LogNoEndline(msg, __VA_ARGS__);
