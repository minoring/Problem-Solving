class Solution {
public:
    void FindPos(string s, int *p) {
        int num_back = 0;
        while (*p >= 0) {
            if (s[*p] != '#' && num_back == 0) {
                return;
            }
            if (s[*p] >= 0) {
                if (s[*p] == '#')
                    num_back++;
                else
                    num_back--;
            }
            (*p)--;
        }
    }
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1;
        int j = T.length() - 1;

        while (i >= 0 || j >= 0) {
            FindPos(S, &i);
            FindPos(T, &j);
            if (i < 0 || j < 0) {
                if (i < 0 && j < 0) {
                    return true;
                }
                return false;
            }
            if (S[i] != T[j]) {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
};