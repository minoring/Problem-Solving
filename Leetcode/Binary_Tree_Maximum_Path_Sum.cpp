/**
Tree는 뭘 return 해야 하는지 생각.
정답 = 외쪽 최대 or 0 + 지금 + 오른쪽 최대 or 0
지금 루트는 트리의 부분일 수 있으니 최대 path return.
 */
class Solution {
    int answer;
public:
    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        answer = max(answer, root->val + l + r);
        return max(0, root->val + max(l, r));
    }
    int maxPathSum(TreeNode* root) {
        answer = INT_MIN;
        dfs(root);
        return answer;
    }
};