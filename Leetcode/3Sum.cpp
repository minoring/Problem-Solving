#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                if (nums[i] + nums[l] + nums[r] == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l - 1] == nums[l]) {
                        l++;
                    }
                    while (r > l && nums[r + 1] == nums[r]) {
                        r--;
                    }
                } else if (nums[i] + nums[l] + nums[r] < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    // vector<int> nums{0, 0, 0, 0, 1, -1};
    // vector<int> nums{0, 3, -3};
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = sol.threeSum(nums);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}