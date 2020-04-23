class Solution {
  public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        if (!n || n == 1)
            return 0;

        int dp0, dp1;
        dp0 = 0;
        dp1 = INT_MIN >> 1;

        for (int i = 0; i < n; ++i) {
            int v = prices[i];
            int pre0 = dp0;
            dp0 = max(dp0, dp1 + v);
            dp1 = max(dp1, pre0 - v - fee);
        }
        return dp0;
    }
};