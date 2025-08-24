#include<stdio.h>

int reverseBits(int n)
{
    unsigned int res = 0;
    for (size_t i = 0; i < 32; i++) {
        res <<= 1;
        res |= (n & 1);
        n >>= 1;
    }

    return res;
}


int main()
{
    printf("%u\n", reverseBits(43261596));
    printf("%u\n", reverseBits(2147483644));
}
