class Solution {
  public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        int t;
        for (int i = 1; i < n; ++i) {
            t = b;
            b += a;
            a = t;
        }
        return b;
    }
};