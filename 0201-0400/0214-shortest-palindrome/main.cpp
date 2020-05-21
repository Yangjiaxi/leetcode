class Solution {
  public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (!n || n == 1)
            return s;

        string rev(s);
        reverse(rev.begin(), rev.end());

        string s_all = s + "#" + rev;
        /*
            KMP的next数组：
                next[i] = j意味着s[j...i] == s[0:i-j]，后缀与前缀的最长匹配长度
                因此，当我们对拼接的字符串求next后，最后一个字符对应next.back()

                它的next值为：这个逆序字符串的后缀与原字符串前缀的最长匹配长度
                匹配的部分不用动，复制没有匹配的就行

                e.g.1: abcd # dcba
                -------------
                       abcd
                    dcba
                       ^
                -------------

                e.g.2: aacecaaa # aaacecaa
                -------------
                     aacecaaa
                    aaacecaa
                     ^^^^^^^
                -------------
        */
        auto next = get_next(s_all);
        return rev.substr(0, n - next.back()) + s;
    }

    static vector<int> get_next(const string &s) {
        int n = s.size();
        vector<int> pi(n, 0);
        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) j = pi[j - 1];
            if (s[i] == s[j])
                ++j;
            pi[i] = j;
        }
        return move(pi);
    }
};