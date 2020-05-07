class Solution {
  public:
    int calculateMinimumHP(vector<vector<int>> &map) {
        int m = map.size();
        int n = map[0].size();

        vector<int> dp(n + 1, INT_MAX);

        dp[n - 1] = 0;

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[j] = min(dp[j], dp[j + 1]) - map[i][j];
                if (dp[j] < 0)
                    dp[j] = 0;
            }
        }
        return dp[0] + 1;
    }
};