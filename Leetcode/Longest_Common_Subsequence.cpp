/*
lcs("abc", "edc") = 1 + lcs("ab", "ed")

lcs("abd", "abe") = max(lcs("ab", "abe"), lcs("abd", "ab"))
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length() + 1;
        int n = text2.length() + 1;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};