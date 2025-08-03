#include <stdio.h>
#include <stdint.h>

int hammingWeight(int n)
{
    int count = 0;
    while(n) {
        n &= (n -1);
        count++;
    }
    return count;
}

int main()
{
    uint32_t intput = 11;
    printf("Number of 1 bits: %d\n", hammingWeight(intput));
    return 0;
}
