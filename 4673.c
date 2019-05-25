#include <stdio.h>
int D(int n)
{
    int d = n;
    while (n != 0) {
        d += n % 10;
        n /= 10;
    }
    return d;
}
int main()
{
    int d[10001] = {1, 0};
    int n = 1;
    while (n <= 10000) {
        if (D(n) <= 10000)
            d[D(n)] = 1;
        n = n + 1;
    }
    for (int i = 1; i < 10001; ++i)
        if (!d[i])
            printf("%d \n", i);
    return 0;
}