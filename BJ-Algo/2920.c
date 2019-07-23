#include <stdio.h>

int main() {
    const int kArrSize = 8;
    int inputs[kArrSize];
    int i, temp;
    const char* result = NULL;
    for (i = 0; i < kArrSize; ++i)
        scanf("%d", &inputs[i]);
    for (i = 0; i < kArrSize - 1; ++i) {
        temp = inputs[i + 1] - inputs[i];
        if (temp != 1 && temp != -1) {
            result = "mixed";
            break;
        }
    }
    if (result == NULL)
        result = ((temp == 1) ? "ascending" : "descending");
    printf("%s", result);
    return 0;
}