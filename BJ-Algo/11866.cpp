#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  int k;
  cin >> n;
  cin >> k;

  vector<bool> is_live(n + 1);
  fill(is_live.begin(), is_live.end(), true);
  is_live[0] = false;

  cout << '<';

  int cnt = 0;
  int lastIdx = 0;
  for (int i = 0; i < n; ++i) {
    while (cnt < k) {
      lastIdx = (lastIdx + 1) % (n + 1);
      if (is_live[lastIdx]) {
        cnt++;
      }
    }
    cnt = 0;
    is_live[lastIdx] = false;
    cout << lastIdx;

    if (i == n - 1) {
      cout << '>';
    } else {
      cout << ", ";
    }
  }
  cout << '\n';
}
