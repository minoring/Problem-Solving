#include <iostream>
#include <unordered_map>

using namespace std;

int Find(unordered_map<int, int> &m, int x)
{
  if (x == 0) {
    return -1;
  }
  if (m.find(x) == m.end()) {
    return m[x] = x - 1;
  }
  return m[x] = Find(m, m[x]);
}

int main()
{
  int G;
  int P;
  cin >> G >> P;
  unordered_map<int, int> m;

  int answer = 0;
  bool end = false;
  for (int i = 0; i < P; ++i) {
    int g;
    cin >> g;

    if (end) {
      continue;
    }

    if (Find(m, g) == -1) {
      end = true;
      continue;
    }
    answer++;
  }

  cout << answer << '\n';
}