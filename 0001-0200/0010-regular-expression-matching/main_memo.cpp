#include <iostream>
using namespace std;

class Solution {
  public:
    bool isMatch(string s, string p) {
        int slen = s.length();
        int plen = p.length();

        bool dp[slen + 1][plen + 1];
        dp[slen][plen] = true;
        for (int i = slen; i >= 0; --i) {
            for (int j = plen - 1; j >= 0; --j) {
                bool firstMatch = i < slen && (p[j] == s[i] || p[j] == '.');
                if (j + 1 < plen && p[j + 1] == '*')
                    dp[i][j] = dp[i][j + 2] || (firstMatch && dp[i + 1][j]);
                else
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
};

int main() {
    Solution a;
    assert(!a.isMatch("aa", "a"));
    assert(a.isMatch("aa", "a*"));
    assert(a.isMatch("ab", ".*"));
    assert(a.isMatch("aab", "c*a*b"));
    assert(!a.isMatch("mississippi", "mis*is*p*."));
    return 0;
}