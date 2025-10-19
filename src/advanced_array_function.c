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
    if (numsSize == 0) {
        return 0;
    }

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
    if (intervalsSize == 0) {
        *returnSize = 0;
        return 0;
    }

    int n = intervalsSize / 2;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (intervals[j * 2] > intervals[(j + 1) * 2]) {
                int a = intervals[j * 2];
                int b = intervals[j * 2 + 1];
                intervals[j * 2] = intervals[(j + 1) * 2];
                intervals[j * 2 + 1] = intervals[(j + 1) * 2 + 1];
                intervals[(j + 1) * 2] = a;
                intervals[(j + 1) * 2 + 1] = b;
            }
        }
    }

    int* res = malloc(intervalsSize * sizeof(int));
    int k = 0;
    int start = intervals[0];
    int end = intervals[1];

    for (int i = 2; i < intervalsSize; i += 2) {
        int s = intervals[i];
        int e = intervals[i + 1];
        if (s <= end) {
            if (e > end)
                end = e;
        } else {
            res[k++] = start;
            res[k++] = end;
            start = s;
            end = e;
        }
    }

    res[k++] = start;
    res[k++] = end;
    *returnSize = k;
    return res;
}
