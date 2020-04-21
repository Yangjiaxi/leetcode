#include <iostream>

using namespace std;

class Solution {
  public:
    int longestValidParentheses(string s) {
        if (s.empty())
            return 0;
        int dp[s.length()];
        int maxn = 0;
        dp[0] = 0;
        for (int i = 1; i < s.length(); ++i) {
            dp[i] = 0;
            if (s[i] == ')') {
                if (s[i - 1] == '(')
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                else {
                    int tmp = i - dp[i - 1];
                    if (tmp > 0 && s[tmp - 1] == '(')
                        dp[i] = dp[i - 1] + (tmp >= 2 ? dp[tmp - 2] : 0) + 2;
                }
                maxn = max(maxn, dp[i]);
            }
        }
        return maxn;
    }
};

int main() {
    Solution a;
    assert(a.longestValidParentheses("") == 0);
    assert(a.longestValidParentheses("((()))") == 6);
    assert(a.longestValidParentheses("(()") == 2);
    assert(a.longestValidParentheses(")()())") == 4);
    return 0;
}