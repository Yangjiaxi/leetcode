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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            mapper.emplace(inorder[i], i);
        }
        rootIndexPost = postorder.size() - 1;
        return solve(0, inorder.size() - 1, inorder, postorder);
    }

    TreeNode *solve(int leftIndex,
                    int rightIndex,
                    vector<int> &inorder,
                    vector<int> &postorder) {
        if (leftIndex > rightIndex)
            return nullptr;

        int val = postorder.at(rootIndexPost);
        auto root = new TreeNode(val);

        int rootIndexIn = mapper[val];
        --rootIndexPost;
        root->right = solve(rootIndexIn + 1, rightIndex, inorder, postorder);
        root->left = solve(leftIndex, rootIndexIn - 1, inorder, postorder);
        return root;
    }

  private:
    unordered_map<int, int> mapper;
    int rootIndexPost;
};