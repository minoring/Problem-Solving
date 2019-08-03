#include <iostream>

using namespace std;

int main() {
    int n;
    const int k = 9901;
    const int N = 100001;
    cin >> n;

    int d[N][3];
    d[1][0] = 1;
    d[1][1] = 1;
    d[1][2] = 1;

    for (int i = 2; i < N; ++i) {
        d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % k;
        d[i][1] = (d[i - 1][0] + d[i - 1][2]) % k;
        d[i][2] = (d[i - 1][0] + d[i - 1][1]) % k;
    }

    cout << (d[n][0] + d[n][1] + d[n][2]) % k << '\n';
}