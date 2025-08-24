#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int divide(int dividend, int divisor)
{
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;

    int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1; // 1 ^ 1 = 0, 0 ^ 0 = 0

    long long dvd = llabs((long long)dividend);
    long long dvs = llabs((long long)divisor);
    long long ans = 0;

    while (dvd >= dvs) {
        long long temp = dvs, multiple = 1;
        while ((temp << 1) <= dvd) {
            temp <<= 1;
            multiple <<= 1;
        }
        dvd -= temp;
        ans += multiple;
    }
    return (int)(sign*ans);
}

int main()
{
    printf("43 / 5 = %d\n", divide(43, 5));
    printf("43 / -5 = %d\n", divide(43, -5));
    printf("-43 / 5 = %d\n", divide(-43, 5));
    printf("-43 / -5 = %d\n", divide(-43, -5));
    printf("INT_MIN / -1 = %d\n", divide(-2147483648, -1));
    return 0;
}
