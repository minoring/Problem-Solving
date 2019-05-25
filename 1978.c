#include <stdio.h>
int IsPrime(n)
{
    if (n == 1) return 0;
    for (int i = 2; i < n; ++i)
        if (n % i == 0)
            return 0;
    return 1;
}
int main()
{
    int num, n; scanf("%d", &num);
    int count = 0;
    while (num--) {
        scanf("%d", &n);
        if(IsPrime(n)) ++count;
    }
    printf("%d", count);
    return 0;
}