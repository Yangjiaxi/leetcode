#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    bool isValidBST(TreeNode *root) {
        return valid(root, LLONG_MIN, LLONG_MAX);
    }

    bool valid(TreeNode *root, long lower, long upper) {
        if (!root)
            return true;

        int v = root->val;
        if (v <= lower || v >= upper || !valid(root->left, lower, v) ||
            !valid(root->right, v, upper))
            return false;
        return true;
    }
};

int main() {
    Solution a;
    auto node = new TreeNode(2147483647);
    node->left = new TreeNode(2147483647);
    cout << a.isValidBST(node) << endl;
    return 0;
}