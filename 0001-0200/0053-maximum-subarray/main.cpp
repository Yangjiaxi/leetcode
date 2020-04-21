class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int curr = 0, maxn = nums[0];
        for (auto n : nums) {
            if (curr > 0)
                curr += n;
            else
                curr = n;
            maxn = max(maxn, curr);
        }
        return maxn;
    }
};