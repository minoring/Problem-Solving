/*
https://leetcode.com/problems/majority-element/
Approach: Hash Map
Algorithm:
Maps elements count occurences in linear time by looping over nums.
Then, we simply return the key with maximum value.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> num_counter;
        int res;
        for (int num : nums) {
            if (num_counter.find(num) == num_counter.end()) {
                num_counter[num] = 1;
            } else {
                num_counter[num] += 1;
            }
            if (num_counter[num] > nums.size() / 2) {
                res = num; 
                break;
            }
        }
        return res;
    }
};