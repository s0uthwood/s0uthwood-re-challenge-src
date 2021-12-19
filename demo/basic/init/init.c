#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void __attribute__((constructor)) fuction();

unsigned char cipher[] = "flag{***********}";

int main(){
    unsigned char input[101];
    memset(input, 0, sizeof(input));
    scanf("%64s", input);
    if (!strncmp(input, cipher, 0x11)) {
        printf("Good\n");
    } else {
        printf("Wrong\n");
    }
    return 0;
}

void fuction(){
    unsigned char key[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x68, 0x4f, 0x4c, 0x45, 0x58, 0x4f, 0x75, 0x47, 0x4b, 0x43, 0x44, 0x00};
    for (int i = 0; i < 0x11; i++) {
        cipher[i] ^= key[i];
    }
    return;
}

// flag{Before_main}