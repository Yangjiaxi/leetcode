#include <iostream>
#include <stack>

using namespace std;

class MaxStack {
  private:
    stack<int> real;
    stack<int> wing;

  public:
    /** initialize your data structure here. */
    MaxStack() : real(), wing() {}

    void push(int x) {
        real.push(x);

        if (wing.empty())
            wing.push(x);
        else {
            int t = wing.top();
            if (x > t)
                wing.push(x);
            else
                wing.push(t);
        }
    }

    void pop() {
        real.pop();
        wing.pop();
    }

    int top() { return real.top(); }

    int getMax() { return wing.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MaxStack s;
    s.push(10);
    cout << s.getMax() << endl;
    s.push(5);
    cout << s.getMax() << endl;
    return 0;
}