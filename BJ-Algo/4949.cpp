#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    while (true) {
        char inputString[102];
        cin.getline(inputString, sizeof(inputString));
        if (inputString[0] == '.') {
            break;
        }

        stack<char> st;
        bool printed = false;
        for (int i = 0; i < strlen(inputString); ++i) {
            char c = inputString[i];
            if (c == '(' || c == '[') {
                st.push(c);
            } else if (c == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    cout << "no" << '\n';
                    printed = true;
                    break;
                }
            } else if (c == ']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                } else {
                    cout << "no" << '\n';
                    printed = true;
                    break;
                }
            }
        }
        if (!printed) {
            if (st.empty()) {
                cout << "yes" << '\n';
            } else {
                cout << "no" << '\n';
            }
        }
    }
}
