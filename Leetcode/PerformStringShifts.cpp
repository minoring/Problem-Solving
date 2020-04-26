class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int curr = 0;
        for (int i = 0; i < shift.size(); ++i) {
            if (shift[i][0] == 0) {
                curr += shift[i][1];
            } else {
                curr -= shift[i][1];
            }
            if (curr < 0) {
                curr = s.length() + curr;
            }
            curr = curr % s.length();
        }

        string answer;
        int i = curr;
        do {
            answer += s[i];
            i++;
            if (i == s.length()) {
                i = 0;
            }
        } while (i != curr);
        return answer;
    }
};