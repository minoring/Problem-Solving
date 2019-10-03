/*
https://www.acmicpc.net/problem/9465
*/

#include <algorithm>
#include <iostream>

using namespace std;

int dp[2][100001];
int scores[2][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    int n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 2; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                cin >> scores[i][j];
            }
        }

        dp[0][1] = scores[0][1];
        dp[1][1] = scores[1][1];

        for (int i = 2; i < n + 1; ++i) {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + scores[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + scores[1][i];
        }

        cout << max(dp[0][n], dp[1][n]) << '\n';
    }
}