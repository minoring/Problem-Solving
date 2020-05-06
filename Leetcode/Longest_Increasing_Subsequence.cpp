class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        vector<int> dp(n);

        int answer = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i]++;
            answer = max(answer, dp[i]);
        }
        return answer;
    }
};