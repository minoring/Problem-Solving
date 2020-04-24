 /*
 현재 diameter는 왼쪽 diameter 혹은 오른쪽 diameter 혹은 왼쪽 깊이 + 오른쪽 깊이
 두개다 중요하니 두개다 저장하면서 가자.
 */
class Solution {
    pair<int, int> dfs(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);

        int dia = max({left.first, right.first, left.second + right.second});
        return {dia, max(left.second, right.second) + 1};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).first;
    }
};