#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  vector<int> incs(n, 1);
  vector<int> decs(n, 1);

  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  for (int i = 1; i < n; ++i) {
    if (nums[i] >= nums[i - 1]) {
      incs[i] = incs[i - 1] + 1;
    }
    if (nums[i] <= nums[i - 1]) {
      decs[i] = decs[i - 1] + 1;
    }
  }

  cout << max(*max_element(incs.begin(), incs.end()),
              *max_element(decs.begin(), decs.end()))
       << '\n';
}
