class Solution {
  public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        int upto = 0;

        for (int i = 0; i < n - 1; ++i) {
            if (i <= upto && i + nums[i] >= upto) {
                upto = i + nums[i];
                if (upto >= n - 1) return true;
            }
            if (i > upto) return false;
        }

        return upto >= n - 1;
    }
};