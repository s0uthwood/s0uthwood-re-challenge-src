#include <stdio.h>
#include <string.h>
#include <stdint.h>

unsigned char cipher[] = {
    0xc4, 0xd3, 0x48, 0x84, 
    0x76, 0x17, 0xe8, 0x69,
    0xb9, 0xe6, 0xbb, 0xf9,
    0xb6, 0x97, 0x26, 0x71,
    0x00
};

void encrypt (uint32_t* v, uint32_t* k) {  
    uint32_t v0=v[0], v1=v[1], sum=0, i;           /* set up */  
    uint32_t delta=0x9e3779b9;                     /* a key schedule constant */  
    uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];   /* cache key */  
    for (i=0; i < 32; i++) {                       /* basic cycle start */  
        sum += delta;  
        v0 += ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);  
        v1 += ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);  
    }                                              /* end cycle */  
    v[0]=v0; v[1]=v1;
}

int main(){
    char input[101];
    memset(input, 0, sizeof(input));
    scanf("%64s", input);
    // flag{Drink_TEA!}
    int input_len = strlen(input);
    if (input_len != 0x10) {
        printf("Wrong\n");
        return 0;
    }
    uint32_t key[] = {0x11111111, 0x55555555, 0x99999999, 0xdddddddd};
    encrypt((uint32_t*)input, key);
    encrypt((uint32_t*)input+2, key);
    // printf("%x\n", *((uint32_t*)input));
    // printf("%x\n", *((uint32_t*)input + 1));
    // printf("%x\n", *((uint32_t*)input + 2));
    // printf("%x\n", *((uint32_t*)input + 3));
    if (!strncmp(input, cipher, input_len)) {
        printf("Good\n");
    } else {
        printf("Wrong\n");
    }
    return 0;
}
