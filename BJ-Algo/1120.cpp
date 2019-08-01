#include <iostream>
#include <string>

using namespace std;

int main() {
    int m = 50;
    string x;
    string y;

    cin >> x >> y;
    for (int i = 0; i <= y.length() - x.length(); ++i) {
        int s = 0;
        for (int j = 0; x[j]; ++j)
            if (x[j] - y[i + j]) {
                s++;
            }
        m = min(m, s);
    }
    cout << m << '\n';
}