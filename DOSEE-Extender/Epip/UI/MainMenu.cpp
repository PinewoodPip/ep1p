#include "pch.h"
#include <format>
#include "MainMenu.h"
#include "Extender/ScriptExtender.h"

using namespace dse;
using namespace epip;

void MainMenu::Setup()
{
	gExtender->GetHooks().RegisterUIListener((int)UIObject::TypeID::MainMenu, this);
}

bool MainMenu::OnInvoke1(UIObject* ui, int64_t invokeEnum, ig::InvokeDataValue* invokeData1)
{
	if (invokeEnum == (int64_t)UIMainMenu::Invokes::setDebugText)
	{
        // https://stackoverflow.com/a/940743
        LPWSTR filenameOut = new wchar_t[255];
        GetModuleFileName(gExtender->GetModuleHandle(), filenameOut, 255);
        DWORD verHandle = 0;
        UINT size = 0;
        LPBYTE lpBuffer = NULL;
        DWORD verSize = GetFileVersionInfoSize(filenameOut, &verHandle);
        int major, minor, build, patch;
        bool foundVersion = false;
        if (verSize != NULL)
        {
            LPSTR verData = new char[verSize];

            if (GetFileVersionInfo(filenameOut, verHandle, verSize, verData))
            {
                if (VerQueryValue(verData, L"\\", (VOID FAR * FAR*) & lpBuffer, &size))
                {
                    if (size)
                    {
                        VS_FIXEDFILEINFO* verInfo = (VS_FIXEDFILEINFO*)lpBuffer;
                        if (verInfo->dwSignature == 0xfeef04bd)
                        {
                            major = (verInfo->dwFileVersionMS >> 16) & 0xffff;
                            minor = (verInfo->dwFileVersionMS >> 0) & 0xffff;
                            build = (verInfo->dwFileVersionLS >> 16) & 0xffff;
                            patch = (verInfo->dwFileVersionLS >> 0) & 0xffff;
                            foundVersion = true;
                        }
                    }
                }
            }
            delete[] verData;
        }
        delete[] filenameOut;

        if (foundVersion)
        {
            // Append Ep1p version
            std::string originalString = std::string(invokeData1->StringVal.c_str());
            std::string str = std::format("{}<br>Ep1p v{}.{}.{}.{}", originalString, major, minor, build, patch);
            STDString newStr = STDString(str.begin(), str.end());
            invokeData1->StringVal = newStr;
        }
	}
	return false;
}
