#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int bino[201][201];
const int MAX = 1000000000 + 100;

void calc_bino() {
    for (int i = 0; i <= 200; ++i) {
        bino[i][0] = 1;
        bino[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            bino[i][j] = min(MAX, bino[i - 1][j] + bino[i - 1][j - 1]);
        }
    }
}


int skip;
void generate(int n, int m, string s) {
    if (skip < 0) {
        return;
    }
    if (n == 0 && m == 0) {
        if (skip == 0) {
            cout << s << '\n';
        }
        skip--;
        return;
    }
    if (bino[n + m][n] <= skip) {
        skip -= bino[n + m][n];
        return;
    }
    if (n > 0) {
        generate(n - 1, m, s + "-");
    }
    if (m > 0) {
        generate(n, m - 1, s + "o");
    }
}

string kth(int n, int m, int skip) {
    if (n == 0) {
        return string(m, 'o');
    }
    if (skip < bino[m + n - 1][n - 1]) {
        return "-" + kth(n - 1, m, skip);
    }
    return "o" + kth(n, m - 1, skip - bino[m + n - 1][n - 1]);
}

int main() {
    int c;
    cin >> c;
    calc_bino();
    while (c--) {
        int n, m, k;
        cin >> n >> m >> k;
        skip = k - 1;
        string s = "";
        // generate(n, m, s);
        cout << kth(n, m, k - 1) << '\n';
    }
}
