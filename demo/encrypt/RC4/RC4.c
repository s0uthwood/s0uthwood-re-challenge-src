#include <stdio.h>
#include <string.h>

#define swap(x,y)   do{typeof(x) t;t=x;x=y;y=t;}while(0)

// unsigned char flag[] = "flag{RC4_solved!}";
unsigned char cipher[] = {0x4b, 0x0a, 0x4c, 0xb0, 0x3d, 0x7e, 0x8b, 0x98, 0x1b, 0x6b, 0x7e, 0x80, 0x47, 0xb4, 0x82, 0x16, 0xc7, 0x00};

void RC4crypt(unsigned char * in, unsigned char * key, unsigned char * out){
    unsigned char SBOX[257];
    int key_len = strlen(key);
    int i, j;
    for (i = 0; i < 256; i++) {
        SBOX[i] = i;
    }
    j = 0;
    for (i = 0; i < 256; i++) {
        j = (j + SBOX[i] + key[i % key_len]) % 256;
        swap(SBOX[i], SBOX[j]);
    }
    i = j = 0;
    int in_len = strlen(in);
    for (int l = 0; l < in_len; l++, i++) {
        i %= 256;
        j += SBOX[i];
        j %= 256;
        swap(SBOX[i], SBOX[j]);
        out[l] = in[l] ^ SBOX[(SBOX[i] + SBOX[j]) % 256];
    }
    return;
}

int main(){
    unsigned char in[100];
    unsigned char out[100];
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    unsigned char key[] = "abc";
    scanf("%64s", in);
    RC4crypt(in, key, out);
    if (!strncmp(out, cipher, strlen(cipher))) {
        printf("Good\n");
    } else {
        printf("Wrong\n");
    }
    return 0;
}