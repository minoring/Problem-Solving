#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> dp(N);

  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      if (A[j] > A[i]) {
        dp[i] = max(dp[i], dp[j]);
      }
    }
    dp[i] += 1;
  }

  cout << *max_element(dp.begin(), dp.end()) << '\n';
}
