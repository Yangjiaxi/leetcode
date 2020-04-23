#include <array>
#include <iostream>
#include <vector>

using namespace std;

class Trie {
  public:
    Trie() : next(), exist() {
        next.emplace_back();
        exist.emplace_back();
    }

    void insert(const string &str) {
        int cur = 0;
        int l = str.size();
        for (int i = 0; i < l; ++i) {
            int tr = mapper(str.at(i));
            if (!next[cur][tr]) {
                next[cur][tr] = ++state;
                next.emplace_back();
                exist.emplace_back(false);
            }
            cur = next[cur][tr];
        }
        exist[cur] = true;
    }

    bool find(const string &str) {
        int cur = 0;
        int l = str.size();
        for (int i = 0; i < l; ++i) {
            int tr = mapper(str.at(i));
            if (!next[cur][tr])
                return false;
            cur = next[cur][tr];
        }
        return exist[cur];
    }
    int mapper(char c) { return c - 'a'; }

  private:
    vector<array<unsigned, 26>> next;
    vector<bool> exist;
    unsigned state = 0;
};

class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int n = s.size();
        if (!n)
            return true;
        if (!wordDict.size())
            return false;

        Trie dict;
        for (auto s : wordDict) {
            dict.insert(s);
        }

        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.find(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution a;
    string s = "applepenapplepen";
    vector<string> d{"apple", "pen"};
    cout << a.wordBreak(s, d) << endl;
    return 0;
}