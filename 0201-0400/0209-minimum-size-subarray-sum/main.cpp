class Solution {
  public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int left = 0, right = 0;
        int len = INT_MAX;

        int size = nums.size();
        int sum = 0;
        while (right < size) {
            sum += nums[right];
            ++right;

            while (sum >= s) {
                len = min(len, right - left);
                sum -= nums[left];
                ++left;
            }
        }

        if (len == INT_MAX)
            return 0;
        return len;
    }
};