#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k) {
    int i;
    double sum = 0;

    for(i = 0; i < k; i++) {
        sum += nums[i];
    }

    double maxSum = sum;

    for(i = k; i < numsSize; i++) {
        sum = sum - nums[i - k] + nums[i];

        if(sum > maxSum) {
            maxSum = sum;
        }
    }

    return maxSum / k;
}