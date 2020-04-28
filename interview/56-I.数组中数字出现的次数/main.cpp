class Solution {
  public:
    vector<int> singleNumbers(vector<int> &nums) {
        int diff = 0;

        for (auto n : nums) diff ^= n;

        int lowbit = diff & (-diff);

        int a, b;
        a = b = 0;
        for (auto n : nums) {
            if (n & lowbit)
                a ^= n;
            else
                b ^= n;
        }

        return {a, b};
    }
};