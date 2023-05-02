#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define ROL(a,b) (((a) << (b)) | ((a) >> (32 - (b))))
#define QUARTERROUND(x, a, b, c, d) \
    x[b] ^= ROL(x[a] + x[d], 7); \
    x[c] ^= ROL(x[b] + x[a], 9); \
    x[d] ^= ROL(x[c] + x[b], 13); \
    x[a] ^= ROL(x[d] + x[c], 18);

void salsa20(uint32_t * in, uint32_t * out){
    for (int i = 0; i < 16; i++){
        out[i] = in[i];
    }
    for (int i = 0; i < 10; i++){
        QUARTERROUND(out,  0,  4,  8, 12);
        QUARTERROUND(out,  5,  9, 13,  1);
        QUARTERROUND(out, 10, 14,  2,  6);
        QUARTERROUND(out, 15,  3,  7, 11);
        QUARTERROUND(out,  0,  1,  2,  3);
        QUARTERROUND(out,  5,  6,  7,  4);
        QUARTERROUND(out, 10, 11,  8,  9);
        QUARTERROUND(out, 15, 12, 13, 14);
    }
    for (int i = 0; i < 16; i++){
        out[i] += in[i];
    }
    return;
}

uint32_t cipher[] = {0xe2efc1db, 0xe15d999f, 0xfe7c9e7a, 0x02dd418a, 0x7bcdc0bc, 0x6031df10, 0xc4a0e809, 0x91037f0f, 0x1a69b4ce, 0x9c01172e, 0x9b6a5a00, 0x83bcb615, 0x5caef8ab, 0x42a6128a, 0x8b7cf530, 0x974bad12};

int main(){
    uint8_t key[40];
    scanf("%36s", key);
    uint32_t *k = (uint32_t*) key;
    uint32_t c[] = {0x61707865, 0x3320646e, 0x79622d32, 0x6b206574};
    uint8_t nonce[] = {3,1,4,1,5,9,2,6};
    uint32_t *n = (uint32_t*) nonce;
    uint8_t block_counter[] = {7, 0, 0, 0, 0, 0, 0, 0};
    uint32_t *b = (uint32_t*) block_counter;
    uint32_t plain[16] = {c[0], k[0], k[1], k[2], k[3], c[1], n[0], n[1], b[0], b[1], c[2], k[4], k[5], k[6], k[7], c[3]};
    uint32_t out[16];
    salsa20(plain, out);
    // for (int i = 0; i < 16; i++) printf("0x%08x, ", out[i]);
    // printf("\n");
    for (int i = 0; i < 16; i++) {
        if (cipher[i] != out[i]) {
            printf("Wrong\n");
            return 0;
        }
    }
    printf("Good\n");
    return 0;
}

// flag{Salsa20_is_another_Stream!}