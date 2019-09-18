/* 
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * Approach: Binary Search
 * Time Complexity: O(logn)
 * Space Complexity: O(1)
 *
 * */
#include <vector>

using namespace std;

class Solution {
public:
    int searchRangeHelper(vector<int>& nums, int target, bool is_left) {
        int lo = 0;
        int hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target || (is_left && nums[mid] == target)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int left_idx = searchRangeHelper(nums, target, true);
        if (left_idx == nums.size() || nums[left_idx] != target) {
            return res;
        }
        res[0] = left_idx;
        res[1] = searchRangeHelper(nums, target, false) - 1;
        return res;
    }
};
