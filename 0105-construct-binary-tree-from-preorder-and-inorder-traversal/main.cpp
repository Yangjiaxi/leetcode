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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (!preorder.size())
            return nullptr;
        int root = preorder[0];
        auto it = find(inorder.cbegin(), inorder.cend(), root);
        int rootIndex = distance(inorder.cbegin(), it);
        int leftN = rootIndex;
        int rightN = inorder.size() - rootIndex - 1;
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;
        if (leftN > 0) {
            vector<int> leftIn(inorder.cbegin(), inorder.cbegin() + leftN);
            vector<int> leftPre(preorder.cbegin() + 1,
                                preorder.cbegin() + 1 + leftN);
            if (leftIn.size() > 1)
                left = buildTree(leftPre, leftIn);
            else
                left = new TreeNode(leftPre[0]);
        }
        if (rightN > 0) {
            vector<int> rightIn(inorder.cbegin() + rootIndex + 1,
                                inorder.cbegin() + rootIndex + rightN + 1);
            vector<int> rightPre(preorder.cbegin() + rootIndex + 1,
                                 preorder.cbegin() + rootIndex + rightN + 1);
            if (rightIn.size() > 1)
                right = buildTree(rightPre, rightIn);
            else
                right = new TreeNode(rightPre[0]);
        }
        return makeNode(left, root, right);
    }

    static TreeNode *makeNode(TreeNode *left, int val, TreeNode *right) {
        auto tmp = new TreeNode(val);
        tmp->left = left;
        tmp->right = right;
        return tmp;
    }
};