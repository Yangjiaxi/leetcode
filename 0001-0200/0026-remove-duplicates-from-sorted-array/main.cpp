class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        if (!n)
            return 0;
        if (n == 1)
            return 1;
        int j = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[j])
                nums[++j] = nums[i];
        }
        return j + 1;
    }
};