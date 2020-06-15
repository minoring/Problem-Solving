class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &T) {
    const int n = T.size();
    stack<int> st;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; --i) {
      while (!st.empty() && T[st.top()] <= T[i]) {
        st.pop();
      }
      if (st.empty()) {
        ans[i] = 0;
      } else {
        ans[i] = st.top() - i;
      }
      st.push(i);
    }
    return ans;
  }
};
