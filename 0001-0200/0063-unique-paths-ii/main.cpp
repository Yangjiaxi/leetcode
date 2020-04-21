class Solution {
  public:
    long long uniquePathsWithObstacles(vector<vector<int>> &map) {
        if (map[0][0])
            return 0;

        int m = map.size();
        int n = map[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int j = 1; j < n; ++j) {
            if (map[0][j])
                break;
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; ++i) {
            if (map[i][0])
                break;
            dp[i][0] = 1;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (map[i][j])
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};