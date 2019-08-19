#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    int n[15][15];
    for (int i = 1; i < 15; ++i) {
        n[0][i] = i;
    }

    for (int i = 1; i < 15; ++i) {
        for (int j = 1; j < 15; ++j) {
            int sum = 0;
            for (int k = 1; k <= j; ++k) {
                sum += n[i - 1][k];
            }
            n[i][j] = sum;
        }
    }

    while (T--) {
        int a;
        int b;
        cin >> a >> b;

        cout << n[a][b] << '\n';
    }
}