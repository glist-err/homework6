#include <stdio.h>
#include <string.h>

int string_to_int(char *str) {
    int number = 0;
    int size = strlen(str);
    
    for (int i = 0; i < size; i++) {
        if (str[i] >= '0' && str[i] <= 9) {
            int digit = str[i] - '0';

            number = number * 10 + digit;
        }
    }

    return number;
}

int main(int argc, char** argv) {
    char str[] = "123";
    int res = string_to_int(str);

    printf("%d\n", res);

    return 0;
}