#include <cstring>
#include <iostream>

using namespace std;

int cache[101];
const int divisor = 1000000007;

int tile(int n) {
    if (n <= 1) {
        return 1;
    }

    int &ret = cache[n];
    if (ret != -1) {
        return ret;
    }

    ret = (tile(n - 1) + tile(n - 2)) % divisor;
    return ret;
}

int main() {
    int c;
    cin >> c;

    memset(cache, -1, sizeof(cache));

    while (c--) {
        int n;
        cin >> n;
        cout << tile(n) << '\n';
    }
}
