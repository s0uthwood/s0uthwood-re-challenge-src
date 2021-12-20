#include <stdio.h>
#include <string.h>

// flag{Process_Hollow!}
char input[101];
char key[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x1a, 0x06, 0x10, 0x2c, 0x00, 0x32, 0x19, 0x29, 0x04, 0x09, 0x2a, 0x03, 0x16, 0x46, 0x00};
char cipher[] = "flag{ThisIsAFakeFlag}";

int main(){
    printf("Please input your license:\n");
    scanf("%32s", input);
    if (strlen(input) != 21) {
        printf("Wrong\n");
        system("pause");
        return 0;
    }
    for (int i = 0; i < 21; i++){
        if (input[i] ^ key[i] ^ cipher[i]) {
            printf("Wrong\n");
            system("pause");
            return 0;
        }
    }
    printf("Good\n");
    system("pause");
    return 0;
}