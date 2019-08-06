#include <vector>

using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int res = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum = nums[i] + ((sum > 0) ? sum : 0);
            res = max(res, sum);
        }

        return res;
    }
};