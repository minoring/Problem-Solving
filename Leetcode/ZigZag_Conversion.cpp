#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string res = "";
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; i + j < s.length(); j += (numRows - 1) * 2) {
                res += s[i + j];
                if (i != 0 && i != numRows - 1) {
                    if (i + j + (numRows - i - 1) * 2 < s.length()) {
                        res += s[i + j + (numRows - i - 1) * 2];
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.convert("PAYPALISHIRING", 2) << '\n';
}