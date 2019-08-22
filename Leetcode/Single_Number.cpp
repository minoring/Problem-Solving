#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            res ^= num; 
        }
        return res;
    }
};

/*
https://leetcode.com/problems/single-number/
Approach: Bit Manipulation
a⊕0 = a If we take xor of zero and some bit, it will return that bit
a⊕a = 0 If we take XOR of two same bits, it will return 0
a⊕b⊕a = (a⊕a)⊕b = 0⊕b = b associative rule.

So we cam XOR all bits together to find the unique number.

Complexity Analysis
Time complexity: O(n). We only iterate through nums, so the time
complexity is the number of elements in nums.
Space Complexity: O(1)
*/
