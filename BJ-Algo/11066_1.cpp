/*
문제: https://www.acmicpc.net/problem/11066
풀이: http://melonicedlatte.com/algorithm/2018/03/22/051337.html
Intuition:
dp[a][b]는 구간 a에서 b까지의 최소합.
key: 이차원 배열 table로만 생각했는데, 구간으로 표현한다는게 신기했다.
*/
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int dp[501][501];
int acc_sum[501];
int cost[501];

int solve(int lo, int hi) {
    if (dp[lo][hi] != 0x3F3F3F3F) {
        return dp[lo][hi];
    }
    if (lo == hi) {
        dp[lo][hi] = 0;
        return 0;
    }
    if (lo + 1 == hi) {
        dp[lo][hi] = cost[lo] + cost[hi];
        return dp[lo][hi];
    }

    for (int i = lo; i < hi; ++i) {
        dp[lo][hi] = min(dp[lo][hi], solve(lo, i) + solve(i + 1, hi));
    }
    return dp[lo][hi] += acc_sum[hi] - acc_sum[lo - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        memset(dp, 0x3F, sizeof(dp));
        int k;
        cin >> k;
        for (int i = 1; i <= k; ++i) {
            cin >> cost[i];
            acc_sum[i] = acc_sum[i - 1] + cost[i];
        }

        cout << solve(1, k) << '\n';
    }
}