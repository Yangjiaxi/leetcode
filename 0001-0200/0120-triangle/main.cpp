class Solution {
  public:
    int minimumTotal(vector<vector<int>> &map) {
        int n = map.size();
        if (!n)
            return 0;
        if (n == 1)
            return map[0][0];

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        int minn = INT_MAX;
        dp[0][0] = map[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (!j)
                    dp[i][0] = map[i][0] + dp[i - 1][0];
                else
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + map[i][j];
                if (i == n - 1)
                    minn = min(dp[i][j], minn);
            }
        }
        return minn;
    }
};