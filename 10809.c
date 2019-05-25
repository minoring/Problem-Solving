#include <stdio.h>

int main() 
{
    int i = 0;
    char s[101];
    char pos[26] = {[0 ... 25] = -1};
    scanf("%s", s);
    while (s[i] != '\0') {
        if (pos[s[i] - 'a'] == -1)
            pos[s[i] - 'a'] = i;
        ++i;
    }
    for (i = 0;  i < 26; ++i )
        printf("%d ", pos[i]);
    return 0;
}