#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int prev_prev = 0;
  int prev = 1;
  int curr;
  for (int i = 2; i <= n; ++i) {
    curr = prev_prev + prev;
    prev_prev = prev;
    prev = curr;
  }
  cout << ((n >= 2) ? curr : n) << '\n';
}
