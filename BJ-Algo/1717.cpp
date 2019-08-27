#include <iostream>

using namespace std;

int parent[1000001];

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    parent[x] = find(parent[x]);
    return parent[x];
}

void uni(int a, int b) {
    int p_a = find(a);
    int p_b = find(b);
    parent[p_a] = p_b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;
    cin >> n >> m;
    for (int i = 0; i < 1000001; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 0) {
            uni(a, b);
        } else {
            cout << (find(a) == find(b) ? "YES" : "NO") << '\n';
        }
    }
}
