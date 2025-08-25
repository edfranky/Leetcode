#include<stdio.h>
#include<stdlib.h>

int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;
    int *res = (int*)malloc((n+1) * sizeof(int));
    res[0] = 0;
    for (int i = 1; i <= n; i++) res[i] = res[i >> 1] + (i & 1);
    return res;
}

int main()
{
    int n = 10;
    int returnSize = 0;
    int *res = countBits(n, &returnSize);

    printf("countBits(%d):\n", n);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(res);
    return 0;
}
