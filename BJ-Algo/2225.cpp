#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  const int modNum = 1000000000;
  vector<vector<long long>> dp(k + 1, vector<long long>(n + 1));

  for (int i = 0; i <= n; ++i) {
    dp[1][i] = 1;
  }
  for (int i = 2; i <= k; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= j; ++k) {
        dp[i][j] += (dp[i - 1][k] % modNum);
      }
    }
  }

  cout << dp[k][n] % modNum << '\n';
}
