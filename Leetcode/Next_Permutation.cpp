#include <vector>
#include <algorithm>

using namespace std;

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        for (; i > 0; --i) {
            if (nums[i - 1] < nums[i]) {
                break;
            }
        }

        if (i != 0) {
            for (int j = i; j <= nums.size(); ++j) {
                if (j == nums.size() || nums[i - 1] >= nums[j]) {
                    swap(nums[j - 1], nums[i - 1]);
                    break;
                }
            }
        }

        int l = i;
        int r = nums.size() - 1;
        while (l <= r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};