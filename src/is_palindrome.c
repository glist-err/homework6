#include <stdio.h>
#include <ctype.h>

int is_palindrome(const char *str) {
    const char *left = str;
    const char *right = str;
    while (*(right+1) != '\0') {
        right++;
    }

    while (left < right) {
        while (left < right && !isalpha(*left)) {
            left++;
        }
        while (left < right && !isalpha(*right)) {
            right--;
        }

        // сравниваем без учёта регистра
        if (tolower(*left) != tolower(*right))
            return 0;  // palindrome - false

        left++;
        right--;
    }

    return 1;  // PALINDROME EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEYY
}

int main() {
    char str[] = "Lev el";

    int res = is_palindrome(str);

    printf("Is palindrome - %s", (res == 1) ? "yse" : "no");

    return 0;
}