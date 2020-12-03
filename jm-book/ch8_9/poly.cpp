#include <cstring>
#include <iostream>

using namespace std;

const int MOD = 10000000;

int cache[101][101];

int poly(int n, int first) {
    if (n == first) {
        return 1;
    }

    int &res = cache[n][first];
    if (res != -1) {
        return res;
    }

    res = 0;
    for (int second = 1; second <= n - first; ++second) {
        res = (res + (first + second - 1) * poly(n - first, second)) % MOD;
    }
    return res;
}

int main() {
    int c;
    cin >> c;
    memset(cache, -1, sizeof(cache));

    while (c--) {
        int n;
        cin >> n;

        int res = 0;
        for (int first = 1; first <= n; ++first) {
            res = (res + poly(n, first)) % MOD;
        }
        cout << res << '\n';
    }
}
