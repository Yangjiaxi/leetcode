class Solution {
  public:
    double myPow(double x, int n) {
        if (x == 0 || x == 1)
            return x;
        if (x == -1)
            return (n & 1 ? -1 : 1);

        if (n == 0)
            return 1;
        if (n == 1)
            return x;

        return pow(x, n);
    }

    double pow(double a, long long b) {
        bool neg = false;
        if (b < 0) {
            b = -b;
            neg = true;
        }

        double res = 1.0;
        double base = a;
        while (b) {
            if (b & 1)
                res *= base;
            base *= base;
            b >>= 1;
        }

        if (neg)
            return 1.0 / res;
        return res;
    }
};