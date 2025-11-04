#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* RLD(char* code) {
    int size = 0;   // Размер исходной строки
    for (int i = 0; code[i];) {
        int count = 0;
        // Считаем число после буквы
        while (isdigit(code[i])) {
            count = count * 10 + (code[i] - '0');
            i++;
        }
        
        if (code[i]) i++;    // Пропускаем симовл
        
        size += count;
    }

    char *decode = (char*)malloc(size+1);
    int pos = 0;

    for (int i = 0; code[i];) {
        char letter = code[i++];
        int count = 0;

        while (isdigit(code[i])) {
            count = count * 10 + (code[i] - '0');
            i++;
        }

        for (int j = 0; j < count; j++) {
            decode[pos++] = letter;
        }
    }

    decode[pos] = '\0';

    return decode;
}

int main(int argc, char** argv) {
    char text[] = "A3B3C2";
    char *code = RLD(text);

    printf("Code: %s\n", text);
    printf("Orig: %s\n", code);

    return 0;
}