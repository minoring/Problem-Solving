class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> count_pref;
        int pref_sum = 0;
        count_pref[0] = 1;

        int answer = 0;
        for (int r = 0; r < nums.size(); ++r) {
            pref_sum = pref_sum + nums[r];
            int target = pref_sum - k;
            answer += count_pref[target];
            count_pref[pref_sum]++;
        }
        return answer;
    }
};