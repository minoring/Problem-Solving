/*
https://leetcode.com/problems/house-robber/
Approach: DP
Algorithm:
D[n] = max(o[n], x[n])
The maximum value of length n array is
maximum value of arrays between selecting current element or
not selecting current element.
Tip: let array size n. Not n - 1
Time Complexity: O(n). Iterate array length of n.
Space Complexity: O(n) as we have length n array for memorization.
*/
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        vector<int> o(n);
        vector<int> x(n);
        
        o[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            o[i] = x[i - 1] + nums[i];
            x[i] = max(o[i - 1], x[i - 1]);
        }
        return max(o[n - 1], x[n - 1]);
    }
};