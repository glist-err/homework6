#include <stdio.h>

int get_greater_series(int *array, size_t size) {
    if (size == 0) return 0;

    int max_number = array[0];
    int max_length = 1;

    int current_number = array[0];
    int current_length = 1;

    for (int i = 1; i < size; ++i) {
        if (array[i] == current_number) {
            current_length++;
        } else {
            if (current_length > max_length) {
                max_length = current_length;
                max_number = current_number;
            }
            current_number = array[i];
            current_length = 1;
        }
    }

    // Проверяем последнюю серию
    if (current_length > max_length) {
        max_length = current_length;
        max_number = current_number;
    }

    return max_number;
}

int main() {
    int array[10] = {1, 2, 2, 2, 3, 3, 15, 15, 15, 15};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Max series = %d\n", get_greater_series(array, size));
    return 0;
}
