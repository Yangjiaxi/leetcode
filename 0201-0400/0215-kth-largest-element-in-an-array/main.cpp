#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int k;

  public:
    int findKthLargest(vector<int> &nums, int k) {
        this->k = k;
        return maxK(nums, 0, nums.size() - 1);
    }

    int maxK(vector<int> &nums, int l, int r) {
        swap(nums[r], nums[l + (r - l) / 2]);

        int v = nums[r];
        int v_idx = l; // not align with `v = nums[r]`

        for (int i = l; i < r; ++i) {
            if (nums[i] > v) {
                swap(nums[v_idx], nums[i]);
                ++v_idx;
            }
        }

        swap(nums[v_idx], nums[r]); // now v_idx align with v

        if (v_idx + 1 == k) { // center
            return v;
        }
        if (v_idx + 1 > k) { // left
            return maxK(nums, l, v_idx - 1);
        }
        return maxK(nums, v_idx + 1, r); // right, v_idx + 1 < k
    }
};

int main() {
    Solution a;
    vector<int> t{7, 1, 4, 2, 6, 3, 5};
    cout << a.findKthLargest(t, 5) << endl;
    return 0;
}