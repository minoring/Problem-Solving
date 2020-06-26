#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  const int maxNumRoom = 100;
  vector<vector<int>> isOpen(maxNumRoom + 1, vector<int>(maxNumRoom + 1));

  for (int i = 1; i <= maxNumRoom; ++i) {
    for (int j = 1; j <= maxNumRoom; j += 1) {
      if (j % i == 0) {
        if (isOpen[i - 1][j] == 1) {
          isOpen[i][j] = 0;
        } else {
          isOpen[i][j] = 1;
        }
      } else {
        isOpen[i][j] = isOpen[i - 1][j];
      }
    }
  }

  while (t--) {
    int n;
    cin >> n;
    cout << accumulate(isOpen[n].begin(), isOpen[n].begin() + n + 1, 0) << '\n';
  }
}
