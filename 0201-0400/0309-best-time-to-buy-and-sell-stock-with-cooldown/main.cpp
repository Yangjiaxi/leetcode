class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (!n || n == 1)
            return 0;

        int dp0, dp1, dpPre0;
        dp0 = dpPre0 = 0;
        dp1 = INT_MIN;
        for (int v : prices) {
            int t = dp0;
            dp0 = max(dp0, dp1 + v);
            dp1 = max(dp1, dpPre0 - v);
            dpPre0 = t;
        }
        return dp0;
    }
};