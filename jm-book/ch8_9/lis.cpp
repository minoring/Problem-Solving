#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int lis(int start, const vector<int> &nums, vector<int> &dp) {
    int &ret = dp[start];
    if (ret != -1) {
        return ret;
    }
    ret = 1;
    for (int i = start + 1; i < nums.size(); ++i) {
        if (nums[start] < nums[i]) {
            ret = max(ret, lis(i, nums, dp) + 1);
        }
    }
    return ret;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;

        vector<int> nums(n);
        vector<int> dp(n, -1);

        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, lis(i, nums, dp));
        }
        cout << ans << '\n';
    }
}
