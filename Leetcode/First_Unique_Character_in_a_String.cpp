class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> first_unique;
        int seen_count[27] = {0, };
        for (int i = 0; i < s.length(); ++i) {
            seen_count[s[i] - 'a']++;
            if (seen_count[s[i] - 'a'] == 1) {
                first_unique.push(i);
            }
        }

        while (!first_unique.empty()) {
            int first_idx = first_unique.front();
            first_unique.pop();
            if (seen_count[s[first_idx] - 'a'] == 1) {
                return first_idx;
            }
        }
        return -1;
    }
};