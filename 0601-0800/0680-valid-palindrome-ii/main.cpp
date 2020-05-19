class Solution {
  public:
    bool validPalindrome(string s) { return solve(s); }

    bool solve(const string &s) {
        int i, j;
        bool ch, ok;

        // omit left one
        ch = ok = true;
        i = 0;
        j = s.size() - 1;
        while (ok && i < j) {
            if (s[i] == s[j]) {
                ++i;
                --j;
            } else if (ch && s[i + 1] == s[j]) {
                i += 2;
                --j;
                ch = false;
            } else {
                ok = false;
            }
        }
        if (ok)
            return true;

        // omit right one
        ch = true;
        i = 0;
        j = s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                ++i;
                --j;
            } else if (ch && s[i] == s[j - 1]) {
                ++i;
                j -= 2;
                ch = false;
            } else {
                return false;
            }
        }
        return true;
    }
};