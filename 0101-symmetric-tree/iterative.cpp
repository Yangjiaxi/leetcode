#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;

        queue<TreeNode *> Q;
        TreeNode *l, *r;

        Q.push(root);
        Q.push(root);
        while (!Q.empty()) {
            l = Q.front();
            Q.pop();
            r = Q.front();
            Q.pop();

            if (!l && !r)
                continue;
            if (!l || !r)
                return false;
            if (l->val != r->val)
                return false;
            Q.push(l->left);
            Q.push(r->right);
            Q.push(l->right);
            Q.push(r->left);
        }
        return true;
    }
};