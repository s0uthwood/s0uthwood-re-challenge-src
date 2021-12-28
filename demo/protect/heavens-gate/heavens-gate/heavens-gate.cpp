// heavens-gate.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <stdio.h>

#define EMIT(_val_) __asm __emit(_val_)

#define ENTER_X64()                                                         \
    {                                                                       \
    EMIT(0x6A) EMIT(0x33)                       /* push _cs */              \
    EMIT(0xE8) EMIT(0) EMIT(0) EMIT(0) EMIT(0)  /* call $+5 */              \
    EMIT(0x83) EMIT(4) EMIT(0x24) EMIT(5)       /* add dword [esp], 5 */    \
    EMIT(0xCB)                                  /* retf */                  \
    }

#define EXIT_X64()                                                                      \
    {                                                                                   \
    EMIT(0xE8) EMIT(0x00) EMIT(0x00) EMIT(0x00) EMIT(0x00)  /* call $+5 */              \
    EMIT(0xC7) EMIT(0x44) EMIT(0x24) EMIT(0x04) EMIT(0x23)  /* mov dword [rsp+4], cs */ \
    EMIT(0x00) EMIT(0x00) EMIT(0x00)                                                    \
    EMIT(0x83) EMIT(0x04) EMIT(0x24) EMIT(0x0D)             /* add dword [rsp] 0xD */   \
    EMIT(0xCB)                                              /* retf */                  \
    }

char cipher[101] = {0x56, 0x5c, 0x51, 0x57, 0x6b, 0x78, 0x55, 0x24, 0x66, 0x23, 0x5e, 0x63, 0x77, 0x51, 0x27, 0x55, 0x6d, 0x00};

__declspec(naked) void func(char* Input) {
    __asm {

        __emit 0x55
        __emit 0x48
        __emit 0x89
        __emit 0xE5
        __emit 0x48
        __emit 0x83
        __emit 0xEC
        __emit 0x10
        __emit 0x48
        __emit 0x89

        __emit 0x4D
        __emit 0x10
        __emit 0xC7
        __emit 0x45
        __emit 0xFC
        __emit 0x00
        __emit 0x00
        __emit 0x00
        __emit 0x00
        __emit 0xEB

        __emit 0x4A
        __emit 0x8B
        __emit 0x45
        __emit 0xFC
        __emit 0x48
        __emit 0x63
        __emit 0xD0
        __emit 0x48
        __emit 0x8B
        __emit 0x45

        __emit 0x10
        __emit 0x48
        __emit 0x01
        __emit 0xD0
        __emit 0x0F
        __emit 0xB6
        __emit 0x10
        __emit 0x8B
        __emit 0x45
        __emit 0xFC

        __emit 0x48
        __emit 0x63
        __emit 0xC8
        __emit 0x48
        __emit 0x8B
        __emit 0x45
        __emit 0x10
        __emit 0x48
        __emit 0x01
        __emit 0xC8

        __emit 0x83
        __emit 0xF2
        __emit 0x20
        __emit 0x88
        __emit 0x10
        __emit 0x8B
        __emit 0x45
        __emit 0xFC
        __emit 0x48
        __emit 0x63

        __emit 0xD0
        __emit 0x48
        __emit 0x8B
        __emit 0x45
        __emit 0x10
        __emit 0x48
        __emit 0x01
        __emit 0xD0
        __emit 0x0F
        __emit 0xB6

        __emit 0x00
        __emit 0x8D
        __emit 0x48
        __emit 0x10
        __emit 0x8B
        __emit 0x45
        __emit 0xFC
        __emit 0x48
        __emit 0x63
        __emit 0xD0

        __emit 0x48
        __emit 0x8B
        __emit 0x45
        __emit 0x10
        __emit 0x48
        __emit 0x01
        __emit 0xD0
        __emit 0x89
        __emit 0xCA
        __emit 0x88

        __emit 0x10
        __emit 0x83
        __emit 0x45
        __emit 0xFC
        __emit 0x01
        __emit 0x83
        __emit 0x7D
        __emit 0xFC
        __emit 0x10
        __emit 0x7E

        __emit 0xB0
        __emit 0x90
        __emit 0x48
        __emit 0x83
        __emit 0xC4
        __emit 0x10
        __emit 0x5D
        __emit 0xC3


    }

}

int main()
{
    char input[101] = {};
    printf("Do you know heaven's gate?\nInput flag to prove it:\n");
    scanf("%64s", input);
    __asm {
        lea ecx, input
        ENTER_X64()
        call func
        EXIT_X64()
    }
    for (int i = 0; i < 0x12; i++) {
        if (cipher[i] != input[i]) {
            printf("Wrong\n");
            return 0;
        }
    }
    printf("Good\n");
    return 0;
}
