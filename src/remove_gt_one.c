#include <stdio.h>
#include <stdlib.h>

void remove_gt_one(float *array, size_t size) {
    //float new_array[size];

    for (int i = 0; i < size; ++i) {
        if (abs(array[i]) <= 1) {
            for (int j = i; j < size-1; ++j) {
                array[j] = array[j+1];
            }
            array[size-1] = 0.0;
        }
    }
}

int main(int argc, char** argv) {
    float array[10] = {1.0, -2.0, -1.0, -4.0, 15.0, -15.0, 6.0, -7.0, 9.0, -10.0};
    int size = sizeof(array)/sizeof(int);

    printf("Old array: ");
    for (int i = 0; i < size; ++i) {
        printf("%.1f ", array[i]);
    }
    printf("\n");

    remove_gt_one(array, size);

    printf("New array: ");
    for (int i = 0; i < size; ++i) {
        printf("%.1f ", array[i]);
    }
    printf("\n");
    
    return 0;
}