#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    int largestRectangleArea(vector<int> heights) {
        int maxn = 0;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stack<int> st;
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int top = st.top();
                st.pop();
                maxn = max(maxn, (i - st.top() - 1) * heights[top]);
            }
            st.push(i);
        }
        return maxn;
    }
};

int main() {
    Solution a;
    cout << a.largestRectangleArea({2, 1, 5, 6, 2, 3}) << endl;
    return 0;
}