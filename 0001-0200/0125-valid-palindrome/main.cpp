class Solution {
  public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;

        int n = s.size() - 1;
        int left = 0, right = n;

        while (left < right) {
            while (left <= n && shouldPass(s[left])) ++left;
            while (right >= 0 && shouldPass(s[right])) --right;
            if (left >= right)
                break;

            if (tolower(s[left]) != tolower(s[right]))
                return false;

            ++left;
            --right;
        }
        return true;
    }

    bool shouldPass(char c) {
        if ('0' <= c && c <= '9')
            return false;
        char t = tolower(c);
        if ('a' <= t && t <= 'z')
            return false;
        return true;
    }
};