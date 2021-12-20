#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int smc(){
	char cipher[] = {0x70,0x7a,0x77,0x71,0x6d,0x45,0x5b,0x55,0x6b,0};
	char input[50];
	char key = 0x16;
    printf("Please input your license:\n");
    scanf("%32s", input);
    if (strlen(input) != 9) {
        printf("Wrong\n");
        getchar();
        return 0;
    }
    for (int i = 0; i < 9; i++){
        if (input[i] ^ cipher[i] ^ key) {
            printf("Wrong\n");
            getchar();
			return 0;
        }
    }
    printf("Good\n");
    getchar();
}

int main(){
  int i = 0;
  unsigned char *p = smc;
  for(i = 0; i < 171; i ++){
  	*(p+i) = *(p+i)^0x20;
  }
  smc();
	return 0;
}
