class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int answer = INT_MIN;
        const int n = nums.size();
        vector<int> pref_sum(n);
        for (int i = 0; i < n; ++i) {
            pref_sum[i] = nums[i] + ((i == 0) ? 0 : pref_sum[i - 1]);
        }
        int min_sub = 0;

        for (int i = 0; i < n; ++i) {
            answer = max(answer, pref_sum[i] - min_sub);
            min_sub = min(min_sub, pref_sum[i]);
        }
        return answer;
    }
};