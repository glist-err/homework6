#include <stdio.h>
#include <stdlib.h>

int string_to_int(char *str) {
    return atoi(str);
}

int main() {
    char str[] = "123";
    int res = string_to_int(str);

    printf("%d\n", res);
    
    return 0;
}