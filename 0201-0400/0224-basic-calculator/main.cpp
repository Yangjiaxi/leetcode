#include <iostream>
#include <sstream>

using namespace std;

class Solution {
  private:
    char token;
    string buffer;
    int index;

    char peek() {
        while (buffer[index + 1] == ' ') ++index;
        return buffer[index + 1];
    }

    void consume() {
        ++index;
        token = buffer[index];
    }

    int expr() {
        int value = factor();
        while (1) {
            if (peek() == '+') {
                consume();
                value += factor();
            } else if (peek() == '-') {
                consume();
                value -= factor();
            } else {
                break;
            }
        }
        return value;
    }

    int factor() {
        int sign = 1;
        if (peek() == '-') {
            consume();
            sign = -1;
        }

        int value;

        if (isdigit(peek())) {
            value = sign * number();
        } else if (peek() == '(') {
            consume();
            value = sign * expr();
            consume(); // match )
        }
        return value;
    }

    int number() {
        int value = 0;
        while (isdigit(peek())) {
            consume();
            value = value * 10 + (token - '0');
        }
        return value;
    }

  public:
    int calculate(const string &s) {
        buffer = s;
        index = -1;
        return expr();
    }
};

int main() {
    Solution a;
    cout << a.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    return 0;
}