#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getNumsOps(const string &s, vector<int> &nums, vector<char> &ops) {
    int i = 0;
    int num = 0;
    while (i < s.length()) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + s[i] - '0';
        } else {
            nums.push_back(num);
            ops.push_back(s[i]);
            num = 0;
        }
        ++i;
    }
    nums.push_back(num);
}

int main() {
    string s;
    cin >> s;

    vector<int> nums;
    vector<char> ops;
    getNumsOps(s, nums, ops);

    int answer = nums[0];

    int i = 0;
    while (i < ops.size()) {
        int currNum = nums[i + 1];
        int j = i + 1;
        while (j < ops.size() && ops[j] == '+') {
            currNum += nums[j + 1];
            ++j;
        }
        if (ops[i] == '-') {
            currNum = -currNum;
        }
        i = j;
        answer += currNum;
    }
    cout << answer << '\n';
}
