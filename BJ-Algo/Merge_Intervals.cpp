/*
Sort는 앞서는거 정해줌.
Strict week order. 자신은 자신보다 앞서지 않음.
앞서는 것만 strict하게 정의.
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals[0].empty()) {
            return vector<vector<int>>();
        }
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });
        vector<vector<int>> answer;
        answer.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            int& last_end = answer.back()[1];
            if (intervals[i][0] <= last_end) {
                last_end = max(last_end, intervals[i][1]);
            } else {
                answer.push_back(intervals[i]);
            }
        }
        return answer;
    }
};