// this src is write for gcc on linux
// gcc -o junk junk.c -masm=intel
#include <stdio.h>
#include <string.h>

#define PART1 5
#define PART2 18
#define PART3 30
#define PART4 42
#define PART5 54

// flag{Congratulations!You_bypass_all_junk_in_this_chall}
// __asm__ ("movl %eax, %ebx/n/t"
        //  "movl $56, %esi/n/t"
        //  "movl %ecx, $label(%edx,%ebx,$4)/n/t"
        //  "movb %ah, (%ebx)");
// asm __volatile__ (".byte 0x12");
unsigned char input[101];
unsigned char cipher[] = "flag{Naawcsgaywcqv|`5LybG{ck}n}Pq}~L~`x|Gp}Ka~~kFys}qr}";

int main(){
    asm(".intel_syntax noprefix\n");
    int check = 0;
    scanf("%64s", input);
    // 1st junk:
    __asm__ __volatile__(
        "lea rbx, input[rip]\n\t"
        "cmp byte ptr [rbx], 'f'\n\t"
        "jnz fail\n\t"
        "cmp byte ptr [rbx+1], 'l'\n\t"
        "jnz fail\n\t"
        "cmp byte ptr [rbx+2], 'a'\n\t"
        "jnz fail\n\t"
        "cmp byte ptr [rbx+3], 'g'\n\t"
        "jnz fail\n\t"
        "cmp byte ptr [rbx+4], '{'\n\t"
        "jnz fail\n\t"
        "cmp byte ptr [rbx+54], '}'\n\t"
        "jnz fail\n\t"
    );
    printf("First check pass!\n");
    // 2nd junk:
    __asm__ __volatile__ (
        "xor rax, rax\n\t"
        "jz LABEL2\n\t"
        ".byte 0xE8\n\t"
        "LABEL2:\n\t"
    );
    for (int i = PART1; i < PART2; i++){
        input[i] ^= 0x0D + i - PART1;
        check |= input[i] ^ cipher[i];
    }
    if (check) goto fail;
    printf("Second check pass!\n");
    // 3rd junk
    __asm__ __volatile__ (
        "jz LABEL3\n\t"
        "jnz LABEL3\n\t"
        ".byte 0xE8\n\t"
        "LABEL3:\n\t"
    );
    for (int i = PART2; i < PART3; i++){
        input[i] ^= 0x12 + i - PART2;
        check |= input[i] ^ cipher[i];
    }
    if (check) goto fail;
    printf("Third check pass!\n");
    // 4th junk
    __asm__ __volatile__ (
        "call Sub4\n\t"
        ".byte 0xE8\n\t"
        "jmp Label4\n\t"
        "Sub4:\n\t"
        "add dword ptr [rsp], 1\n\t"
        "ret\n\t"
        "Label4:\n\t"
    );
    for (int i = PART3; i < PART4; i++){
        input[i] ^= 0x0E + i - PART3;
        check |= input[i] ^ cipher[i];
    }
    if (check) goto fail;
    printf("Fourth check pass!\n");
    // 5th junk
    __asm__ __volatile__ (
        "call    Sub5\n\t"
        ".byte   0xE8\n\t"
        "jmp     LABEL5\n\t"
        "Sub5:\n\t"
        "pop     rax\n\t"
        "add     rax, 1\n\t"
        "push    rax\n\t"
        "mov     rax, rsp\n\t"
        "xchg    rax, [rax]\n\t"
        "pop     rsp\n\t"
        "mov     [rsp+0], rax\n\t"
        "ret\n\t"
        "LABEL5:\n\t"
    );
    for (int i = PART4; i < PART5; i++){
        input[i] ^= 0x13 + i - PART4;
        check |= input[i] ^ cipher[i];
    }
    if (check) goto fail;
    printf("Fifth check pass!\n");
    printf("All junk code cleared!\n");
    return 0;
    fail:
    __asm__ __volatile__ ("fail:");
    printf("Wrong\n");
    return 0;
}
