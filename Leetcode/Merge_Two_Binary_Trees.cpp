/*
https://leetcode.com/problems/merge-two-binary-trees/solution/
Approach: Recursion
Intuition:
We change our t1 node as answer node.
If Both node is not null, then t1 is the sum value of both node.
If one node is null, then t1's child node is the other node that is not null,
which can save time not copying all nodes. 
Time Complexity: O(m). m is minumum number of nodes from the two give trees.
Space Complexity: O(m). The depth of the recursion tree can go upto m in
the case of a skewed tree. in average case, depth will be O(logm)
*/

#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        t1->val = t1->val + t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};