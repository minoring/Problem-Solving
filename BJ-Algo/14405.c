#include <stdio.h>
#include <string.h>

int main()
{
    char s[5000];
    scanf("%s", s);
    int len = strlen(s);
    int i = 0;
    while (i + 1 < len) {
        if (s[i] == 'p') {
            if (s[i + 1] != 'i')
                break;
            i += 2;
        } else if (s[i] == 'k') {
            if (s[i + 1] != 'a')
                break;
            i += 2;
        } else if (s[i] == 'c') {
            if (i + 2 < len) {
                if (s[i + 1] != 'h' || s[i + 2] != 'u')
                    break;
            } else
                break;
            i += 3;
        } else {
            break;
        }
    }
    if (i == len)
        printf("YES");
    else
        printf("NO");
    return 0;
}