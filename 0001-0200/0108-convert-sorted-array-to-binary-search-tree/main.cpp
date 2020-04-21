class Solution {
  public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return solve(nums, 0, nums.size() - 1);
    }

    static TreeNode *solve(vector<int> &nums, int l, int r) {
        if (l > r)
            return nullptr;
        int mid = (r + l) >> 1;
        auto tmp = new TreeNode(nums[mid]);
        tmp->left = solve(nums, l, mid - 1);
        tmp->right = solve(nums, mid + 1, r);
        return tmp;
    }
};