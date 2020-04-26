class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        int count_zeros = 0;
        int prod_all = 1;
        int prod_without_zero = 1;
        for (int x : nums) {
            if (x == 0) {
                count_zeros++;
            } else {
                prod_without_zero *= x;
            }
            prod_all *= x;
        }
        vector<int> answer(n);
        if (count_zeros >= 2) {
            return answer;
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                answer[i] = prod_without_zero;
            } else {
                answer[i] = prod_all / nums[i];
            }
        }
        return answer;
    }
};