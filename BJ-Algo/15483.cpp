#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    string b;
    cin >> a >> b;

    int n = a.length();
    int m = b.length();

    int dp[1001][1001];
    for (int i = 0; i < 1001; ++i) {
        dp[i][0] = i;
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] =
                min(dp[i][j - 1] + 1,
                    min((dp[i - 1][j - 1] + ((a[i - 1] == b[j - 1]) ? 0 : 1)),
                        dp[i - 1][j] + 1));
        }
    }
    cout << dp[n][m] << '\n';
}