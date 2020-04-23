class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (!n || n == 1)
            return 0;

        /**dp[T][K][STATE]
            T: DAY [0, n-1]
            K: UPPER TIMES {1, 2}
            STATE:
                0 / EMPTY
                1 / HOLD

            dp[0][][0] = 0
            dp[0][][1] = -prices[0]

            Treat SELL as 1
            dp[T][K][0] = dp[T-1][K][0] / dp[T-1][K][1] + prices[T]
            dp[T][K][1] = dp[T-1][K][1] / dp[T-1][K-1][0] - prices[T]
        */
        int MAX_K = 2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(MAX_K + 1, vector<int>(2, 0)));

        for (int T = 0; T < n; ++T) {
            for (int K = MAX_K; K >= 1; --K) {
                if (!T) {
                    dp[0][K][0] = 0;
                    dp[0][K][1] = -prices[0];
                } else {
                    dp[T][K][0] = max(dp[T - 1][K][0], dp[T - 1][K][1] + prices[T]);
                    dp[T][K][1] = max(dp[T - 1][K][1], dp[T - 1][K - 1][0] - prices[T]);
                }
            }
        }

        return dp[n - 1][MAX_K][0];
    }
};