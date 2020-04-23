/*
  index 가 필요한지 안필요한지.
*/
class Solution {
public:
    int countElements(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int cnt = 0;
        int prev = -1;
        int curr_count = 0;
        for (int x : arr) {
            if (x == prev) {
                curr_count++;
            } else {
                if (x == prev + 1) {
                    cnt += curr_count;
                }
                curr_count = 1;
                prev = x;
            }
        }
        return cnt;
    }
};