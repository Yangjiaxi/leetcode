class Solution {
  public:
    int numDecodings(string s) {
        int len = s.size();
        if (!len)
            return 0;
        if (s[0] == '0')
            return 0;
        int a = 1, b = 1;
        for (int i = 2; i <= len; ++i) {
            int temp = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            int c = 0;
            if (temp >= 10 && temp <= 26)
                c = a;
            if (s[i - 1] > '0')
                c += b;
            a = b;
            b = c;
        }
        return b;
    }
};