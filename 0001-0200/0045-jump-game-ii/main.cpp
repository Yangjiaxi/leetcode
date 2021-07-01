class Solution {
  public:
    // f[0] = 0
    // f[n] = min{f[n], f[k]+1} (n <= k+a[k], 0 <= k < n)

    // f[0] = 0
    // f[n+i] = min{f[n+i], f[n]+1} (i <= a[n])
    int jump(vector<int> &nums) {
        int size = nums.size();
        if (size == 1) return 0;
        vector<int> dp(size, 0x3f3f3f3f);
        dp[0] = 0;

        for (int n = 0; n < size - 1; ++n) {
            if (nums[n] == 0) continue;
            for (int i = 1; i <= min(nums[n], size - 1 - n); ++i) {
                dp[n + i] = min(dp[n + i], dp[n] + 1);
                if (n + i == size - 1) return dp[size - 1];
            }
        }

        return dp[size - 1];
    }
};