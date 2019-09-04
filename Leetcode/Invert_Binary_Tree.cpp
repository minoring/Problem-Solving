#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Approach: Recursive
class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);

        return root;
    }
};

// Approach: Iterative
class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            TreeNode* curr = que.front();
            que.pop();

            swap(curr->left, curr->right);

            if (curr->left != nullptr) {
                que.push(curr->left);
            }
            if (curr->right != nullptr) {
                que.push(curr->right);
            }
        }

        return root;
    }
};

/*
https://leetcode.com/problems/invert-binary-tree/
Since each node in the tree is visited only once, the time complexity is
O(n), where n is the number of nodes in the tree. We cannot do better than
that, since at the very least we have to visit each node to invert it.

Because of recursion, O(h) function calls will be placed on the stack in the
worst case, where h is the height of the tree. Because h ∈ O(n), the 
space complexity is O(N).
*/