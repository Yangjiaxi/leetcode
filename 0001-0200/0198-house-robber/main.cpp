class Solution {
  public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (!n)
            return 0;
        if (n == 1)
            return nums[0];

        // dp[i][K] K: 0/1 not/steal
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = nums[0];

        // dp[i][not] = max(dp[i-1][0], dp[i-1][1])
        // dp[i][steal] = dp[i-1][0] + nums[i]

        // -> res: max(dp[n-1][not], dp[n-1][steal])
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};