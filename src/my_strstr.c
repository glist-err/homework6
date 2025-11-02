#include <stdio.h>

char* my_strstr(char *str, char *substr) {
    if (substr == '\0') {
        return str; // Нулевая строка
    }

    for (char *p = str; *p != '\0'; p++) {
        char *s1 = p;
        char *s2 = substr;

        // Пока символы совпадают
        while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
            s1++;
            s2++;
        }
        
        if (*s2 == '\0') {
            return p;
        }
    }

    return NULL;    // если Строка не найдена
}

int main(int argc, char** argv) {
    char str[] = "BBBAAACCC";
    char substr[] = "AAA";

    char *res = my_strstr(str, substr);

    printf("Substr position - %ld\n", res - str);

    return 0;
}