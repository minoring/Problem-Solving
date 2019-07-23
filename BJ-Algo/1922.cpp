#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int v1;
    int v2;
    int cost;
    Node(int _v1, int _v2, int _cost) : v1(_v2), v2(_v2), cost(_cost) {}
};

struct UnionFindTree {
    vector<int> parent;
    vector<int> height;

    void init(int uf_n) {
        for (int i = 0; i < uf_n; ++i) {
            parent.push_back(i);
            height.push_back(0);
        }
    }

    int get_root(int now) {
        if (parent[now] == now) return now;
        return parent[now] = get_root(parent[now]);
    }
    
};

struct Comp {
    bool operator()(Node n1, Node n2) {
        return n1.cost < n2.cost;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Node> nodes;
    while (m--) {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        nodes.push_back(Node(v1, v2, cost));
    }
    sort(nodes.begin(), nodes.end(), Comp());

    int num_edge = 0;
    while (num_edge < n - 1) {

    }
}