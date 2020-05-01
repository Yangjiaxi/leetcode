/**
 * time: 116ms, 11.22%
 * mem:  26.4MB, 6.67%
 *
 * LEETCODE YOU BASTARD
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
    stack<TreeNode *> S;
    TreeNode *ptr;

  public:
    BSTIterator(TreeNode *root) : S(), ptr(root) { update(); }

    /** @return the next smallest number */
    int next() {
        ptr = S.top();
        S.pop();
        int res = ptr->val;

        ptr = ptr->right;
        update();

        return res;
    }

    void update() {
        while (ptr) {
            S.push(ptr);
            ptr = ptr->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() { return !S.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */