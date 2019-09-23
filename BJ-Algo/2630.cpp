/*
https://www.acmicpc.net/problem/2630
Apporach: Divide and Conquer
Tips: Use size and start x, start y coordinate.
Use y, x coordinate
*/
#include <iostream>

using namespace std;

int paper[128][128];
int num_white;
int num_blue;

void solve(int size, int y, int x) {
    int color = paper[y][x];
    bool is_same_color = true;
    for (int i = y; i < y + size; ++i) {
        if (!is_same_color) {
            break;
        }
        for (int j = x; j < x + size; ++j) {
            if (paper[i][j] != color) {
                is_same_color = false;
                break;
            }
        }
    }
    if (is_same_color) {
        if (color == 1) {
            num_blue++;
        } else {
            num_white++;
        }
        return;
    }
    solve(size / 2, y, x);
    solve(size / 2, y, x + size / 2);
    solve(size / 2, y + size / 2, x);
    solve(size / 2, y + size / 2, x + size / 2);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> paper[i][j];
        }
    }
    solve(n, 0, 0);
    cout << num_white << '\n' << num_blue << '\n';
}
