#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        gen_paren("(", 1, 0);
        return res;
    }

    void gen_paren(string cur, int num_opened, int num_closed) {
        if (num_opened == n && num_closed == n) {
            res.push_back(cur);
            return;
        }

        if (num_opened < n) {
            gen_paren(cur + "(", num_opened + 1, num_closed);
        }
        if (num_closed < num_opened) {
            gen_paren(cur + ")", num_opened, num_closed + 1);
        }
    }
    vector<string> res;
    int n;
};

int main() {
    Solution sol;
    sol.generateParenthesis(3);
}