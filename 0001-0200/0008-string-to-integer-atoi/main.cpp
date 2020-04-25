class Solution {
  public:
    int myAtoi(string str) {
        int res = 0;
        int sign = 1;

        int i = 0;
        while (str[i] == ' ') ++i;

        if (str[i] == '-') {
            sign = -1;
            ++i;
        } else if (str[i] == '+') {
            ++i;
        }

        char c;
        while (isDigit(c = str[i])) {
            int t = c - '0';

            if (res > 214748364)
                return 2147483647;
            if (res < -214748364)
                return -2147483648;
            if (res == 214748364 && t > 7)
                return 2147483647;
            if (res == -214748364 && t > 8)
                return -2147483648;

            res = t * sign + res * 10;
            ++i;
        }

        return res;
    }

    bool isDigit(char c) { return '0' <= c && c <= '9'; }
};