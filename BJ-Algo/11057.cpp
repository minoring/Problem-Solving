#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int d[10];
    for(int i = 0; i < 10; ++i) {
        d[i] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            int sum = 0;
            for (int k = j; k < 10; ++k) {
                sum += d[k];
            }
            d[j] = sum % 10007;
        }
    }
    int res = 0;
    for (int i = 0; i < 10; ++i) {
        res += d[i];
    }
    cout << res % 10007 << '\n';
}