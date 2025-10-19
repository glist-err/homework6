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
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    // bubble sort
    for (int i = 0; i < intervalsSize - 1; i++) {
        for (int j = 0; j < intervalsSize - i - 1; j++) {
            if (intervals[j * 2] > intervals[(j + 1) * 2]) {

                int tempStart = intervals[j * 2];
                int tempEnd = intervals[j * 2 + 1];
                
                intervals[j * 2] = intervals[(j + 1) * 2];
                intervals[j * 2 + 1] = intervals[(j + 1) * 2 + 1];
                
                intervals[(j + 1) * 2] = tempStart;
                intervals[(j + 1) * 2 + 1] = tempEnd;
            }
        }
    }
    
    // временный массив для результатика
    int tempResult = (int)malloc(intervalsSize * sizeof(int*));
    for (int i = 0; i < intervalsSize; i++) {
        tempResult[i] = (int*)malloc(2 * sizeof(int));
    }
    
    int resultSize = 0;
    tempResult[resultSize][0] = intervals[0];
    tempResult[resultSize][1] = intervals[1];
    
    // алгоритм объединения
    for (int i = 1; i < intervalsSize; i++) {
        int currentStart = intervals[i * 2];
        int currentEnd = intervals[i * 2 + 1];
        int lastEnd = tempResult[resultSize][1];
       
        if (currentStart <= lastEnd) {
            if (currentEnd > lastEnd) {
                tempResult[resultSize][1] = currentEnd;
            }
        } else {
            resultSize++;
            tempResult[resultSize][0] = currentStart;
            tempResult[resultSize][1] = currentEnd;
        }
    }
    
    resultSize++;
    
    // Теперь все в один массив
    int* flatResult = (int*)malloc(resultSize * 2 * sizeof(int));
    for (int i = 0; i < resultSize; i++) {
        flatResult[i * 2] = tempResult[i][0];
        flatResult[i * 2 + 1] = tempResult[i][1];
        free(tempResult[i]);
    }
    free(tempResult);
    
    *returnSize = resultSize;
    return flatResult;
}
