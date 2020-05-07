class Solution {
  public:
    int trap(vector<int> &height) {
        // DOUBLE POINTER SOLUTION

        int left = 0;
        int right = height.size() - 1;
        int left_max = 0;
        int right_max = 0;

        int ans = 0;
        while (left < right) {
            int lh = height[left];
            int rh = height[right];
            if (lh < rh) {
                if (left_max < lh)
                    left_max = lh;
                else
                    ans += (left_max - lh);
                ++left;
            } else {
                if (right_max < rh)
                    right_max = rh;
                else
                    ans += (right_max - rh);
                --right;
            }
        }
        return ans;
    }
};