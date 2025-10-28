#include <stdio.h>

int get_second_max(int *array, size_t size) {
    int max1 = array[0];
    int max2 = array[0];

    for (int i = 0; i < size; i++) {
        if (array[i] > max1) {
            max1 = array[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (array[i] > max2 && array[i] != max1) {
            max2 = array[i];
        }
    }

    return max2;
}

int main(int argc, char** argv) {
    int array[10] = {1, 2, 3, 4, 15, 15, 6, 7, 9, 10};
    int size = sizeof(array)/sizeof(int);

    printf("Second max = %d\n", get_second_max(array, size));

    return 0;
}