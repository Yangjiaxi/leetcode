/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
  private:
    stack<NestedInteger> st;

  public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto it = nestedList.crbegin(); it != nestedList.crend(); ++it) {
            st.push(*it);
        }
    }

    /**
     * next() is call after hasNext()
     * make sure when next() is called, st.top() is a integer,
     * which means if st.top() is a NestedInteger,
     * we must spilt every element out,
     * until st.top() is a integer.
     */
    int next() {
        auto t = st.top();
        st.pop();
        return t.getInteger();
    }

    bool hasNext() {
        while (!st.empty()) {
            auto top = st.top();
            if (top.isInteger())
                return true;
            st.pop();
            auto list = top.getList();
            for (auto it = list.crbegin(); it != list.crend(); ++it) {
                st.push(*it);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */