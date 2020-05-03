class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> char_count;
        for (char s : magazine) {
            char_count[s]++;
        }
        for (char s : ransomNote) {
            if (char_count[s] == 0) {
                return false;
            } else {
                char_count[s]--;
            }
        }
        return true;
    }
};