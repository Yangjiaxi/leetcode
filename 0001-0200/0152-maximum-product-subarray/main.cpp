class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        if (!n)
            return 0;
        if (n == 1)
            return nums[0];

        int cmax, cmin, res;
        cmax = cmin = 1;
        res = INT_MIN;
        for (auto e : nums) {
            if (e < 0) {
                int t = cmax;
                cmax = cmin;
                cmin = t;
            }
            cmax = max(cmax * e, e);
            cmin = min(cmin * e, e);
            res = max(cmax, res);
        }
        return res;
    }
};