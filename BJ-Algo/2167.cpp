#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  int m;

  cin >> n >> m;
  vector<vector<int>> accum(n + 1, vector<int>(m + 1));

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      accum[i][j] += accum[i - 1][j];
      accum[i][j] += accum[i][j - 1];
      accum[i][j] -= accum[i - 1][j - 1];
      int inputNum;
      cin >> inputNum;
      accum[i][j] += inputNum;
    }
  }

  int k;
  cin >> k;
  while (k--) {
    int i, j, x, y;
    cin >> i >> j >> x >> y;

    int res =
        accum[x][y] - accum[i - 1][y] - accum[x][j - 1] + accum[i - 1][j - 1];
    cout << res << '\n';
  }
}
