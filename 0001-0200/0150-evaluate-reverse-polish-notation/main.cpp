class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.empty())
            return 0;
        stack<int> store;
        for (auto s : tokens) {
            int op = 0;
            if (s == "+")
                op = 1;
            else if (s == "-")
                op = 2;
            else if (s == "*")
                op = 3;
            else if (s == "/")
                op = 4;
            if (op) {
                int lhs, rhs;
                rhs = store.top();
                store.pop();
                lhs = store.top();
                store.pop();
                switch (op) {
                    case 1:
                        store.push(lhs + rhs);
                        break;
                    case 2:
                        store.push(lhs - rhs);
                        break;
                    case 3:
                        store.push(lhs * rhs);
                        break;
                    case 4:
                        store.push(lhs / rhs);
                        break;
                    default:
                        break;
                }
            } else {
                store.push(stoi(s));
            }
        }
        return store.top();
    }
};