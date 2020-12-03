#include <cstring>
#include <iostream>

using namespace std;

int cache[101];
int cache2[101];
const int MOD = 1000000007;

int tile(int n) {
    if (n <= 1) {
        return 1;
    }

    int &ret = cache[n];
    if (ret != -1) {
        return ret;
    }

    ret = (tile(n - 1) + tile(n - 2)) % MOD;
    return ret;
}

int asym(int n) {
    if (n % 2 == 1) {
        return (tile(n) - tile(n / 2) + MOD) % MOD;
    }

    int ret = tile(n);
    ret = (ret - tile(n / 2) + MOD) % MOD;
    ret = (ret - tile(n / 2 - 1) + MOD) % MOD;
    return ret;
}

int asym2(int n) {
    if (n <= 2) {
        return 0;
    }

    int &ret = cache2[n];
    if (ret != -1) {
        return ret;
    }
    ret = asym2(n - 2) % MOD;
    ret = (ret + asym2(n - 4)) % MOD;
    ret = (ret + tile(n - 3)) % MOD;
    ret = (ret + tile(n - 3)) % MOD;
    return ret;
}

int main() {
    int c;
    cin >> c;

    memset(cache, -1, sizeof(cache));
    memset(cache2, -1, sizeof(cache2));

    while (c--) {
        int n;
        cin >> n;
        cout << (asym2(n)) % MOD << '\n';
    }
}
