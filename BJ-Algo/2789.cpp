#include <iostream>

using namespace std;

int main() {
    int N[100];
    int n;
    int m;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> N[i];
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (N[i] + N[j] + N[k] <= m && N[i] + N[j] + N[k] > res) {
                    res = N[i] + N[j] + N[k];
                }
            }
        }
    }
    cout << res << '\n';
}