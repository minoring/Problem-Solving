class Solution {
public:
    bool checkValidString(string s) {
        return helper(0, s, 0);
    }
    bool helper(int idx, const string& s, int num_open) {
        if (idx >= s.length()) {
            if (num_open == 0) {
                return true;
            }
            return false;
        }

        if (s[idx] == '(') {
            return helper(idx + 1, s, num_open + 1);
        } else if (s[idx] == ')') {
            if (num_open == 0) {
                return false;
            }
            return helper(idx + 1, s, num_open - 1);
        } else {
            bool res = helper(idx + 1, s, num_open + 1) || helper(idx + 1, s, num_open);
            if (num_open > 0) {
                res = res || helper(idx + 1, s, num_open - 1);
            }
            return res;
        }
    }
};