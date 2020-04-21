#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preOrder(TreeNode *root) {
    if (root == nullptr) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

class Solution {
  public:
    vector<TreeNode *> generateTrees(int n) {
        vector<vector<TreeNode *>> dp(n + 1, vector<TreeNode *>());
        dp[0].emplace_back(nullptr);
        if (n == 0) {
            dp[0].clear();
            return dp[0];
        }
        dp[1].emplace_back(new TreeNode(1));
        if (n == 1)
            return dp[1];

        // start DP
        // i: total nodes / phase
        for (int i = 2; i <= n; ++i) {
            // j: root / state
            for (int j = 1; j <= i; ++j) {
                // left:    1 -> j-1
                // right: j+1 -> i
                vector<TreeNode *> left = dp[j - 1];
                vector<TreeNode *> right = stepByN(dp[i - j], j);
                addCrossProduct(dp[i], left, right, j);
            }
        }
        return dp[n];
    }

    static void addCrossProduct(vector<TreeNode *> &cur,
                                vector<TreeNode *> &left,
                                vector<TreeNode *> &right,
                                int val) {
        for (auto leftNode : left) {
            for (auto rightNode : right) {
                cur.emplace_back(makeNode(leftNode, val, rightNode));
            }
        }
    }

    static TreeNode *cloneTree(TreeNode *root, int step) {
        if (!root) {
            return nullptr;
        }
        return makeNode(cloneTree(root->left, step),
                        root->val + step,
                        cloneTree(root->right, step));
    }

    static vector<TreeNode *> stepByN(vector<TreeNode *> &arr, int step) {
        vector<TreeNode *> newArr;
        newArr.reserve(arr.size());
        for (auto root : arr) {
            newArr.emplace_back(cloneTree(root, step));
        }
        return newArr;
    }

    static TreeNode *makeNode(TreeNode *left, int val, TreeNode *right) {
        auto *tmp = new TreeNode(val);
        tmp->left = left;
        tmp->right = right;
        return tmp;
    }
};

int main() {
    Solution a;
    auto res = a.generateTrees(3);
    for (TreeNode *tree : res) {
        preOrder(tree);
        cout << endl;
    }
    return 0;
}