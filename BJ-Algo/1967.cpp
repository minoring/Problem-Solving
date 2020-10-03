#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

int ans = 0;

int max_len(unordered_map<int, list<pair<int, int>>> &graph, int root) {
  int first_max = 0;
  int second_max = 0;

  if (graph.find(root) == graph.end()) {
    return 0;
  }

  for (auto it = graph[root].begin(); it != graph[root].end(); ++it) {
    int w = max_len(graph, (*it).first) + (*it).second;

    if (w > first_max) {
      second_max = first_max;
      first_max = w;
    } else if (w > second_max) {
      second_max = w;
    }
  }
  ans = max(ans, first_max + second_max);
  return first_max;
}

int main() {
  int n;
  cin >> n;

  unordered_map<int, list<pair<int, int>>> graph;
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  max_len(graph, 1);
  cout << ans << '\n';
}
