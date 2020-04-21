#include <iostream>
#include <stack>

using namespace std;

class Solution {
  public:
    int longestValidParentheses(string s) {
        if (s.empty())
            return 0;
        int maxn, curr;
        maxn = curr = 0;
        stack<int> S;
        S.push(-1);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                S.push(i);
            else {
                S.pop();
                if (S.empty())
                    S.push(i);
                else {
                    maxn = max(maxn, i - S.top());
                }
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
    assert(a.longestValidParentheses("()(()") == 2);
    return 0;
}