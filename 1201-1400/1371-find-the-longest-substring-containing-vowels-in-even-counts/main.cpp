class Solution {
  public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        if (!n)
            return 0;

        short now_state = 0; // uoiea -> Five Binary Digits
        vector<int> first_pos(1 << 5,
                              -1); // first index of specific state, 2^5 => 32
        first_pos[0] = 0;

        short jump[255] = {
            ['u'] = 1 << 4,
            ['o'] = 1 << 3,
            ['i'] = 1 << 2,
            ['e'] = 1 << 1,
            ['a'] = 1 << 0,
        };

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            now_state ^= jump[s[i]]; // update state

            if (first_pos[now_state] >= 0)
                ans = max(ans, i + 1 - first_pos[now_state]);
            else
                first_pos[now_state] = i + 1;
        }
        return ans;
    }
};