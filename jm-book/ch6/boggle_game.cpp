#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
                        {1, 1},   {1, 0},  {1, -1}, {0, -1}};

bool inRange(int y, int x) { return (y >= 0 && y < 5 && x >= 0 && x < 5); }

bool dfs(const char grid[][5], int y, int x, const string &s, int idx) {
    if (idx >= s.length()) {
        return true;
    }
    if (!inRange(y, x)) {
        return false;
    }
    if (grid[y][x] != s[idx]) {
        return false;
    }

    for (int k = 0; k < 8; ++k) {
        int newRow = y + dirs[k][0];
        int newCol = x + dirs[k][1];
        if (dfs(grid, newRow, newCol, s, idx + 1)) {
            return true;
        }
    }
    return false;
}

bool canFind(const char grid[][5], const string &s) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (s[0] == grid[i][j]) {
                if (dfs(grid, i, j, s, 0)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    char grid[5][5];
    while (t--) {
        string s;
        for (int i = 0; i < 5; ++i) {
            cin >> s;
            for (int j = 0; j < 5; ++j) {
                grid[i][j] = s[j];
            }
        }

        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;

            bool found = canFind(grid, s);

            cout << s << ' ';
            if (found) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
}
