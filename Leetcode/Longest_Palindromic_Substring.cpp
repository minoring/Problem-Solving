#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int palin_len(const string& s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }

    string longestPalindrome(string s) {
        if (s == "") return "";

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); ++i) {
            int len1 = palin_len(s, i, i + 1);
            int len2 = palin_len(s, i, i);

            int len = max(len1, len2);
            if (len > end - start + 1) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome(string("abad")) << '\n';
}