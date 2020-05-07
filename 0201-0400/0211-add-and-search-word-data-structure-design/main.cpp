class WordDictionary {
  public:
    /** Initialize your data structure here. */
    WordDictionary() : next(), exist() {
        next.emplace_back();
        exist.emplace_back();
    }

    /** Adds a word into the data structure. */
    void addWord(string str) {
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

    bool walk_from(int current, const string &str, int idx) {
        if (idx >= str.size())
            return exist[current];

        char c = str.at(idx);
        if (c == '.') {
            for (int i = 0; i < 26; ++i) {
                int tmp = next[current][i];
                if (tmp && walk_from(tmp, str, idx + 1)) {
                    return true;
                }
            }
        } else {
            int tr = mapper(c);
            int tmp = next[current][tr];
            if (!tmp)
                return false;
            return walk_from(tmp, str, idx + 1);
        }

        return false;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to
     * represent any one letter. */

    bool search(const string &str) { return walk_from(0, str, 0); }

    int mapper(char c) { return c - 'a'; }

  private:
    vector<array<unsigned, 26>> next;
    vector<bool> exist;
    unsigned state = 0;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */