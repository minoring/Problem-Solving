#include <stdio.h>
int main()
{
    int n; scanf("%d", &n);
    int a = n / 5; 
    int b = (n - (5 * a)) / 3; // n = 5a + 3b
    while (5*a + 3*b != n && a != 0) {
        --a;
        b = (n - (5 * a)) / 3;
    }
    if (5*a + 3*b == n)
        printf("%d", a + b);
    else
        printf("-1");
    return 0;
}