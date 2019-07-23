#include <stdio.h>
int main()
{
    int t, n; char s[20];
    scanf("%d", &t);
    while (t--) {
        scanf("%d %s", &n, s);
        for (int i = 0; s[i] != '\0'; ++i)
            for (int j = 0; j < n; ++j)
                printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}