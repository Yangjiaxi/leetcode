class Solution {
  public:
    int orderOfLargestPlusSign(int N, vector<vector<int>> &mines) {
        int ms = mines.size();
        if (!ms)
            return (N + 1) / 2;

        vector<vector<int>> map(N + 2, vector<int>(N + 2, 0));

        vector<vector<int>> left(N + 2, vector<int>(N + 2, 0));
        vector<vector<int>> right(N + 2, vector<int>(N + 2, 0));
        vector<vector<int>> up(N + 2, vector<int>(N + 2, 0));
        vector<vector<int>> down(N + 2, vector<int>(N + 2, 0));

        for (auto &ele : mines) map[ele[0] + 1][ele[1] + 1] = 1; // set mine

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (map[i][j])
                    left[i][j] = up[i][j] = 0;
                else {
                    left[i][j] = left[i][j - 1] + 1;
                    up[i][j] = up[i - 1][j] + 1;
                }

                int x = N + 1 - i;
                int y = N + 1 - j;
                if (map[x][y])
                    down[x][y] = right[x][y] = 0;
                else {
                    down[x][y] = down[x + 1][y] + 1;
                    right[x][y] = right[x][y + 1] + 1;
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (!map[i][j]) {
                    int t = up[i][j];
                    t = min(t, down[i][j]);
                    t = min(t, left[i][j]);
                    t = min(t, right[i][j]);
                    ans = max(ans, t);
                }
            }
        }

        return ans;
    }
};