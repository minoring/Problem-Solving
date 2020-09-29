#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 0) {
    cout << 1 << '\n';
  } else if (n < 0) {
    cout << 32 << '\n';
  } else {
    int bits = 0;
    while (n != 0) {
      n = n >> 1;
      bits++;
    }
    cout << bits << '\n';
  }
}
