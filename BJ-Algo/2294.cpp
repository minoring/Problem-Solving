#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    vector<int> dp(k + 1);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    const int coinMax = 10001;
    fill(dp.begin(), dp.end(), coinMax);
    dp[0] = 0;

    for (int coin : coins) {
        for (int j = coin; j <= k; ++j) {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    cout << ((dp[k] == coinMax) ? -1 : dp[k]) << '\n';
}
