#include "pch.h"
#include <string.h>

#include "NoSound.h"
#include <minwindef.h>
#include <Windows.h>


EXPORT void CALL GetDllInfo(PLUGIN_INFO* PluginInfo)
{
	PluginInfo->Version = 0x0100; // 0x0100
	PluginInfo->Type = PLUGIN_TYPE_SOUND;
	wsprintfA(PluginInfo->Name, PLUGIN_NAME); // wsprintf will not work because this confuses the preprocessor
}

EXPORT void CALL DllAbout(HWND hParent)
{
	MessageBox(hParent, L"No sound\nby Aurumaker72", L"", MB_ICONINFORMATION | MB_OK);
}

