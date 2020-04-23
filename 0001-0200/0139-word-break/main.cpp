#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int n = s.size();
        if (!n)
            return true;
        if (!wordDict.size())
            return false;

        unordered_set<string> set(wordDict.cbegin(), wordDict.cend());
        /**dp[i] = can(s[0:i-1])
         *  IF s[j:i] IN set,dp[0:i] |= dp[0:j]
         */

        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && set.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution a;
    string s = "applepenapple";
    vector<string> d{"apple", "pen"};
    cout << a.wordBreak(s, d) << endl;
    return 0;
}