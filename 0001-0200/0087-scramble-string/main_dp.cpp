#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isScramble(string s1, string s2) {
        int len = s1.size();
        int lb = s2.size();
        if (!len && !lb)
            return true;
        if (!len || !lb || len != lb)
            return false;

        // dp[i][j][k] : s1[i:i+l] ~ s2[j:j+k]
        // k: 1->len, len+1
        // i: 0->len-1, len
        // j: 0->len-1, len
        vector<vector<vector<bool>>> dp(len,
                                        vector<vector<bool>>(len, vector<bool>(len + 1, false)));

        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) dp[i][j][1] = s1[i] == s2[j];
        }

        for (int k = 2; k <= len; ++k) {
            for (int i = 0; i <= len - k; ++i)
                for (int j = 0; j <= len - k; ++j)
                    for (int p = 1; p < k; ++p) { // 划分位置
                        if (dp[i][j][p] && dp[i + p][j + p][k - p]) {
                            dp[i][j][k] = true;
                            break;
                        }
                        if (dp[i][j + k - p][p] && dp[i + p][j][k - p]) {
                            dp[i][j][k] = true;
                            break;
                        }
                    }
        }
        return dp[0][0][len];
    }
};

int main() {
    Solution a;
    cout << a.isScramble("great", "rgeat") << endl;
    return 0;
}