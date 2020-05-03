class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        for (int i = 0; i < J.length(); ++i) {
            jewels.insert(J[i]);
        }
        int answer = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (jewels.find(S[i]) != jewels.end()) {
                answer++;
            }
        }
        return answer;
    }
};