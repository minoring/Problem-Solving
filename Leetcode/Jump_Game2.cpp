class Solution {
public:
    bool canJump(vector<int>& nums) {
      int can_reach = 0;
      int n = nums.size();
      for (int i = 0; i <= can_reach; ++i) {
        if (i == n - 1) {
          return true;
        }
        can_reach = max(can_reach, nums[i] + i);
      }
      return false;
    }
};