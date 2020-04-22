#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int minDistance(const string &from, const string &to) {
        int m = from.size();
        int n = to.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) dp[i][0] = i;
        for (int j = 1; j <= n; ++j) dp[0][j] = j;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (from[i - 1] == to[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
        return dp[m][n];
    }

    static int min3(int a, int b, int c) { return min(min(a, b), c); }
};

int main() {
    Solution a;
    cout << a.minDistance("intention", "execution") << endl;
    return 0;
}