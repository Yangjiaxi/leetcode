class Solution {
  public:
    int maxProfit(int max_k, vector<int> &prices) {
        int n = prices.size();
        if (!n || n == 1)
            return 0;
        if (n / 2 < max_k)
            return withoutLimit(prices);

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(max_k + 1, vector<int>(2, 0)));

        for (int T = 0; T < n; ++T) {
            for (int K = max_k; K >= 1; --K) {
                if (!T) {
                    dp[0][K][0] = 0;
                    dp[0][K][1] = -prices[0];
                } else {
                    dp[T][K][0] = max(dp[T - 1][K][0], dp[T - 1][K][1] + prices[T]);
                    dp[T][K][1] = max(dp[T - 1][K][1], dp[T - 1][K - 1][0] - prices[T]);
                }
            }
        }

        return dp[n - 1][max_k][0];
    }

    int withoutLimit(vector<int> &prices) {
        int n = prices.size();
        vector<int> dp0(n, 0);
        vector<int> dp1(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!i) {
                dp0[0] = 0;
                dp1[0] = -prices[0];
            } else {
                dp0[i] = max(dp0[i - 1], dp1[i - 1] + prices[i]);
                dp1[i] = max(dp1[i - 1], dp0[i - 1] - prices[i]);
            }
        }
        return dp0[n - 1];
    }
};