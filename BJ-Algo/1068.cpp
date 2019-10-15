#include <iostream>
#include <queue>
#include <vector>

void DFS(int* num_leaf, int root_node, int delete_node,
         const std::vector<std::vector<int> >& adjacencies) {
    if (root_node == delete_node) {
        return;
    }

    if (adjacencies[root_node].empty() || 
        (adjacencies[root_node].size() == 1 && 
        adjacencies[root_node][0] == delete_node)) {
        (*num_leaf)++;
        return;
    }

    for (int i = 0; i < adjacencies[root_node].size(); ++i) {
        DFS(num_leaf, adjacencies[root_node][i], delete_node, adjacencies);
    }
}

int main() {
    int n;
    std::cin >> n;
    const int MAX_NUM_NODE = 50;
    std::vector<std::vector<int> > adjacencies(MAX_NUM_NODE);

    int root_node;
    for (int i = 0; i < n; ++i) {
        int parent;
        std::cin >> parent;
        if (parent == -1) {
            root_node = i;
            continue;
        }
        adjacencies[parent].push_back(i);
    }

    int delete_node;
    std::cin >> delete_node;

    int num_leaf = 0;
    DFS(&num_leaf, root_node, delete_node, adjacencies);
    std::cout << num_leaf << '\n';
}