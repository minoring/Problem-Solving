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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) {
            return false;
        }
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, root));

        int x_depth = -1;
        int y_depth = -1;
        while (!q.empty()) {
            if (x_depth != -1 && y_depth != -1) {
                break;
            }
            int depth = q.front().first;
            TreeNode* curr = q.front().second;
            q.pop();

            if (curr->val == x) {
                x_depth = depth;
            }
            if (curr->val == y) {
                y_depth = depth;
            }
            if (curr->left != nullptr && curr->right != nullptr) {
                if ((curr->left->val == x && curr->right->val == y) ||
                    (curr->left->val == y && curr->right->val == x)) {
                    return false;
                }
            }
            if (curr->left != nullptr) {
                q.push({depth + 1, curr->left});
            }
            if (curr->right != nullptr) {
                q.push({depth + 1, curr->right});
            }
        }

        if (x_depth == y_depth) {
            return true;
        }
        return false;
    }
};