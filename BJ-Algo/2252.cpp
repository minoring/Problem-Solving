#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    int m;
    scanf("%d %d", &n, &m);

    int in_degree[32001] = {0, };
    vector<int> g[32001];

    for (int i = 0; i < m; ++i) {
        int u;
        int v;
        scanf("%d %d", &u, &v);
        in_degree[v]++;
        g[u].push_back(v);
    }

    queue<int> zeros;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            zeros.push(i);
        }
    }

    while (!zeros.empty()) {
        int front = zeros.front();
        zeros.pop();
        printf("%d ", front);
        for (int v : g[front]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                zeros.push(v);
            }
        }
    }
}