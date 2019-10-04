/*
https://leetcode.com/problems/min-stack/
Approach: two stack
Create one normal stack and min stack.
insert into min stack if input is smallest value.
pop from min stack if it is the value on the top of normal stack

Time Complexity: O(1)
Space Complexity: O(n)
*/
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= getMin()) s2.push(x);
    }
    void pop() {
        if (s2.top() == s1.top()) s2.pop();
        s1.pop();
    }
    int top() { return s1.top(); }
    int getMin() { return s2.top(); }
};