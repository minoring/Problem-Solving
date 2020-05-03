#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= 2 * n - 1; ++i) {
    int num_star = 1;
    if (i <= n) {
      num_star = i;
    } else {
      num_star = n - (i % n);
    }
    for (int j = 0; j < num_star; ++j) {
      cout << '*';
    }
    cout << '\n';
  }
}