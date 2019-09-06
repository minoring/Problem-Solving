/* Apporach #3: DP - Bottom up
For the iterative solution, we think in bottom-up manner.
Before calculating F(i), we have to compute all minumun counts for
amounts up to i. On ech iteration i of the algorithm F(i) is
computed as min_{j=0...n-1}F(i-C_j)+1
F(3) = min{F(3-c_1), F(3-c_2), F(3-c_3)} + 1
     = min{F(2), F(1), F(0)}
*/
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max_val = amount + 1;
        vector<int> dp(amount + 1, max_val);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return (dp[amount] == max_val) ? -1 : dp[amount];
    }
};