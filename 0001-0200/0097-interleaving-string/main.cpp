#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size())
            return false;

        /**
         * dp[i][j] : s1[:i-1] + s2[:j-1] ~ s3[:i+j-1] ?
         *
         */
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (!i && !j)
                    continue;
                bool a = false, b = false;
                if (i && s1[i - 1] == s3[i + j - 1])
                    a = dp[i - 1][j];
                if (j && s2[j - 1] == s3[i + j - 1])
                    b = dp[i][j - 1];
                dp[i][j] = a || b;
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution a;
    cout << a.isInterleave("a", "a", "aa") << endl;
    return 0;
}
