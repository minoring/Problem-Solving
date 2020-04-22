/*
https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3286/
Two pointer.
Move none zeros forward, rest fill zeros.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nxt = 0;
        for (int x : nums) {
            if (x != 0) {
                nums[nxt] = x;
                nxt++;
            }
        }
        for (int i = nxt; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};