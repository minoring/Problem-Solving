/*
가장 긴 바이토닉 부분수열
https://www.acmicpc.net/problem/11054
Approach: DP(LIS)
Algorithm:
1. Subproblem으로 나누자.
n번째 원소가 최대일때 가장 긴 증가하는 부분수열은
n-1번째까지 가장 긴 증가하는 부분수열의 max값중
그 원소의 값이 나보다 작은것 + 1.
Time Complexity: O(n^2). iterate n elements, each element search takes O(n)
Space COmplexity: O(n). Store answer n subproblem.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int inc_dp[1001];
int dec_dp[1001];
int a[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        int max_num = 0;
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i] && inc_dp[j] > max_num) {
                max_num = inc_dp[j];
            }
        }
        inc_dp[i] = max_num + 1;
    }

    for (int i = n - 1; i >= 0; --i) {
        int max_num = 0;
        for (int j = n - 1; j > i; --j) {
            if (a[j] < a[i] && dec_dp[j] > max_num) {
                max_num = dec_dp[j];
            }
        }
        dec_dp[i] = max_num + 1;
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(res, inc_dp[i] + dec_dp[i] - 1);
    }
    cout << res << '\n';
}
