#include <iostream>
#include <vector>

using namespace std;

int solve(const vector<int> &fences, int left, int right) {
    if (left == right) {
        return fences[left];
    }

    int mid = (left + right) / 2;
    int ans = max(solve(fences, left, mid), solve(fences, mid + 1, right));

    int lo = mid;
    int hi = mid + 1;
    int min_height = min(fences[lo], fences[hi]);
    ans = max(ans, min_height * 2);

    while (left < lo || hi < right) {
        if (hi < right && (lo == left || fences[lo - 1] <= fences[hi + 1])) {
            hi++;
            min_height = min(min_height, fences[hi]);
        } else {
            lo--;
            min_height = min(min_height, fences[lo]);
        }
        ans = max(ans, (hi - lo + 1) * min_height);
    }

    return ans;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;

        vector<int> fences(n);
        for (int i = 0; i < n; ++i) {
            cin >> fences[i];
        }

        cout << solve(fences, 0, n - 1) << '\n';
    }
}
