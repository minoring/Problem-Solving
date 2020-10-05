#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first < b.first) {
    return true;
  }
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> ranks(n);

    for (int i = 0; i < n; ++i) {
      cin >> ranks[i].first >> ranks[i].second;
    }
    sort(ranks.begin(), ranks.end(), compare);

    int high_interview_rank = ranks[0].second;
    int num_fail = 0;
    for (int i = 1; i < n; ++i) {
      if (ranks[i].second < high_interview_rank) {
        high_interview_rank = ranks[i].second;
      } else {
        num_fail++;
      }
    }
    cout << n - num_fail << '\n';
  }
}
