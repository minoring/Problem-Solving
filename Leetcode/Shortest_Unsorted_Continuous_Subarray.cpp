class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());

    int lo = 0;
    int hi = temp.size() - 1;
    while (lo < temp.size() && temp[lo] == nums[lo]) {
      lo++;
    }
    while (hi > 0 && temp[hi] == nums[hi]) {
      hi--;
    }
    if (hi > lo) {
      return hi - lo + 1;
    }
    return 0;
  }
};
