#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int cmp[20] = {0x67616c66, 0x7530597b, 0x6f6e4b5f, 0x314c5f77, 0x336c7474, 0x646e455f, 0x5f6e3669, 0x6c336557, 0x7d31316c};
unsigned int new_cmp[20] = {0x7e356d7f, 0x6c645862, 0x763a4a46, 0x28185e6e, 0x2a38756d, 0x7d3a4446, 0x463a3770, 0x7567644e, 0x64653075};
unsigned int a[20];

int main() {
    printf("Please input your flag:\n");
    scanf("%50s", a);
    if (a[9] != 0) {
        printf("wrong length\n");
        exit(1);
    }
    for (int i = 0; i < 9; i++){
        if((unsigned int)0x19540119 != (a[i] ^ new_cmp[i])) {
            // printf("%d %x %x\n", i, a[i] ^ (unsigned int)0x19540119, new_cmp[i]);
            printf("Wrong!\n");
            return 0;
        }
    }
    printf("true\n");
    return 0;
}
