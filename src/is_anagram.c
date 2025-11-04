#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp_char(const void* a, const void* b) {
    char c1 = *(const char*)a;
    char c2 = *(const char*)b;

    return (int)c1 - (int)c2;
}

int is_anagram(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2) {
        return 0;   // Строки не равны - не анаграмма
    }

    qsort(str1, len1, sizeof(char), cmp_char);
    qsort(str2, len2, sizeof(char), cmp_char);

    if (strcmp(str1, str2) == 0 ) {
        return 1;   // Анаграмма
    }
    
    return 0;   // по умолчанию не анаграмма    
}

int main(int argc, char** argv) {
    char s1[] = "listen";
    char s2[] = "silent";

    printf("Is anagram - %s", (is_anagram(s1, s2) == 1) ? "Yes" : "No");

    return 0;
}