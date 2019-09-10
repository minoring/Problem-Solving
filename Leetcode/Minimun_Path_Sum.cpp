/*
https://leetcode.com/problems/minimum-path-sum/
Approach: DP
Intuition:
Suppose the minumun path sum of arriving at point (i, j) is dp[i][j],
then the state equationis dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
Time Complexity: O(m*n)
Space Complexity: O(m*n)
Note: 2-d vector initialization.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int> > dp(m, vector<int>(n, grid[0][0]));

        for (int i = 1; i < m; ++i) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};