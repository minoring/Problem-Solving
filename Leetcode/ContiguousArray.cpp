/*
왜 0은 특별했을까?
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int sum = 0;
        int answer = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] == 0) ? 1 : -1;

            if (sum == 0) {
                answer = i + 1;
            } else if (m.count(sum) == 1) {
                answer = max(answer, i - m[sum]);
            } else {
                m[sum] = i;
            }
        }
        return answer;
    }
};