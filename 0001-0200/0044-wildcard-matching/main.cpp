#include <iostream>
#include <vector>

using namespace std;

/**
 * 正则表达式匹配
 * 1. ? - 匹配一个任意字符
 * 2. * - 匹配零个或多个任意元素
 *
 * 匹配状态 i->目标串，j->模式串
 * a. 字符：字面匹配一个i++, j++
 * b. ? 随意匹配一个i++, j++
 * c. *
 *  c1 - 不做匹配，跳过 j++
 *  c2 - 匹配一个 i++
 */

class Solution {
  private:
    string s, p;
    int plen, slen;

  public:
    bool isMatch(string s, string _p) {
        string p = fix(_p);
        int slen = s.length();
        int plen = p.length();
        cout << p << endl;

        vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
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

    string static fix(const string &t) {
        string r = "";
        for (auto c : t) {
            if (c == '?')
                r.push_back('.');
            else if (c == '*') {
                if (r.empty() || r.back() != '*')
                    r.append(".*");
                else
                    continue;
            } else
                r.push_back(c);
        }
        return r;
    }
};

int main() {
    Solution a;
    // assert(!a.isMatch("aa", "a"));
    // assert(a.isMatch("aa", "*"));
    // assert(!a.isMatch("cb", "?a"));
    // assert(a.isMatch("adceb", "*a*b"));
    // assert(!a.isMatch("acdcb", "a*c?b"));
    // assert(a.isMatch("aa", "a*"));
    // assert(a.isMatch("ab", "?*"));
    cout << a.isMatch("ho", "**ho") << endl;
    return 0;
}