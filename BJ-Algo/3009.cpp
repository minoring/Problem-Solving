#include <iostream>

using namespace std;
int main() {
    int x, y;

    cin >> x >> y;
    for (int i = 0; i < 2; ++i) {
        int tmp;
        cin >> tmp;
        x ^= tmp;
        cin >> tmp;
        y ^= tmp;
    }
    cout << x << ' ' << y << '\n';
}
