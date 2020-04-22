#include <string>
using namespace std;

class Solution {
  public:
    bool isScramble(string s1, string s2) {
        int len = s1.length();
        if (len != s2.length()) {
            return false;
        }
        return solve(s1.c_str(), s2.c_str(), len);
    }

    bool solve(const char *s1, const char *s2, int len) {
        if (len == 1) {
            return s1[0] == s2[0];
        }

        int sum = 0;
        for (int i = 0; i < len; ++i) sum += s1[i] - s2[i];
        if (sum != 0)
            return false; // different char exist

        for (int i = 1; i < len; ++i) {
            if (solve(s1, s2, i) && solve(s1 + i, s2 + i, len - i)) {
                return true;
            }
            if (solve(s1, s2 + len - i, i) && solve(s1 + i, s2, len - i)) {
                return true;
            }
        }
        return false;
    }
};