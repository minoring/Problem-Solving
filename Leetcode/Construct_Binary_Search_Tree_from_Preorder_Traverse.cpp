/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* Helper(const vector<int>& preorder, int& idx, int limit) {
        if (idx == preorder.size() || preorder[idx] > limit) {
            return nullptr;
        }
        int root_val = preorder[idx];
        TreeNode* root = new TreeNode(root_val);
        idx++;
        root->left = Helper(preorder, idx, root_val);
        root->right = Helper(preorder, idx, limit);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return Helper(preorder, idx, INT_MAX);

    }
};