#include <stdio.h>
#include <string.h>
#include <stdint.h>

unsigned char cipher[] = {
    0xfa, 0x3a, 0x06, 0x04,
    0x67, 0xb0, 0xcc, 0xca,
    0xd9, 0xe8, 0x80, 0x4b,
    0x54, 0xf5, 0x4d, 0x83,
    0x00
};

void encipher(unsigned int num_rounds, uint32_t v[2], uint32_t const key[4]) {  
    unsigned int i;
    uint32_t v0=v[0], v1=v[1], sum=0, delta=0x9E3779B9;
    for (i=0; i < num_rounds; i++) {
        v0 += (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3]);
        sum += delta;
        v1 += (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum>>11) & 3]);
    }
    v[0]=v0; v[1]=v1;
}

int main(){
    uint32_t key[] = {0x11111111, 0x22222222, 0x33333333, 0x44444444};
    uint8_t input[101];
    memset(input, 0, sizeof(input));
    scanf("%s", input);
    if (strlen(input) != 0x10) {
        printf("Wrong");
        return 0;
    }
    encipher(32u, (uint32_t*)input, key);
    encipher(32u, (uint32_t*)input+2, key);
    if (!strncmp(input, cipher, 0x10)) {
        printf("Good");
    } else {
        printf("Wrong");
    }
    return 0;
}
