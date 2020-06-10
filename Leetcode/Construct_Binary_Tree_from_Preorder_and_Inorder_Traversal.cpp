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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty()) {
      return nullptr;
    }
    for (int i = 0; i < inorder.size(); ++i) {
      m[inorder[i]] = i;
    }
    return helper(preorder, inorder, 0, preorder.size() - 1);
  }

  TreeNode *helper(const vector<int> &preorder, const vector<int> &inorder,
                   int lo, int hi) {
    if (lo < 0 || lo > hi) {
      return nullptr;
    }
    TreeNode *newNode = new TreeNode(preorder[preIdx]);
    int inIdx = m.at(preorder[preIdx]);
    preIdx++;
    if (lo == hi) {
      return newNode;
    }
    newNode->left = helper(preorder, inorder, lo, inIdx - 1);
    newNode->right = helper(preorder, inorder, inIdx + 1, hi);
    return newNode;
  }
  unordered_map<int, int> m;
  int preIdx = 0;
};
