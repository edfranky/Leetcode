#include<stdio.h>
#include<stdlib.h>

int* singleNumber(int* nums, int numsSize, int* returnSize)
{
    int xor_all = 0;
    for (size_t i = 0; i < numsSize; i++) xor_all ^= nums[i];

    unsigned int diff = (unsigned int)xor_all & -(unsigned int)xor_all;
    int group_1 = 0, group_2 = 0;

    for (size_t i = 0; i < numsSize; i++) {
        if (nums[i] & diff) {
            group_1 ^= nums[i];
        }
        else {
            group_2 ^= nums[i];
        }
    }

    int* res = (int*)malloc(2 * sizeof(int));
    res[0] = group_1;
    res[1] = group_2;
    *returnSize = 2;
    return res;
}

int main()
{
    int nums[] = {1, 2, 1, 3, 2, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    int* result = singleNumber(nums, numsSize, &returnSize);

    printf("The two single numbers are: %d and %d\n", result[0], result[1]);

    free(result);
    return 0;
}
