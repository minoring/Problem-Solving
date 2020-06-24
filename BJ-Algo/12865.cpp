#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> dp(n + 1, vector<int>(k + 1));

  vector<pair<int, int>> weightValues;
  weightValues.push_back({0, 0});
  for (int i = 0; i < n; ++i) {
    int w;
    int v;
    cin >> w >> v;
    weightValues.push_back({w, v});
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      if (j - weightValues[i].first >= 0) {
        dp[i][j] = max(dp[i - 1][j], weightValues[i].second + dp[i - 1][j - weightValues[i].first]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  cout << dp[n][k] << '\n';
}
