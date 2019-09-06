/*
Approach #1: Brute force
Enumerate all subsets of coin frequencies [x0...xn-1]
Time Complexity: O(S^n). 
In worst case, complexity is exponential in the number of the coins n.
The Reason is that every coin denomination ci could have at most
S/ci values. Therefore the number of possible combinations is:
S/c1 * S/c2 * S/c3 ... S/cn = S^n/c1*...*cn
Space Complexity: O(n).
In the worst case the maximum depth of recursion is n.
Therefore we need O(n) space used by the system recursive stack.
*/
#include <climits>
#include <vector>

using namespace std;

class SolutionOne {
   public:
    int coinChange(vector<int>& coins, int amount) {
        return coinChangeHelper(0, coins, amount);
    }

    int coinChangeHelper(int idx_coin, vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        if (idx_coin < coins.size() && amount > 0) {
            int max_count = amount / coins[idx_coin];
            int min_res = INT_MAX;
            for (int x = 0; x <= max_count; ++x) {
                if (amount >= x * coins[idx_coin]) {
                    int res = coinChangeHelper(idx_coin, coins,
                                               amount - x * coins[idx_coin]);
                    if (res != -1) {
                        min_res = min(min_res, res + x);
                    }
                }
            }
            return (min_res == INT_MAX) ? -1 : min_res;
        }

        return -1;
    }
};
