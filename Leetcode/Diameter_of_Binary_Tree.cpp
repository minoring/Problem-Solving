/*
Find longest path between two nodes in a tree.
https://leetcode.com/problems/diameter-of-binary-tree/

Intuition:
If we knew maximum depth of left child(L) and right child(R)
,then the best path touch L + R edges.

Algorithm:
We can solve this problem with two different cases:
If the longest path include the root node, then the longest path must be
the depth(root->right) + depth(root->left).
If the longest path does not include the root node, this problem is divided into
2 sub-problem: set left child and right child as the new root separately,
we could get the solution by returing the max path of left and right.

Time Complexity: O(N). as we visit every node once.
Space Complexity: O(N). The size of implicit call stack during DFS.

핵심: 모든 노드가 루트노드인지 검사하고 루트 노드라면 답은 분명 왼쪽 가장 긴 깊이 + 오른쪽 가장 깊은 깊이
일것그다. 그래서 모든 노드를 방문할때마다 max인지 확인 해 보고, 다음 루트 노드를 위해 가장 깊은
깊이를 반환한다.
*/

#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root, &ans);
        return ans;
    }

    int dfs(TreeNode* root, int* ans) {
        if (root == nullptr) {
            return 0;
        }
        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);
        *ans = max(*ans, l + r);
        return max(l, r) + 1;
    }
};