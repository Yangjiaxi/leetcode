class Solution {
  public:
    int trap(vector<int> &height) {
        // Non-Increasing Monotonic Stack Solution
        int ans = 0;
        int sz = height.size();

        stack<int> st; // indices
        for (int i = 0; i < sz; ++i) {
            while (!st.empty() && height[st.top()] < height[i]) {
                int t = st.top();
                st.pop();
                if (st.empty())
                    break; // IGNORE Leftmost Bar

                int length = i - st.top() - 1;
                int diff_height = min(height[st.top()], height[i]) - height[t];
                ans += length * diff_height;
            }
            st.push(i);
        }
        return ans;
    }
};