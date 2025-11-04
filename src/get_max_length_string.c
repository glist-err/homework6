#include <stdio.h>
#include <string.h>

char* get_max_length_string(char* str) {
    int lenght = 0;
    int max_lengh = 0;

    int start = 0;
    int max_start = 0;

    int size = strlen(str);

    for (int i = 0; /*нет условия, просто проходимся до '\0'*/; i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            if (lenght == 0) {
                start = i;
            }

            lenght++;
        }
        else {
            if (lenght > max_lengh) {
                max_lengh = lenght;
                max_start = start;
            }

            lenght = 0;
        }

        if (str[i] == '\0') {
            break;  // ыстретили конец строки
        }
    }

    return str + max_start;
}

int main(int argc, char** argv) {
    char text1[] = "Hello World";
    char text2[] = "one two three";
    char text3[] = "A AA AAA";

    printf("Text1 = %s\n", get_max_length_string(text1));
    printf("Text2 = %s\n", get_max_length_string(text2));
    printf("Text3 = %s\n", get_max_length_string(text3));

    return 0;
}