#include <iostream>
#include <vector>

using namespace std;

int dfs(const vector<int> &nums, int sum, int s, int idx) {
    if (idx == nums.size()) {
        return 0;
    }

    return ((sum + nums[idx] == s) ? 1 : 0) +
           dfs(nums, sum + nums[idx], s, idx + 1) + dfs(nums, sum, s, idx + 1);
}

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << dfs(nums, 0, s, 0) << '\n';
}
