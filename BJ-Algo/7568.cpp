#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<pair<int, int>> people;
  for (int i = 0; i < N; ++i) {
    int width;
    int height;
    cin >> width >> height;
    people.push_back({width, height});
  }

  vector<int> rank(N);
  for (int i = 0; i < N; ++i) {
    int biggerCount = 0;
    for (int j = 0; j < N; ++j) {
      if (people[j].first > people[i].first &&
          people[j].second > people[i].second) {
        biggerCount++;
      }
      rank[i] = biggerCount + 1;
    }
  }

  for (int i = 0; i < N; ++i) {
    cout << rank[i] << ' ';
  }
}
