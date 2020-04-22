class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (!n || n == 1)
            return 0;

        prices.emplace_back(-1);
        vector<int> st;
        int maxn = 0;
        for (auto n : prices) {
            while (!st.empty() && st.back() > n) {
                maxn = max(maxn, st.back() - st.front());
                st.pop_back();
            }
            st.push_back(n);
        }
        return maxn;
    }
};