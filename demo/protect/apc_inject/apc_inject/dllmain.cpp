// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include<stdio.h>
#include<windows.system.h>
#pragma warning(disable:4996)

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    char input[101];
    char key = 0x45;
    char cipher[] = { 0x23,0x29,0x24,0x22,0x3e,0x4,0x15,0x6,0x1a,0xc,0xb,0xf,0x0,0x6,0x11,0x38 };
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        system("cls");
        printf("Please input your flag:\n");
        scanf("%32s", input);
        if (strlen(input) != 16) {
            printf("Wrong\n");
            system("pause");
            return 0;
        }
        for (int i = 0; i < 16; i++) {
            if (input[i] ^ key ^ cipher[i]) {
                printf("Wrong\n");
                system("pause");
                return 0;
            }
        }
        printf("Good\n");
        getchar();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

