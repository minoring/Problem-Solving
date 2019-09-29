/*
https://leetcode.com/problems/path-sum-iii/
Approach: Recursive
Note: 재귀함수가 자기자신을 부르는것 (이 노드를 포함 안한것)과, 계속 더해가는것
두개로 나뉘는데, 원래 함수가 자기자신을 호출하는 형태를 처음봤음.
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return sumUp(root, 0, sum) + pathSum(root->left, sum) +
               pathSum(root->right, sum);
    }

    int sumUp(TreeNode* root, int curr, int sum) {
        if (!root) return 0;
        curr += root->val;
        return (curr == sum) + sumUp(root->left, curr, sum) +
               sumUp(root->right, curr, sum);
    }
};