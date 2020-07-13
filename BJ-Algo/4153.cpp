#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        if (a > c && a > b) {
            swap(a, c);
        } else if (b > a && b > c) {
            swap(b, c);
        }

        if (a * a + b * b == c * c) {
            cout << "right" << '\n';
        } else {
            cout << "wrong" << '\n';
        }
    }
}
