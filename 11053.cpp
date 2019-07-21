#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int N[1001];
    int d[1001];  // max가 N[i]일때 최대 길이.
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &N[i]);
    }

    for (int i = 0; i < n; ++i) {
        int max_num = 0;
        for (int j = 0; j < i; ++j) {
            if (N[j] < N[i] && d[j] > max_num) {
                max_num = d[j];
            }
        }
        d[i] = max_num + 1;
    }

    printf("%d\n", *max_element(d, d + n));
}