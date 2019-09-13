/*
https://leetcode.com/problems/move-zeroes/
"Array Transformation". This category is the meat of tech interviews.
Approach: Fast and slow pointer
Intuition:
1. All the elements before slow pointer are non zeros.
2. All the elements between slow pointer and fast pointer are zeros.
Time Complexity: O(n). as we traverse array element once
Space Complexity: O(1). Only constant space
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int last_non_zero_found_at = 0, curr = 0;
             curr < nums.size(); ++curr) {
            if (nums[curr] != 0) {
                swap(nums[last_non_zero_found_at++], nums[curr]);
            }
        }
    }
};