//#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') brackets.push(s[i]);

            if (brackets.size() == 0) return false;

            if (s[i] == ')') {
                if (brackets.top() != '(') return false;
                brackets.pop();
            }
            else if (s[i] == '}') {
                if (brackets.top() != '{') return false;
                brackets.pop();
            }
            else if (s[i] == ']') {
                if (brackets.top() != '[') return false;
                brackets.pop();
            }
        }

        return brackets.size() == 0;
    }
};
