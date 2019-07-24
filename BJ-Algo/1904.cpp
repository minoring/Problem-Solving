#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int n_2 = 1;
    int n_1 = 2;

    int res = 2;
    for (int i = 3; i <= n; ++i) {
        res = (n_2 + n_1) % 15746;
        n_2 = n_1 % 15746;
        n_1 = res % 15746;
    }
    printf("%d\n", res);
}