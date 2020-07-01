#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> boxes(n);
  vector<int> dp(n);

  for (int i = 0; i < n; ++i) {
    cin >> boxes[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (boxes[i] > boxes[j]) {
        dp[i] = max(dp[i], dp[j]);
      }
    }
    dp[i] += 1;
  }

  cout << *max_element(dp.begin(), dp.end()) << '\n';
}
