#include <iostream>
#include <vector>
using namespace std;

struct Node {
    /**
     * {值， 选择}
     * 0 - Nothing
     * 1 - Insert
     * 2 - Delete
     * 3 - Replace
     */
    int val;
    int step;
};

class Solution {
  private:
    string from;
    string to;
    vector<vector<Node>> dp;

  public:
    void minDistance(const string &s1, const string &s2) {
        from = s1;
        to = s2;

        int m = from.size();
        int n = to.size();

        dp = vector<vector<Node>>(m + 1, vector<Node>(n + 1, {0, 0}));

        for (int i = 1; i <= m; ++i) dp[i][0] = {i, 1};
        for (int j = 1; j <= n; ++j) dp[0][j] = {j, 1};

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int c = dp[i - 1][j - 1].val; // 替换 or 跳过
                if (from[i - 1] == to[j - 1]) {
                    dp[i][j] = {c, 0};
                } else {
                    int a = dp[i][j - 1].val; // 插入
                    int b = dp[i - 1][j].val; // 删除
                    int minv = min3(a, b, c);

                    if (minv == a)
                        dp[i][j] = {a + 1, 1};
                    else if (minv == b)
                        dp[i][j] = {b + 1, 2};
                    else
                        dp[i][j] = {c + 1, 3};
                }
            }
        }
        // for (auto row : dp) {
        //     for (auto ele : row) {
        //         cout << "(" << ele.val << "," << ele.step << ") ";
        //     }
        //     cout << endl;
        // }

        string ori = from;
        cout << ori << "->" << endl;
        print(m, n, ori);
        cout << "->" << ori << endl;
    }

    void print(int row, int col, string &ori) {
        if (row < 0 || col < 0)
            return;
        auto choice = dp[row][col].step;
        int a = ori.length();

        if (choice == 0) {
            print(row - 1, col - 1, ori);
        } else if (choice == 1) {
            // insert
            print(row, col - 1, ori);
            int b = ori.length();
            ori.insert(row + (b - a), 1, to[col - 1]);
            cout << ori << "(+" << to[col - 1] << ")" << endl;
        } else if (choice == 2) {
            // delete
            print(row - 1, col, ori);
            int b = ori.length();
            ori.erase(row - 1 + (b - a), 1);
            cout << ori << "(-" << from[row - 1] << ")" << endl;
        } else if (choice == 3) {
            // replace
            print(row - 1, col - 1, ori);
            int b = ori.length();
            ori.at(row - 1 + (b - a)) = to[col - 1];
            cout << ori << "(" << from[row - 1] << "->" << to[col - 1] << ")" << endl;
        }
    }
    int min3(int a, int b, int c) { return min(min(a, b), c); }
};

int main() {
    Solution a;
    a.minDistance("asqnv", "nkasrwoiqvn");
    return 0;
}
