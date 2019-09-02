#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        for (int i = 1; i <= num; ++i) {
            res[i] = res[i >> 1] + (i & 1);        
        } 
        return res;
    }
};

// Counting Bits
// https://leetcode.com/problems/counting-bits/
// Apporach: Dynamic Programming
// Key: Let d[n] == the number of bits of n.
// d[n] = # bits except for last bits + last bit = d[n % 2] + last bit