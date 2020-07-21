#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  if (b > a) {
    swap(a, b);
  }
  return gcd(b, a % b);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
      cin >> nums[i];
    }

    long long sum_gcd = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        sum_gcd += gcd(nums[i], nums[j]);
      }
    }
    cout << sum_gcd << '\n';
  }
}
