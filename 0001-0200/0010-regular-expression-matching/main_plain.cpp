#include <iostream>

using namespace std;

/**
 * 正则表达式匹配
 * 1. 点号，匹配一个任意字符
 * 2. 星号，匹配零个或多个前面的那一个元素
 *
 * 匹配状态 i->目标串，j->模式串
 * a. 字符：字面匹配一个i++, j++
 * b. 点号：随意匹配一个i++, j++
 * c. 星号：
 *  c1 - 不做匹配，跳过 j++
 *  c2 - 匹配一个 i++
 */

class Solution {
  private:
    string s, p;
    int plen, slen;

  public:
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        slen = s.length();
        plen = p.length();
        return match(0, 0);
    }

    bool match(int i, int j) {
        if (j >= plen)
            return i >= slen;
        auto firstMatch = matchOne(s[i], p[j]);
        if (j + 2 <= plen && p[j + 1] == '*')
            return match(i, j + 2) || (firstMatch && match(i + 1, j));
        else
            return firstMatch && match(i + 1, j + 1);
    }

    bool static matchOne(char sc, char pc) {
        if ('a' > sc || sc > 'z')
            return false;
        if (pc == '.')
            return true;
        return pc == sc;
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