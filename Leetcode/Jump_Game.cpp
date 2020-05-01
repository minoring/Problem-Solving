class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1) {
      return true;
    }
    pair<int, int> interval{0, 0};
    while (true) {
      int can_reach = -1;
      for (int i = interval.first; i <= interval.second; ++i) {
        can_reach = max(can_reach, nums[i] + i);
      }
      if (can_reach >= n - 1) {
        return true;
      }
      interval = {interval.second + 1, can_reach};
      if (interval.first > interval.second) {
        return false;
      }
    }
  }
};