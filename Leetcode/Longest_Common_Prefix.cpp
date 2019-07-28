#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string shortest_str = shortestLenStr(strs);
        string res = "";

        for (int i = 0; i < shortest_str.length(); ++i) {
            int j = 0;
            for (; j < strs.size(); ++j) {
                if (shortest_str[i] != strs[j][i]) {
                    break;
                }
            }
            if (j != strs.size()) {
                break;
            }
            res = res + shortest_str[i];
        }

        return res;
    }

    string shortestLenStr(const vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string shortest_str = strs[0];

        for (string str : strs) {
            if (str.length() < shortest_str.length()) {
                shortest_str = str;
            }
        }
        return shortest_str;
    }
};