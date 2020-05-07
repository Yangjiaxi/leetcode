class Solution {
  public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (!n)
            return 0;
        if (n == 1)
            return nums[0];

        // 0 -> n-1
        // A. steal 0
        // B. steal n-1
        // C. neither [IMPOSSIBLE]

        int r = nums.size() - 1;
        int a = rob2(nums, 0, r - 1);
        int b = rob2(nums, 1, r);
        return max(a, b);
    }

    // closed range
    int rob2(vector<int> &nums, int l, int r) {
        int n = r - l + 1;

        if (!n)
            return 0;
        if (n == 1)
            return nums[l];

        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = nums[l];

        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i + l];
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};