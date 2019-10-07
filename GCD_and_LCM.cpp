#include <stdio.h>

#define llu unsigned long long

llu gcd(llu a, llu b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    llu f1, f2, tc;
    scanf("%llu", &tc);
    while (tc--)
    {
        scanf("%llu %llu", &f1, &f2);

        llu g = gcd(f1, f2);

        printf("%llu %llu\n", g, (f1 / g) * f2);
    }
    return 0;
}