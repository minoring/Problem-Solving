#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> num_map;

        for (int i = 0; i < nums.size(); ++i) {
            if (num_map.find(nums[i]) == num_map.end()) {
                num_map.insert(pair<int, int>(target - nums[i], i));
            } else {
                res.push_back(num_map[nums[i]]);
                res.push_back(i);
                break;
            }
        }

        return res;
    }
};