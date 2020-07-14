#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  unordered_map<int, int> counter;
  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    counter[temp]++;
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int temp;
    cin >> temp;
    cout << counter[temp] << ' ';
  }
  cout << '\n';
}
