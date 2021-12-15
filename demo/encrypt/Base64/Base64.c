#include <stdio.h>
#include <string.h>

/* This is a public domain base64 implementation written by WEI Zhicheng. */

#define BASE64_PAD '='

/* BASE 64 encode table */
static const char base64en[] = {
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
};

unsigned int
base64_encode(const unsigned char *in, unsigned int inlen, char *out)
{
	int s;
	unsigned int i;
	unsigned int j;
	unsigned char c;
	unsigned char l;

	s = 0;
	l = 0;
	for (i = j = 0; i < inlen; i++) {
		c = in[i];

		switch (s) {
			case 0:
				s = 1;
				out[j++] = base64en[(c >> 2) & 0x3F];
				break;
			case 1:
				s = 2;
				out[j++] = base64en[((l & 0x3) << 4) | ((c >> 4) & 0xF)];
				break;
			case 2:
				s = 0;
				out[j++] = base64en[((l & 0xF) << 2) | ((c >> 6) & 0x3)];
				out[j++] = base64en[c & 0x3F];
				break;
		}
		l = c;
	}

	switch (s) {
		case 1:
			out[j++] = base64en[(l & 0x3) << 4];
			out[j++] = BASE64_PAD;
			out[j++] = BASE64_PAD;
			break;
		case 2:
			out[j++] = base64en[(l & 0xF) << 2];
			out[j++] = BASE64_PAD;
			break;
	}

	out[j] = 0;

	return j;
}

int main(){
    char plain[60];
    scanf("%40s", plain);
    char res[100];
    base64_encode(plain, strlen(plain), res);
    char cipher[] = "ZmxhZ3t5b3Vfc29sdmVkX0JBU0U2NF9jaGFsbH0=";
    if (!strcmp(cipher, res)){
        printf("Good\n");
    } else {
        printf("Wrong\n");
    }
    return 0;
}