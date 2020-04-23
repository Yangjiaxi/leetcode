class Solution {
  public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (!n)
            return "";
        if (n == 1)
            return string(1, s[0]);

        int maxl = -1;
        int sp = 0;

        for (int i = 0; i < n; ++i) {
            auto [a, al] = spread(s, i, i);
            auto [b, bl] = spread(s, i, i + 1);
            if (maxl < al) {
                sp = a;
                maxl = al;
            }
            if (maxl < bl) {
                sp = b;
                maxl = bl;
            }
            if (maxl == n)
                break;
        }
        return s.substr(sp, maxl);
    }

    static pair<int, int> spread(const string &s, int i, int j) {
        int n = s.size();
        while (i >= 0 && j < n && i <= j && s[i] == s[j]) {
            --i;
            ++j;
        }
        return {i + 1, j - i - 1};
    }
};