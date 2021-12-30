#include <stdio.h>
#include <string.h>

#define PUSH_ARG    0
#define PUSH_EAX    1
#define PUSH_EBX    2
#define PUSH_ECX    3
#define POP_EAX     4
#define POP_EBX     5
#define POP_ECX     6
#define ADD_EAX_EBX 7
#define ADD_EAX_ARG 8
#define ADD_EBX_ARG 9
#define ADD_ECX_ARG 10
#define SUB_EAX_EBX 11
#define SUB_EAX_ARG 12
#define SUB_EBX_ARG 13
#define SUB_ECX_ARG 14
#define XOR_EAX_EBX 15
#define CMP_EAX_EBX 16
#define CALL_ARG    17
#define RET         18
#define JMP_ARG     19
#define JZ_ARG      20
#define PUSH_FLAG   21
#define POP_FLAG    22
#define EXIT        23

int stack[0x10001];
int esp, eip, eax, ebx, ecx, zf;
char opcode[0x10001] = {    17, 52, 0, 42, 5, 16, 20, 9, 23, 0, 36, 5, 3, 17, 29, 6, 0, 
    0, 5, 3, 17, 64, 6, 0, 72, 5, 17, 29, 23, 14, 1, 21, 4, 15, 
    1, 22, 2, 0, 0, 4, 3, 5, 16, 20, 50, 5, 9, 2, 19, 29, 5, 18, 
    21, 4, 16, 20, 61, 10, 1, 19, 52, 3, 4, 18, 14, 1, 21, 4, 7, 
    1, 22, 2, 0, 0, 4, 3, 5, 16, 20, 85, 5, 9, 1, 19, 64, 5, 18};
unsigned char flag[0x101];
unsigned char cipher[0x101] = {0xA3, 0xD8, 0xAC, 0xA9, 0xA8, 0xD6, 0xA6, 0xCD, 0xD0, 0xD5, 0xF7, 0xB7, 0x9C, 0xAB, 0x2E, 0x32, 0x43, 0x31, 0x52, 0x4E, 0x49, 0xFC, 0x46, 0x3C, 0x56, 0x43, 0x56, 0x52, 0x0E, 0x3C, 0x3F, 0x3B, 0x3B, 0x03, 0x08, 0x21, 0x1E, 0x16, 0x36, 0x30, 0x2E, 0x11};

#define PUSH(op) stack[esp] = op; esp += 1
#define POP(op) esp -= 1; op = stack[esp]

int main(int argc, char **argv) {
    // if (argc != 2) {
    //     printf("Usage: ./vm binary_file");
    //     return 1;
    // }
    // FILE *fp = fopen(argv[1], "r+");
    // fread(opcode, sizeof(opcode), 1, fp);
    // printf("%s", opcode);
    printf("Input flag:\n");
    scanf("%s", flag);
    // int oplen = strlen(opcode);
    int next_eip = eip;
    int cur_arg = 0;
    int cur_op = 0;
    while (1) {
        eip = next_eip;
        cur_op = opcode[eip];
        switch (cur_op) {
            case PUSH_ARG:
            case ADD_EAX_ARG:
            case ADD_EBX_ARG:
            case ADD_ECX_ARG:
            case SUB_EAX_ARG:
            case SUB_EBX_ARG:
            case SUB_ECX_ARG:
            case CALL_ARG:
            case JMP_ARG:
            case JZ_ARG:
                next_eip = eip + 1;
                cur_arg = opcode[next_eip];
                break;
            default:
                break;
        }
        // printf("eip: %X, esp: %X, arg: %X\n", eip, esp, cur_arg);
        switch (cur_op) {
            case PUSH_ARG:
                PUSH(cur_arg);
                next_eip += 1;
                break;
            case PUSH_EAX:
                PUSH(eax);
                next_eip += 1;
                break;
            case PUSH_EBX:
                PUSH(ebx);
                next_eip += 1;
                break;
            case PUSH_ECX:
                PUSH(ecx);
                next_eip += 1;
                break;
            case POP_EAX:
                POP(eax);
                next_eip += 1;
                break;
            case POP_EBX:
                POP(ebx);
                next_eip += 1;
                break;
            case POP_ECX:
                POP(ecx);
                next_eip += 1;
                break;
            case ADD_EAX_EBX:
                eax += ebx;
                next_eip += 1;
                break;
            case ADD_EAX_ARG:
                eax += cur_arg;
                next_eip += 1;
                break;
            case ADD_EBX_ARG:
                ebx += cur_arg;
                next_eip += 1;
                break;
            case ADD_ECX_ARG:
                ecx += cur_arg;
                next_eip += 1;
                break;
            case SUB_EAX_EBX:
                eax -= ebx;
                next_eip += 1;
                break;
            case SUB_EAX_ARG:
                eax -= cur_arg;
                next_eip += 1;
                break;
            case SUB_EBX_ARG:
                ebx -= cur_arg;
                next_eip += 1;
                break;
            case SUB_ECX_ARG:
                ecx -= cur_arg;
                next_eip += 1;
                break;
            case XOR_EAX_EBX:
                eax ^= ebx;
                next_eip += 1;
                break;
            case CMP_EAX_EBX:
                zf = eax == ebx;
                next_eip += 1;
                break;
            case CALL_ARG:
                // stack[esp] = eip + 2;
                // esp += 1;
                PUSH(eip + 2);
                next_eip = cur_arg;
                break;
            case RET:
                POP(next_eip);
                break;
            case JMP_ARG:
                next_eip = cur_arg;
                break;
            case JZ_ARG:
                if (zf) {
                    next_eip = cur_arg;
                } else {
                    next_eip += 1;
                }
                break;
            case PUSH_FLAG:
                PUSH(flag[ecx] & 0xff);
                next_eip += 1;
                break;
            case POP_FLAG:
                POP(flag[ecx]);
                next_eip += 1;
                break;
            case EXIT:
                goto LABEL1;
                break;
        }
    }
LABEL1:
    for (int i = 0; i < 43; i++) {
        if (flag[i] != cipher[i]) {
            printf("Wrong\n");
            return 0;
        }
    }
    printf("Good\n");
    return 0;
}
