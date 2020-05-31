class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1);

        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n + 1; ++j) {
                if (dp[i] && Contains(s.substr(i, j - i), wordDict)) {
                    dp[j] = true;
                }
            }
        }

        return dp[n];
    }

    bool Contains(const string &s, const vector<string> &wordDict) {
        if (find(wordDict.begin(), wordDict.end(), s) == wordDict.end()) {
            return false;
        }
        return true;
    }
};
