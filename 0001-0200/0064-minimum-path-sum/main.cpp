class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid) {
        vector<int> dp(grid[0]);
        int m = grid.size();
        int n = dp.size();

        for (int j = 1; j < n; ++j)
            dp[j] += dp[j - 1];

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!j)
                    dp[j] += grid[i][j];
                else
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};