#include <iostream>
#include <string>
#include <vector>

using namespace std;

char dial[10][5] = {
    {},
    {},
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'},
};

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return vector<string>();
        }
        vector<string> res;
        comb("", digits, &res);
        return res;
    }
    void comb(const string& combStr, const string& digit, vector<string>* res) {
        if (digit == "") {
            res->push_back(combStr);
            return;
        }

        for (int i = 0; i < 3; ++i) {
            comb(combStr + dial[digit[0] - '0'][i],
                 digit.substr(1, digit.size() - 1), res);
        }
        if (digit[0] == '7' || digit[0] == '9') {
            comb(combStr + dial[digit[0] - '0'][3],
                 digit.substr(1, digit.size() - 1), res);
        }
    }
};

int main() {
    Solution sol;
    vector<string> res = sol.letterCombinations("23");
    for (auto s : res) {
        cout << s << ' ';
    }
}