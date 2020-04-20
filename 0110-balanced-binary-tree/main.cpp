/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    bool isBalanced(TreeNode *root) {
        if (!root)
            return true;
        return diffOK(height(root->left), height(root->right)) &&
               isBalanced(root->left) && isBalanced(root->right);
    }

    bool diffOK(int x, int y) {
        int d = x - y;
        return -1 <= d && d <= 1;
    }

    int height(TreeNode *root) {
        if (!root)
            return -1;
        return 1 + max(height(root->left), height(root->right));
    }
};