#include <iostream>
#include <vector>

using namespace std;

bool jump(int y, int x, int n, vector<vector<int>> &grid,
          vector<vector<int>> &cache) {
    if (y >= n || x >= n) {
        return false;
    }

    if (y == n - 1 && x == n - 1) {
        return true;
    }

    if (cache[y][x] != -1) {
        return cache[y][x];
    }
    int jump_size = grid[y][x];
    return cache[y][x] = jump(y + jump_size, x, n, grid, cache) ||
                         jump(y, x + jump_size, n, grid, cache);
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));
        vector<vector<int>> cache(n, vector<int>(n, -1));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        if (jump(0, 0, n, grid, cache)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}
