class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (!n || n == 1)
            return 0;

        // int dp{total}{hold?}
        int dp20, dp21, dp10, dp11;
        dp21 = dp11 = INT_MIN;
        dp20 = dp10 = 0;

        /**
         * 注意：顺序很重要，必须20->21->10->11这样的顺序
         * 这是子问题的依赖顺序决定的
         * 只能依赖前一天的数据，不能依赖今天新的数据
         */
        for (auto v : prices) {
            dp20 = max(dp20, dp21 + v); // step 2b, sell
            dp21 = max(dp21, dp10 - v); // step 2a, buy
            dp10 = max(dp10, dp11 + v); // step 1b, sell
            dp11 = max(dp11, -v);       // step 1a, buy
        }
        return dp20;
    }
};