#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;

        unordered_set<char> found_set;
        found_set.clear();

        int i = 0;
        int j = 0;
        while (i < s.length() && j < s.length()) {
            if (found_set.find(s[j]) == found_set.end()) {
                found_set.insert(s[j]);
                max_len = max(max_len, abs(j - i + 1));
                j++;
            } else {
                found_set.erase(s[i]);
                i++;
            }
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("pwekp");
}