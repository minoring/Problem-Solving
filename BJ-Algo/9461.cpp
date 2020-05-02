#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  long long p[101];
  p[1] = 1;
  p[2] = 1;
  p[3] = 1;
  p[4] = 2;
  p[5] = 2;
  p[6] = 3;
  p[7] = 4;
  p[8] = 5;

  for (int i = 9; i < 101; ++i) {
    p[i] = p[i - 1] + p[i - 5];
  }

  while (T--) {
    int n;
    cin >> n;
    cout << p[n] << '\n';
  }
}