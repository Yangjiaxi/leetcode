class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (!n || n == 1)
            return 0;

        // dp[T][STATE]
        // 0 : empty
        // 1 : hold
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