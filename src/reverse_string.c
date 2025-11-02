#include <stdio.h>

void reverse_string(char* str) {
    if (*str == '\0') {
        return;
    }

    char *start = str;  // начало строки
    char *end = str;    // конец

    while (*(end + 1) != '\0') {
        end++;  // Длина строки бкз '\0'
    }
    
    while (start < end) {
        char temp_start = *start;   // ыременный символ

        *start = *end;
        *end = temp_start;

        // идём налеыо и направо
        start++;
        end--;
    }
}

int main(int argc, char**argv) {
    char str[] = "HELP";

    reverse_string(str);

    printf("Reverse - %s", str);

    return 0;
}