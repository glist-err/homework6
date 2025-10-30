#include <stdio.h>

int get_greater_freq(int *array, size_t size) {
    if (size == 0) {
        return 0;
    }
    
    int max_number = 0;
    
    int max_count = 0;
    for (int i = 0; i < size; ++i) {
        int count = 1;

        int number = array[i];
        //int index = array[i];
        
        //count += 1;

        for (int j = 0; j < size; ++j) {
            if (array[j] == number && j != i) {
                count += 1;
            }
        }

        if (count > max_count) {
            max_count = count;

            max_number = number;
        }
    }

    return max_number;
}

int main(int argc, char** argv) {
    int array[10] = {1, 2, 3, 4, 15, 15, 6, 7, 9, 10};
    int size = sizeof(array)/sizeof(int);

    printf("Max freq = %d\n", get_greater_freq(array, size));

    return 0;
}