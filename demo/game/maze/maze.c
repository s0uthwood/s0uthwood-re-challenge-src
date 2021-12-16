#include <stdio.h>
#include <string.h>
#include <stdint.h>

char map[] = {
    '*', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1',
    '1', '0', '1', '0', '1', '0', '1', '1', '1', '0', '0', '0', '0', '1', '0', '0',
    '1', '0', '0', '0', '1', '0', '0', '0', '1', '1', '0', '1', '0', '1', '1', '1',
    '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '1', '0', '0', '1',
    '1', '0', '0', '1', '1', '1', '0', '1', '1', '0', '1', '0', '1', '0', '1', '1',
    '1', '0', '1', '0', '1', '0', '0', '0', '1', '1', '1', '0', '0', '0', '1', '0',
    '1', '1', '1', '0', '1', '1', '0', '1', '1', '0', '0', '0', '0', '0', '1', '#',
    '\0'
};

int main() {
    int col = 0, row = 0;
    char a;
    while (1) {
        a = getchar();
        if (a == 'w'){
            row--;
        } else if (a == 'a') {
            col--;
        } else if (a == 's') {
            row++;
        } else if (a == 'd') {
            col++;
        } else {
            printf("Invalid input\n");
            break;
        }
        if (col < 0 || col > 15) {
            printf("Invalid input\n");
            break;
        }
        if (row < 0 || row > 6) {
            printf("Invalid input\n");
            break;
        }
        if (map[row * 16 + col] == '0') {
            printf("Invalid input\n");
            break;
        }
        if (map[row * 16 + col] == '#') {
            printf("Great! Your input is the flag!\n");
            break;
        }
    }
    return 0;
}
