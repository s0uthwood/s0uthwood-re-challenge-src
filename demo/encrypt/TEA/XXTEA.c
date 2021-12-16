#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define DELTA 0x9e3779b9  
#define MX (((z>>5^y<<2) + (y>>3^z<<4)) ^ ((sum^y) + (key[(p&3)^e] ^ z))) 

unsigned char cipher[] = {0x29, 0x2e, 0x80, 0x5d, 0xfa, 0x27, 0x04, 0xf5, 0x40, 0xd6, 0x59, 0xa0, 0xc9, 0xbc, 0x42, 0xa2, 0x00};

void btea(uint32_t *v, int n, uint32_t const key[4])  
{  
    uint32_t y, z, sum;
    unsigned p, rounds, e;
    rounds = 6 + 52/n;
    sum = 0;
    z = v[n-1];
    do {
        sum += DELTA;  
        e = (sum >> 2) & 3;  
        for (p=0; p<n-1; p++)  
        {  
            y = v[p+1];  
            z = v[p] += MX;  
        }  
        y = v[0];  
        z = v[n-1] += MX;  
    }  
    while (--rounds);
    return;
}

int main(){
    uint32_t key[] = {0x11111111, 0x22222222, 0x33333333, 0x44444444};
    uint8_t input[101];
    memset(input, 0, sizeof(input));
    scanf("%s", input);
    if (strlen(input) != 0x10) {
        printf("Wrong\n");
        return 0;
    }
    btea((uint32_t*)input, 4, key);
    // for (int i = 0; i < 16; i++){
    //     printf("%02hhx, ", input[i]);
    // }
    if (!strncmp(input, cipher, 0x10)) {
        printf("Good\n");
    } else {
        printf("Wrong\n");
    }
    return 0;
}
