#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
  public:
    string simplifyPath(string path) {

        vector<string> store;
        istringstream sin(path);
        string buf;

        while (getline(sin, buf, '/')) {
            if (buf.empty())
                continue;
            if (buf != "." && buf != "..") // normal path, including `...`
                store.emplace_back(buf);
            else if (buf == ".." && !store.empty()) // go back
                store.pop_back();
        }

        if (store.empty())
            return "/";

        string res;
        res.reserve(path.size());
        for (auto &s : store) {
            res.push_back('/');
            res.append(s);
        }
        return res;
    }
};

int main() {
    Solution a;
    cout << a.simplifyPath("/") << endl;
    cout << a.simplifyPath("/...") << endl;
    cout << a.simplifyPath("/////") << endl;
    cout << a.simplifyPath("/.././../../") << endl;
    cout << a.simplifyPath("/home/") << endl;
    cout << a.simplifyPath("/../") << endl;
    cout << a.simplifyPath("/home//foo/") << endl;
    cout << a.simplifyPath("/a/./b/../../c/") << endl;
    cout << a.simplifyPath("/a/../../b/../c//.//") << endl;
    cout << a.simplifyPath("/a//b////c/d//././/..") << endl;
}