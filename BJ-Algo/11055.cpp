/*
Approach: LIS, DP
Idea: 이중 어떤놈은 최대일것이다.
모든놈이 최대일때 다해보면 검색 다해본거다.
DP로 기록해둬서 검색 빠르게.

Time Complexity: O(n^2)
Space Complexity: O(n)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int dp[1000] = {0, };
    int nums[1000];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    dp[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
               dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += nums[i];
    }

    cout << *(max_element(dp, dp + n)) << '\n';
}