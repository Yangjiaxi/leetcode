struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    void recoverTree(TreeNode *root) {
        /**
         * Morris 中序遍历
         *   1. 非递归实现
         *   2. 常数的临时空间
         */
        if (root == nullptr)
            return;

        TreeNode *current, *prev;
        current = root;

        TreeNode *x, *y, *lastVal;
        lastVal = x = y = nullptr;

        while (current != nullptr) {
            if (current->left == nullptr) {
                if (lastVal != nullptr && current->val < lastVal->val) {
                    y = current;
                    if (x == nullptr)
                        x = lastVal;
                }
                lastVal = current;

                current = current->right;
            } else {
                prev = current->left;
                while (prev->right != nullptr && prev->right != current) {
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    prev->right = current;
                    current = current->left;
                } else {
                    if (lastVal != nullptr && current->val < lastVal->val) {
                        y = current;
                        if (x == nullptr)
                            x = lastVal;
                    }
                    lastVal = current;

                    prev->right = nullptr;
                    current = current->right;
                }
            }
        }
        int tmp = x->val;
        x->val = y->val;
        y->val = tmp;
    }
};