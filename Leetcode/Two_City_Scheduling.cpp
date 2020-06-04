class Solution {
public:
  int twoCitySchedCost(vector<vector<int>> &costs) {
    int n = costs.size();
    vector<int> diffs(n);
    int answer = 0;
    for (int i = 0; i < n; ++i) {
      answer += costs[i][0];
      diffs[i] = costs[i][1] - costs[i][0];
    }
    sort(diffs.begin(), diffs.end());
    for (int i = 0; i < n / 2; ++i) {
      answer += diffs[i];
    }
    return answer;
  }
};
