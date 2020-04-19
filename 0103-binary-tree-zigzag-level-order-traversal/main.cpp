struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        bool toRight = true;
        vector<vector<int>> res;
        if (!root)
            return res;

        vector<int> level;

        queue<TreeNode *> Q;
        Q.push(root);

        TreeNode *curr;
        TreeNode *mark = root;

        while (!Q.empty()) {
            curr = Q.front();
            Q.pop();

            if (toRight)
                level.push_back(curr->val);
            else
                level.insert(level.begin(), curr->val);
            if (curr->left)
                Q.push(curr->left);
            if (curr->right)
                Q.push(curr->right);

            if (curr == mark) {
                mark = Q.back();
                res.emplace_back(level);
                level = vector<int>();
                toRight = !toRight;
            }
        }
        return res;
    }
};