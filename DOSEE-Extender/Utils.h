#pragma once

#include <iostream>

extern HMODULE gThisModule;

#define BEGIN_SE() namespace dse {
#define END_SE() }

#define IDR_BINARY_MAPPINGS_EOCAPP      102

std::optional<std::string> GetExeResource(int resourceId);

[[noreturn]]
void Fail(char const* reason);

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

// TODO coloring
//#define ERR(msg, ...) Log(msg, __VA_ARGS__)
//#define WARN(msg, ...) Log(msg, __VA_ARGS__)
#define ERR(msg, ...) Log(msg, __VA_ARGS__)
#define WARN(msg, ...) Log(msg, __VA_ARGS__)
#define LOG(msg, ...) Log(msg, __VA_ARGS__)