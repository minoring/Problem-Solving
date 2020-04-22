/*
https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3287/
중요한거: 현재 위치에서 뭐가 중요한지.
현재 날짜의 최대이윤 과 주식을 가지고 있냐 가지고 있지 않냐 중요.
[i][2] 2는 2개의 상태
[i][k] k는 k의 상태.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit_without = 0;
        int max_profit_with = INT_MIN;

        for (int x : prices) {
            max_profit_with = max(max_profit_with, max_profit_without - x);
            max_profit_without = max(max_profit_without, max_profit_with + x);
        }
        return max_profit_without;
    }
};