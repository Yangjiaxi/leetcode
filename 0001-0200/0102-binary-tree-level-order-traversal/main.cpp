struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        res.emplace_back();

        queue<TreeNode *> Q;
        Q.push(root);

        TreeNode *curr;
        TreeNode *mark = root;

        while (!Q.empty()) {
            curr = Q.front();
            Q.pop();

            res.back().push_back(curr->val);
            if (curr->left)
                Q.push(curr->left);
            if (curr->right)
                Q.push(curr->right);

            if (curr == mark && !Q.empty()) {
                mark = Q.back();
                res.emplace_back();
            }
        }
        return res;
    }
};