#include <cstdio>
#include <string>

int main()
{
    char input_str[100000];
    scanf("%s", input_str);
    std::string str = input_str;
    int len = str.length();
    int cursor = len;
    
    int num_commands;
    scanf("%d", &num_commands);
    while (num_commands--) {
        char command;
        scanf(" %c", &command);
        switch(command) {
            case 'L':
                if (cursor != 0)
                    --cursor;
                break;
            case 'D':
                if (cursor < len)
                    ++cursor;
                break;
            case 'B':
                if (cursor != 0) {
                    str.erase(--cursor);
                }
                break;
            case 'P':
                char c; scanf(" %c", &c);
                str.insert(cursor, 1, c);
                ++cursor;
                break;
        }
    }
    printf("%s\n", str.c_str());
    return 0;
}