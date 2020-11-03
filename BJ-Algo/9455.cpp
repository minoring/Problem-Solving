#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> grid[i][j];
      }
    }

    int num_moves = 0;

    for (int c = 0; c < n; ++c) {
      int lastZero = -1;
      for (int r = m - 1; r >= 0; --r) {
        if (lastZero < 0 && grid[r][c] == 0) {
          lastZero = r;
        }
        if (grid[r][c] == 1 && lastZero > 0) {
          num_moves += (lastZero - r);
          lastZero = lastZero - 1;
        }
      }
    }

    cout << num_moves << '\n';
  }
}
