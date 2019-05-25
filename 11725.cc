// 트리가 주어지면 각 노드의 부모노드를 찾는문제.
// 간선이 루트노드로부터 순서대로 주어지는게 아니기때문에,
// 주어진 간선만으로 누가 부모노드인지 판단하기 힘들다.
// 루트노드 부터 BFS탐색 하면, 깊이 순으로 탐색되기 때문에,
// BFS로 부모노드를 구해 나간다.
// 혹시 루트노드랑 연결 안되있으면 어떡하나 걱정했는데 트리니까..

#include <iostream>
#include <queue>
using namespace std;

int main() {
    vector<int> adj[100001];
    vector<int>::iterator iter;
    bool visited[100001] = {false};
    int parent[100001];
    queue<int> q;

    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    visited[1] = true;
    q.push(1);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (iter = adj[u].begin(); iter != adj[u].end(); ++iter) {
            if (!visited[*iter]) {
                visited[*iter] = true;
                q.push(*iter);
                parent[*iter] = u;
            }
        }
    }

    for (int i = 2; i <= n; ++i)
        cout << parent[i] << '\n';
    
    return 0;
}