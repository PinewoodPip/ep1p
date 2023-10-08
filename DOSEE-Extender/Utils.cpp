#include "pch.h"
#include "Utils.h"

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