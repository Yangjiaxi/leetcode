class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x < 10)
            return true;

        int t = x;
        int tens = 1;
        while (t >= 10) {
            tens *= 10;
            t /= 10;
        }
        while (x) {
            if (x < 10 && tens == 1)
                return true;
            if (x / tens != x % 10)
                return false;
            x %= tens;
            x /= 10;
            tens /= 100;
        }
        return x < 10;
    }
};