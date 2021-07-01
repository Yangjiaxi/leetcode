class Solution {
  public:
    /*
        C_n^m= n!/(m!(n-m)!)
        C_n^{m-1}
            = n!/((m-1)!(n-m+1)!)
            = m * n! / ((n-m)! * (n-m+1))
            = m/(n-m+1) * C_n^m

        therefore:
        C_n^m = (n-m+1) / m * C_n^{m-1}
        A[m] = (n-m+1) / m * A[m-1]
    */
    vector<int> getRow(int k) {
        if (k == 0) return {1};
        vector<int> ans(k + 1, 1);

        for (int m = 1; m <= k; ++m) {
            ans[m] = int((long long)(k - m + 1) * ans[m - 1] / m);
        }
        return ans;
    }
};