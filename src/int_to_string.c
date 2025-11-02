#include <stdio.h>

char* int_to_string(int number) {
    static char str[12]; // int от -2147483648 до 2147483647
    int i = 0;
    int is_negative = 0;

    if (number == 0) {
        str[i++] = '0';
        str[i] = '\0';  // str[0] = '\0'
        return str;
    }

    if (number < 0) {
        is_negative = 1;
        number = -number;
    }

    // разбираем число по цифрам
    while (number > 0) {
        int digit = number % 10;
        str[i++] = '0' + digit;
        number /= 10;
    }

    if (is_negative)
        str[i++] = '-';

    str[i] = '\0';

    // переворачиваем строку
    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }

    return str;
}

int main() {
    printf("%s\n", int_to_string(12345));   // "12345"
    printf("%s\n", int_to_string(-6789));   // "-6789"
    printf("%s\n", int_to_string(0));       // "0"
    return 0;
}
