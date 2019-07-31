#include <cassert>
#include <stack>
#include <string>

using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        stack<char> parentheses;
        
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                parentheses.push(c);
                continue;
            }
            if (parentheses.empty()) {
                return false;
            }
            char top = parentheses.top();
            parentheses.pop();
            if (c == ')' && top != '(') {
                return false;
            } else if (c == ']' && top != '[') {
                return false;
            } else if (c == '}' && top != '{') {
                return false;
            }
        }

        if (parentheses.empty()) {
            return true;
        } else {
            return false;
        }
    }
};