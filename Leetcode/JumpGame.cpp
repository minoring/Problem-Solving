#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> can_jump(nums.size(), 0);
        can_jump[0] = 1;
        
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (can_jump[j] && i - j <= nums[j]) {
                    can_jump[i] = 1;
                    break;
                }
            }
        }
        return can_jump[nums.size() - 1];
    }
};