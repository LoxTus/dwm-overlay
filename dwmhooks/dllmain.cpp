﻿// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "framework.h"
#include "Hooks.h"
void Initialize()
{
	//绘制回调返回类型定义为void
	if (Hooks::Install(Hooks::DemoDraw))
		MessageBox(NULL,L"Hook成功！",L"",MB_ICONINFORMATION);
	MH_EnableHook(MH_ALL_HOOKS);
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CloseHandle(CreateRemoteThread((HANDLE)-1, nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(Initialize), nullptr, 0, nullptr));
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

