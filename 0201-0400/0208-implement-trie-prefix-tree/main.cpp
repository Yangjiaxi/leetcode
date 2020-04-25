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

    bool startsWith(const string &str) { return travel(str, true); }
    bool search(const string &str) { return travel(str, false); }

    bool travel(const string &str, bool part) {
        int cur = 0;
        int l = str.size();
        for (int i = 0; i < l; ++i) {
            int tr = mapper(str.at(i));
            if (!next[cur][tr])
                return false;
            cur = next[cur][tr];
        }
        return part || exist[cur];
    }
    int mapper(char c) { return c - 'a'; }

  private:
    vector<array<unsigned, 26>> next;
    vector<bool> exist;
    unsigned state = 0;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
