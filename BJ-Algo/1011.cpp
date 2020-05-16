#include <iostream>

using namespace std;

int main() {
    int T;
    int x;
    int y;
    cin >> T;
    while (T--) {
        cin >> x >> y;

        long long dist = y - x;
        long long n = 1;
        while (n * n <= dist) {
            ++n;
        }
        --n;

        long long answer;
        answer = 2 * n - 1;

        if (dist > n * n) {
            ++answer;
        }
        if (dist > (n + 1) * (n + 1) - (n + 1)) {
            ++answer;
        }
        cout << answer << '\n';
    }
}
