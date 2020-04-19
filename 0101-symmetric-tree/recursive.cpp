struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    bool isSymmetric(TreeNode *root) {
        return solve(root, root); // for null pointer
    }

    bool solve(TreeNode *a, TreeNode *b) {
        if (!a && !b)
            return true;
        if (!a || !b)
            return false;
        if (a->val != b->val)
            return false;
        return solve(a->left, b->right) && solve(a->right, b->left);
    }
};