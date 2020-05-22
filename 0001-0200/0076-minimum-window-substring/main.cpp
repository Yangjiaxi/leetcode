class Solution {
  public:
    string minWindow(string s, string t) {
        int len_s = s.size();

        array<int, 256> need{}, window{};
        int target = 0;
        for (char c : t) {
            if (!need[c])
                ++target;
            ++need[c];
        }

        // [left, right)
        int left = 0, right = 0;
        int fitness = 0;

        int sp = 0, len = INT_MAX; // record result

        while (right < len_s) {
            char c = s[right];
            ++right;
            if (need[c]) {
                ++window[c];
                if (window[c] == need[c])
                    ++fitness;
            }

            // shrink
            while (fitness == target) {
                if (right - left < len) {
                    sp = left;
                    len = right - left;
                }

                char t = s[left];
                ++left;
                if (need[t]) {
                    if (window[t] == need[t])
                        --fitness;
                    --window[t];
                }
            }
        }

        if (len == INT_MAX)
            return "";
        return s.substr(sp, len);
    }
};