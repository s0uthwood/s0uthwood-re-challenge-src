#include <stdio.h>

void func(char* in) {
	for (int i = 0; i < 0x11; i++) {
		in[i] ^= 0x20;
		in[i] += 0x10;
	}
	return;
}

int main() {
	char input[101] = {};
	scanf("%64s", input);
	func(input);
	char cipher[101] = { 0x56, 0x5c, 0x51, 0x57, 0x6b, 0x78, 0x55, 0x24, 0x66, 0x23, 0x5e, 0x63, 0x77, 0x51, 0x27, 0x55, 0x6d, 0x00 };
	for (int i = 0; i < 0x12; i++) {
		if (cipher[i] != input[i]) {
			printf("Wrong\n");
			return 0;
		}
	}
	printf("Good\n");
	return 0;
}
