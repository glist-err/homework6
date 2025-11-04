#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* RLE(char* str) {
    int length = strlen(str);

    char *code = (char*)malloc(2 * length + 1); // Код строки

    int code_pos = 0;

    for (int i = 0; i < length;) {
        char letter = str[i];   // Буква
        int count= 0;           // Сколько повторов

        while (i < length && str[i] == letter) {
            count++;
            i++;
        }
        
        // Записываем резулльтат
        code_pos += sprintf(code + code_pos, "%c%d", letter, count);
    }

    code[code_pos] = '\0';

    return code;
}

int main(int agc, char** argv) {
    char text[] = "AAABBBCC";
    char *code = RLE(text);

    printf("Orig: %s\n", text);
    printf("Code: %s\n", code);

    return 0;
}