/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    int kthSmallest(TreeNode *root, int k) {
        int answer = -1;
        Helper(root, 0, k, answer);
        return answer;
    }

    int Helper(TreeNode *root, int curr, int k, int &answer) {
        if (root == nullptr) {
            return 0;
        }
        int left = Helper(root->left, curr, k, answer);
        int curr_k = curr + left + 1;
        if (answer == -1 && curr_k == k) {
            answer = root->val;
            return 0;
        }
        int right = Helper(root->right, curr_k, k, answer);
        return left + right + 1;
    }
};
