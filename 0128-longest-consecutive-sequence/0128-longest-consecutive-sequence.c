
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    qsort(nums, numsSize, sizeof(int), compare);

    int longest = 1;
    int current = 1;

    for (int i = 1; i < numsSize; i++) {

        if (nums[i] == nums[i - 1]) {
            continue;
        }

        if (nums[i] == nums[i - 1] + 1) {
            current++;
        } else {
            if (current > longest)
                longest = current;
            current = 1;
        }
    }

    return (current > longest) ? current : longest;
}