#include <iostream>

using namespace std;

int _abs(int x) {
  if (x < 0)
    return -x;
  return x;
}

int main() {
  int n;
  cin >> n;

  int half = n - 1;
  for (int i = 0; i < 2 * n - 1; ++i) {
    int num_stars = _abs(half - i) * 2 + 1;
    int num_spaces = ((2 * n - 1) - num_stars) / 2;

    for (int j = 0; j < num_spaces; ++j) {
      cout << ' ';
    }
    for (int j = 0; j < num_stars; ++j) {
      cout << '*';
    }
    cout << '\n';
  }
}
