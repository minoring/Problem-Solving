/*
Approach #2: Dynamic programming - Top down
Define: F(S) - minimum number of coins to make change for amount S
using coin denominations [c0...cn-1]
The optimal solution can be constructed from optimal solutions of its 
subproblems.
Lets assume that we know F(S) and last coin's denomination is C.
F(S) = F(S-C) + 1
But we do not know which is the denomination of the last coin C.
We compute F(S-Ci) for each possible c0...cn-1 and chose the
minumun amoung them.
F(S) = min_(i=0...n0-1)F(S-c_i) + 1
subject to S - c_i >= 0
F(S) = 0, when S = 0
F(S) = -1, when n = 0
A lot of subproblems were calculated multiple times. Therefore, we should cache
the solutions to the subproblems and access them in constant time.
*/

#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Todo: 이거 없애도 될것같아 왜냐하면 amount 0인경우 밑에서 처리해줌.
        // amount 가 음수일것 같지는 않고.
        if (amount < 1) {
            return 0;
        }
        vector<int> dp;
        return coinChangeHelper(coins, amount, dp);
    }

    int coinChangeHelper(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount < 0) {
            return -1;
        }
        if (amount == 0) {
            return 0;
        }
        if (dp[amount - 1] != 0) {
            return dp[amount - 1];
        }

        int min_res = __INT_MAX__;
        for (int coin : coins) {
            int res = coinChangeHelper(coins, amount - coin, dp);
            if (res >= 0 && res < min_res) {
                min_res = res + 1;
            }
        }
        dp[amount - 1] = (min_res == __INT_MAX__) ? -1 : min_res;
        return dp[amount - 1];
    }
};