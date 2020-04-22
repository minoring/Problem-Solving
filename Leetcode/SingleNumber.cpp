/*
https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3283/
1. XOR of a number with itself is 0
2. XOR of a number with 0 is the number it self
3. XOR is commutative so the order of numbers does not matter
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int x = 0;
        for (int a : nums) {
            x ^= a;
        }
        return x;
    }
};