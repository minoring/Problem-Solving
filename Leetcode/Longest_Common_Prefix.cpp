#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";

        string prefix = strs[0];
        for (const string& str : strs) {
            int  i = 0;
            for (; i < min(prefix.length(), str.length()); ++i) {
                if (prefix[i] != str[i]) {
                    break;
                }
            }
            prefix = prefix.substr(0, i);
        }
        return prefix;
    }
};