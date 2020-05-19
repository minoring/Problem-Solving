#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int N;
    int M;
    cin >> N >> M;

    unordered_map<int, vector<pair<int, int>>> adj;
    for (int i = 0; i < M; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj[from].push_back({to, weight});
    }

    int start, finish;
    cin >> start >> finish;
    unordered_set<int> visited;
    visited.insert(start);
    vector<int> distFromStart(N + 1, INT_MAX);
    distFromStart[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while (visited.find(finish) == visited.end()) {
        int minNodeWeight = distFromStart[-pq.top().second];
        int minDistNode = pq.top().second;
        pq.pop();

        visited.insert(minDistNode);
        if (adj.find(minDistNode) != adj.end()) {
            for (pair<int, int> nodeWeight : adj[minDistNode]) {
                if (visited.find(nodeWeight.first) == visited.end() &&
                    distFromStart[minDistNode] + nodeWeight.second <
                        distFromStart[nodeWeight.first]) {
                    distFromStart[nodeWeight.first] =
                        distFromStart[minDistNode] + nodeWeight.second;
                    pq.push(
                        {-distFromStart[nodeWeight.first], nodeWeight.first});
                }
            }
        }
    }

    cout << distFromStart[finish] << '\n';
}
