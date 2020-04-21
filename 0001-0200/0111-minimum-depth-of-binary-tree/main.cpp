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
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        auto l = root->left;
        auto r = root->right;
        if (l && r)
            return 1 + min(minDepth(root->left), minDepth(root->right));
        if (l && !r)
            return 1 + minDepth(root->left);
        if (!l && r)
            return 1 + minDepth(root->right);
        return 1;
    }
};