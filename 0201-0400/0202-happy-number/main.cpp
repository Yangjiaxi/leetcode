class Solution {
  public:
    int next(int n) {
        int res = 0;
        while (n) {
            int t = n % 10;
            res += t * t;
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = next(n);
        while (fast != 1 && slow != fast) {
            fast = next(next(fast));
            slow = next(slow);
        }
        return fast == 1;
    }
};