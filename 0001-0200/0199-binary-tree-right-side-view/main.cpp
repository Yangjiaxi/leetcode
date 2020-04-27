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
    vector<int> rightSideView(TreeNode *root) {
        if (!root)
            return vector<int>();

        vector<int> res;
        queue<TreeNode *> Q;
        Q.push(root);

        while (!Q.empty()) {
            int n = Q.size();
            res.emplace_back(Q.front()->val);
            while (n--) {
                auto t = Q.front();
                Q.pop();
                if (t->right)
                    Q.push(t->right);
                if (t->left)
                    Q.push(t->left);
            }
        }
        return res;
    }
};