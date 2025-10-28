#include <stdio.h>

int is_alternating(int *array, size_t size) {
    int is_alt = 0;

    for (int i = 0; i < size-1; i++) {
        if (!((array[i] < 0 && array[i+1] > 0) || (array[i] > 0 && array[i+1] < 0))) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char** argv) {
    int array[10] = {1, -2, 3, -4, 15, -15, 6, -7, 9, -10};
    int size = sizeof(array)/sizeof(int);

    printf("%d\n", is_alternating(array, size));

    return 0;
}