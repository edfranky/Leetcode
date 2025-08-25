#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 1 << numsSize;
    int **res = (int**)malloc((*returnSize) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));

    for (int mask = 0; mask < *returnSize; mask++) {
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (mask & (1 << j)) count++;
        }

        res[mask] = (int*)malloc(count * sizeof(int));
        (*returnColumnSizes)[mask] = count;

        int idx = 0;
        for (int j = 0; j < numsSize; j++) {
            if (mask & (1 << j)) {
                res[mask][idx++] = nums[j];
            }
        }
    }
    return res;
}

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = 3;
    int returnSize;
    int *returnColumnSizes;
    int **res = subsets(nums, numsSize, &returnSize, &returnColumnSizes);

    printf("Subsets of [1,2,3]:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("{ ");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("}\n");
        free(res[i]);
    }
    free(res);
    free(returnColumnSizes);
    return 0;
}

