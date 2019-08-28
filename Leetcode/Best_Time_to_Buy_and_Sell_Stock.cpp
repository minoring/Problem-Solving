class Solution {
public:
    int maxProfit(vector<int>& prices) {        
        if (prices.empty()) {
            return 0;
        }
        
        int res = 0;
        int cur_max = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; --i) {
            cur_max = max(cur_max, prices[i]);
            res = max(res, cur_max - prices[i]);
        }
        return res;
    }
};
/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Approach: Loop backward.
Time Complexity: O(n)
Memory Complexity: O(1)
*/