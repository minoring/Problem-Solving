#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int cache[101][11];
const int INF = 987654321;

int sum_squared_error(int m, int lo, int hi, const vector<int> &nums) {
    int sum = 0;

    for (int i = lo; i <= hi; ++i) {
        sum += (nums[i] - m) * (nums[i] - m);
    }

    return sum;
}

int min_error(int lo, int hi, const vector<int> &nums) {
    int ans = INF;

    for (int num = nums[lo]; num <= nums[hi]; ++num) {
        ans = min(ans, sum_squared_error(num, lo, hi, nums));
    }

    return ans;
}

int quantize(int from, int parts, const vector<int> &nums) {
    int n = nums.size();
    if (from >= n) {
        return 0;
    }

    if (parts == 0) {
        return INF;
    }

    int &ret = cache[from][parts];
    if (ret != -1) {
        return ret;
    }

    ret = INF;
    for (int size = 1; size <= n - from; ++size) {
        ret = min(ret, quantize(from + size, parts - 1, nums) +
                           min_error(from, from + size - 1, nums));
    }

    return ret;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        memset(cache, -1, sizeof(cache));

        int n;
        cin >> n;
        int s;
        cin >> s;

        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());

        cout << quantize(0, s, nums) << '\n';
    }
}
