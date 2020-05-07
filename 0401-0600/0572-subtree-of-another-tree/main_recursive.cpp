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
  private:
    bool isIdentical(TreeNode *s, TreeNode *t) {
        if (!s && !t)
            return true;
        if (!s || !t)
            return false;
        if (s->val != t->val)
            return false;
        return isIdentical(s->left, t->left) && isIdentical(s->right, t->right);
    }

  public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (!s)
            return false;
        return isIdentical(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};