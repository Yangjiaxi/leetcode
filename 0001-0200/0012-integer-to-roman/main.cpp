class Solution {
  public:
    string intToRoman(int num) {
        vector<int> n{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> s{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res;
        int i = 0;
        while (num) {
            while (num >= n[i]) {
                res.append(s[i]);
                num -= n[i];
            }
            ++i;
        }
        return res;
    }
};