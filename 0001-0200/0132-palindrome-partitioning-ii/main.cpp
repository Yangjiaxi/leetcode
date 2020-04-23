#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minCut(string s) {
        int n = s.size();
        if (!n || n == 1)
            return 0;

        vector<vector<bool>> is(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            spread(s, i, i, is);
            spread(s, i, i + 1, is);
        }

        /**dp[i] : minCut(s[:i])
         *
         * dp[i] = min{dp[j]} + 1
         *          FOR j IN 0:i
         *          WHEN is[j+1][i]
         */

        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            if (is[0][i])
                dp[i] = 0;
            else
                dp[i] = i;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (is[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1];
    }

    void spread(const string &s, int i, int j, vector<vector<bool>> &dp) {
        int n = s.size();
        while (i >= 0 && j < n && i <= j && s[i] == s[j]) {
            dp[i][j] = true;
            --i;
            ++j;
        }
    }
};

int main() {
    Solution a;
    cout << a.minCut("abab") << endl;
    return 0;
}