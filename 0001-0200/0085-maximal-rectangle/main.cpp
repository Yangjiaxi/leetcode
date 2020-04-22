class Solution {
  public:
    int maximalRectangle(vector<vector<char>> &map) {
        int m = map.size();
        if (!m)
            return 0;
        int n = map[0].size();
        if (!n)
            return 0;

        int maxn = 0;

        vector<int> row(n + 2, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) { // update per row
                if (map[i][j] == '1')
                    row[j + 1] += 1;
                else
                    row[j + 1] = 0;
            }
            maxn = max(maxn, solve(row));
        }
        return maxn;
    }

    int solve(vector<int> &heights) {
        int maxn = 0;
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