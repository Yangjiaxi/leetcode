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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root)
            return res;

        TreeNode *current, *rightmost;
        current = root;
        while (current) {
            if (!current->left) {
                res.push_back(current->val);
                current = current->right; // to right sub tree
            } else {
                rightmost = current->left;
                while (rightmost->right && rightmost->right != current) {
                    rightmost = rightmost->right;
                }

                if (!rightmost->right) {
                    res.push_back(current->val);
                    rightmost->right = current;
                    current = current->left; // to left sub tree
                } else {
                    rightmost->right = nullptr;
                    current = current->right; // back to root
                }
            }
        }
        return res;
    }
};