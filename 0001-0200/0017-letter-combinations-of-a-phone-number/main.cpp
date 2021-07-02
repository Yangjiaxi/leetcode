#include <iostream>
#include <map>
#include <vector>
using namespace std;

template <typename T> void out(vector<T> vec) {
    for (T e : vec) cout << e << " ";
    cout << endl;
}

class Solution {
  public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        map<char, vector<char>> tab = {
            {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},      {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}}, {'6', {'m', 'n', 'o'}},      {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},
        };
        vector<string> prev{""};
        vector<string> ans;
        for (char d : digits) {
            for (string s : prev)
                for (char c : tab[d]) ans.push_back(s + c);
            ans.swap(prev);
            ans.clear();
        }
        return prev;
    }
};

int main() {
    Solution a;
    auto res = a.letterCombinations("2");
    out(res);
    return 0;
}