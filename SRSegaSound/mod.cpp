#include "pch.h"
#include <mmsystem.h>
#include "resource.h"

extern HMODULE ModuleHandle;

DataPointer(int, FadeAmount, 0x7BCB28);
VoidFunc(ProcessFade, 0x409970);
void SegaSoundHook()
{
	ProcessFade();
	if (FadeAmount == 0)
		PlaySound(MAKEINTRESOURCE(IDR_WAVE1), ModuleHandle, SND_RESOURCE | SND_ASYNC);
}

extern "C"
{
	__declspec(dllexport) void Init(const char* path)
	{
		WriteCall((void*)0x444D72, SegaSoundHook);
	}

	__declspec(dllexport) ModInfo SonicRModInfo = { ModLoaderVer };
}