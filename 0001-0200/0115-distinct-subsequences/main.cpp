class Solution {
  public:
    long long numDistinct(string s, string t) {
        int m = t.size();
        int n = s.size();
        if (!m && !n)
            return true;
        if (!m || !n)
            return false;
        if (m == n)
            return s == t;
        if (m > n)
            return false;

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        for (int j = 1; j <= n; ++j) {
            if (t[0] == s[j - 1])
                dp[1][j] = 1 + dp[1][j - 1];
            else
                dp[1][j] = dp[1][j - 1];
        }

        for (int i = 2; i <= m; ++i) {
            for (int j = i; j <= n; ++j) {
                if (t[i - 1] == s[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }

        return dp[m][n];
    }
};