class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> combs;
    vector<int> curr;
    helper(combs, curr, n, 1, k);
    return combs;
  }

  void helper(vector<vector<int>> &combs, vector<int> &curr, int n, int start,
              int k) {
    if (k == 0) {
      combs.push_back(curr);
      return;
    }

    for (int i = start; i <= n; ++i) {
      curr.push_back(i);
      helper(combs, curr, n, i + 1, k - 1);
      curr.pop_back();
    }
  }
};
