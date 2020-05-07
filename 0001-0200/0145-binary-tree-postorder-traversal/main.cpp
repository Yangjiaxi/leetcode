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
  private:
    vector<int> res;
    void solve(TreeNode *root) {
        if (root->left)
            solve(root->left);
        if (root->right)
            solve(root->right);
        res.push_back(root->val);
    }

  public:
    vector<int> postorderTraversal(TreeNode *root) {
        res = vector<int>();
        if (!root)
            return res;
        solve(root);
        return res;
    }
};