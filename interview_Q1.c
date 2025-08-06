#include <stdio.h>

static int function(int *a, int size)
{
    int *ptr = a;
    for (int i = 0; i <= 500; i++) {
        if (*ptr == i) {
            ptr++;
        }
        else {
            printf("%d", i);
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int testCase[] = {0, 3, 5, 100, 200, 500};
    int size = sizeof(testCase) / sizeof(testCase[0]);
    function (testCase, size);
    return 0;
}
