class Solution {
  public:
    using AnsType = vector<string>;
    AnsType generateParenthesis(int n) {
        if (n == 1) return AnsType{"()"};

        vector<AnsType> dp(n + 1, AnsType());
        dp[0] = AnsType{""};
        dp[1] = AnsType{"()"};

        return solve(dp, n);
    }

    AnsType &solve(vector<AnsType> &dp, int k) {
        if (!dp[k].empty()) return dp[k];

        // (a)b
        // (f(p)) * f(q),  p + q + 1 = k => q = k - 1 - q
        for (int p = 0; p < k; ++p) {
            auto &ans_m = solve(dp, p);
            auto &ans_n = solve(dp, k - 1 - p);
            for (auto &a : ans_m)
                for (auto &b : ans_n) dp[k].push_back("(" + a + ")" + b);
        }
        return dp[k];
    }
};