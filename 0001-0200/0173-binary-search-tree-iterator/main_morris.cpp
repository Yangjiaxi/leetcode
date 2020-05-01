/**
 * time: 92ms, 33.90%
 * mem:  26.2MB, 6.67%
 *
 * BUTT WHY ?? :(
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
  private:
    TreeNode *current;

  public:
    BSTIterator(TreeNode *root) : current(root) {}

    /** @return the next smallest number */
    int next() {
        int res = 0;
        while (1) {
            if (!current->left) {
                res = current->val;
                current = current->right;
                return res;
            } else {
                auto rightmost = current->left;
                while (rightmost->right && rightmost->right != current) {
                    rightmost = rightmost->right;
                }
                if (!rightmost->right) {
                    rightmost->right = current;
                    current = current->left;
                } else {
                    rightmost->right = nullptr; // remove temp link
                    res = current->val;
                    current = current->right;
                    return res;
                }
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() { return current; }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */