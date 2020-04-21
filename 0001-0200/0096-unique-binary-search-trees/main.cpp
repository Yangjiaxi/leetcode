#include <stdio.h>

class Solution {
  public:
    /**
        区间型DP
        阶段:一共i(1->n)个节点[1,2,...,n]
          状态:以j(1->i)为根节点时,解的个数f[i]

        f[0] = f[1]  =1
        f[i] = Sum_{j=1}^{i} f[j-1] * f[i-j]

        e.g.
        6个节点以3为根,左边为[1,2]右边为[4,5,6]
        由于[4,5,6]同构于[1,2,3]因此i-1=2, n-i=6-3=3
        则f[3,7]=f[2]*f[3]
    */
    int numTrees(int n) {
        int res[n + 1];
        res[0] = res[1] = 1;
        for (int i = 2; i <= n; ++i) {
            res[i] = 0;
            for (int j = 1; j <= i; ++j) {
                res[i] += res[j - 1] * res[i - j];
            }
        }
        return res[n];
    }
};

int main() {
    Solution s;
    printf("%d\n", s.numTrees(4));
    return 0;
}