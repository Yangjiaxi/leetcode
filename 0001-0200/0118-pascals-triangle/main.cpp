class Solution {
  public:
    vector<vector<int>> generate(int n) {
        if (n == 1) return {{1}};
        if (n == 2) return {{1}, {1, 1}};

        vector<vector<int>> a;
        a.push_back({1});
        a.push_back({1, 1});

        for (int r = 2; r < n; ++r) {
            vector<int> tmp(r + 1, 1);
            for (int i = 0; i < r - 1; ++i) tmp[i + 1] = a[r - 1][i] + a[r - 1][i + 1];
            a.push_back(tmp);
        }
        return a;
    }
};