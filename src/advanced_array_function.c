#include "../include/advanced_array_function.h"

int max_subarray_sum(int* nums, int size) {
    if (size == 0) {
        return 0;
    }
    int max_sum = nums[0];
    int cur_sum = nums[0];

    for (int i = 1; i < size; i++) {
        if (cur_sum < 0) {
            cur_sum = nums[i];
        }
        else {
            cur_sum += nums[i];
        }
        
        if (cur_sum > max_sum) {
            max_sum = cur_sum;
        }
    }

    return max_sum;
}

int length_of_lis(int* nums, int numsSize) {
    int max_len = 1;
    int cur_len = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i-1]) {
            cur_len++;
        }
        else {
            cur_len = 1;
        }

        if (cur_len > max_len) {
            max_len = cur_len;
        }
    }

    return max_len;
}

int* merge(int* intervals, int intervalsSize, int* returnSize) {
    return NULL;
}

