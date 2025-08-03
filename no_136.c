#include <stdlib.h>
#include <stdio.h>

int singleNumber(int *nums, int numsSize)
{
    int result = 0;
    for (size_t i = 0; i < numsSize; i++) result ^= nums[i];
    return result;
}

int main()
{
    int input[3] = {2, 2, 1};
    int res = singleNumber(input, sizeof(input)/sizeof(input[0]));
    printf("Single number is: %d\n", res);
    return 0;
}
