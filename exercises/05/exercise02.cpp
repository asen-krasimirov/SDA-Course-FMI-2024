#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> c1;
        stack<char> c2;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '#') {
                if (!c1.empty()) {
                    c1.pop();
                }
            }
            else c1.push(s[i]);
        }

        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == '#') {
                if (!c2.empty()) {
                    c2.pop();
                }
            }
            else c2.push(t[i]);
        }

        while (!c1.empty() && !c2.empty()) {
            if (c1.top() != c2.top()) return false;

            c1.pop();
            c2.pop();
        }

        return c1.empty() && c2.empty();
    }
};

int main() {
    Solution s;

    cout << s.backspaceCompare("y#fo##f", "y#f#o##f");

    return 0;
}