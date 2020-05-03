#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> dp(n + 1, INT_MAX);
  dp[0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j * j <= i; ++j) {
      if (j * j == i) {
        dp[i] = 1;
      } else {
        dp[i] = min(dp[i], dp[i - j * j] + dp[j * j]);
      }
    }
  }
  cout << dp[n] << '\n';
}
