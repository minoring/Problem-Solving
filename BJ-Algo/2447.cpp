#include <cstring>
#include <iostream>

using namespace std;

char mat[2188][2188];

void solve(int y, int x, int div) {
    if (div == 1) {
        mat[y][x] = '*';
        return;
    }

    div /= 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i != 1 || j != 1) {
                solve(y + (i * div), x + (j * div), div);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    memset(mat, ' ', sizeof(mat));
    solve(0, 0, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mat[i][j];
        }
        cout << '\n';
    }
}

// 별 찍기 - 10
// https://www.acmicpc.net/problem/2447
// Approach: recursive, divide and conquer.