// Dutch national flag problem. 3-way patition problem.
class Solution {
public:
  void sortColors(vector<int> &nums) {
    int mid = 1;
    int i = 0;
    int j = 0;
    int k = nums.size() - 1;

    while (k >= j) {
      if (nums[j] == mid) {
        j++;
      } else if (nums[j] < mid) {
        swap(nums[i], nums[j]);
        i++;
        j++;
      } else {
        swap(nums[k], nums[j]);
        k--;
      }
    }
  }
};
