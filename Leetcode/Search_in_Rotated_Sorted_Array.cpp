/*
Binary tree is about true false
*/
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        int rot = lo;

        return max(binary_search(nums, target, 0, rot - 1),
                   binary_search(nums, target, rot, nums.size() - 1));
    }

    int binary_search(vector<int>& nums, int target, int lo, int hi) {
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return - 1;
    }
};