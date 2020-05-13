#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool IsPrec(char a, char b) {
    if (b == '(') {
        return true;
    }
    if (b == '*' || b == '/') {
        return false;
    }
    if (a == '*' || a == '/') {
        return true;
    }
    return false;
}

int main() {
    string expr;
    cin >> expr;
    stack<char> st;

    for (char c : expr) {
        if (c >= 'A' && c <= 'Z') {
            cout << c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && !IsPrec(c, st.top())) {
                cout << st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << '\n';
}
