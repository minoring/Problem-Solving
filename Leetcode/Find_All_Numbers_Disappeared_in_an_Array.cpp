/*
Intuition: Using input array, change sign of the number that appeared.
Algorithm: Iterate through the input array and mark elements as negative
using nums[nums[i] - 1] = -nums[nums[i] - 1]. In this way all the numbers that
we have seen will be marked as negative. In the second iteration, if a value
is not marked as negative, it implies we have never seen that index before, so
just add it to the return list.
Time Complexity: O(n). as we iterate array.
Space Complexity: O(1). we does not have extra space
*/

#include <vector>
#include <cmath>

using namespace std;

class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int neg_idx = abs(nums[i]) - 1;
            if (nums[neg_idx] > 0) {
                nums[neg_idx] = -nums[neg_idx];
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};