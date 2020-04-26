class Solution {
  public:
    bool isValid(string s) {
        int n = s.size();
        if (!n)
            return true;
        if (n == 1)
            return false;
        stack<char> st;
        for (char c : s) {
            if (isLeft(c))
                st.push(c);
            else if (!st.empty() && canMatch(st.top(), c))
                st.pop();
            else
                return false;
        }
        return st.empty();
    }

    bool isLeft(char c) { return c == '(' || c == '{' || c == '['; }

    bool canMatch(char a, char b) {
        switch (a) {
            case '(':
                return b == ')';
            case '{':
                return b == '}';
            case '[':
                return b == ']';
            default:
                return false;
        }
        return false;
    }
};