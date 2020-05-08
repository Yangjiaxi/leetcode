class Solution {
  public:
    int maximalSquare(vector<vector<char>> &map) {
        int m = map.size();
        if (!m)
            return 0;
        int n = map[0].size();
        if (!n)
            return 0;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int ans = 0;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (map[i - 1][j - 1] == '1') {
                    dp[i][j] =
                        min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) +
                        1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        // for(int i = 0; i <= m; ++i) {
        //     for(int j = 0; j <= n; ++j) {
        //         if(dp[i][j] == INT_MAX) cout << "T";
        //         else cout << dp[i][j];
        //         cout << " ";
        //     }
        //     cout << endl;
        // }
        return ans * ans;
    }
};