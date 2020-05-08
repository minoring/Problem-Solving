#include <iostream>
#include <unordered_map>

using namespace std;

int Find(int a, unordered_map<int, int> &m_s)
{
  if (m_s[a] == a) {
    return a;
  }
  return m_s[a] = Find(m_s[a], m_s);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  int m;
  unordered_map<int, int> m_s;

  cin >> n >> m;
  for (int i = 0; i <= n; ++i) {
    m_s.insert({i, i});
  }

  for (int i = 0; i < m; ++i) {
    int c, a, b;
    cin >> c >> a >> b;
    if (c == 1) {
      int u = Find(a, m_s);
      int v = Find(b, m_s);
      if (u == v) {
        m_s[u] = v;
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    } else {
      int u = Find(a, m_s);
      int v = Find(b, m_s);
      m_s[u] = v;
    }
  }
}
