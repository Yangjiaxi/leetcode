#include <iostream>
#include <vector>

using namespace std;

template <class T> void printVector(vector<T> a) {
    for (auto ele : a) {
        cout << ele << " ";
    }
}

template <class T> void print2DVector(vector<vector<T>> a) {
    for (auto row : a) {
        printVector(row);
        cout << endl;
    }
}

class Solution {
  public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        int n = s.size();
        if (!n)
            return res;
        if (n == 1)
            return {{string(1, s[0])}};

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            spread(s, i, i, dp);
            spread(s, i, i + 1, dp);
        }
        solve(s, 0, vector<string>(), dp, res);
        return res;
    }

    void solve(const string &s,
               int left,
               vector<string> tmp,
               vector<vector<bool>> &dp,
               vector<vector<string>> &res) {

        if (left == s.size()) {
            res.emplace_back(tmp);
            return;
        }

        for (int i = left; i < s.size(); ++i) {
            if (!dp[left][i])
                continue;
            tmp.push_back(s.substr(left, i - left + 1));
            solve(s, i + 1, tmp, dp, res);
            tmp.pop_back();
        }
    }

    void spread(const string &s, int i, int j, vector<vector<bool>> &dp) {
        int n = s.size();
        while (i >= 0 && j < n && i <= j && s[i] == s[j]) {
            dp[i][j] = true;
            --i;
            ++j;
        }
    }
};

int main() {
    Solution a;
    auto res = a.partition("");
    print2DVector(res);
    return 0;
}