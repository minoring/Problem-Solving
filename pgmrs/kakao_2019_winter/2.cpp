#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

void ToCanonical(vector<vector<int>>& nums, const string& s) {
    for (int i = 1; i < s.length() - 1; ++i) {
		if (s[i] == '{' || s[i] == ',' || s[i] == '}') {
            continue;
        }
        vector<int> curr_nums;
        int num = 0;
        while (s[i] != '}') {
            if (s[i] == ',') {
                curr_nums.push_back(num);
                num = 0;
            } else {
                num = num * 10 + (s[i] - '0');
            }
            i++;
        }
        curr_nums.push_back(num);
        nums.push_back(curr_nums);
    }
}

vector<int> solution(string s) {
    vector<int> answer;

    vector<vector<int>> nums;
	ToCanonical(nums, s);


    sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) {
        return a.size() < b.size();
    });

   	unordered_set<int> seen;

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums[i].size(); ++j) {
            if (seen.find(nums[i][j]) == seen.end()) {
                seen.insert(nums[i][j]);
                answer.push_back(nums[i][j]);
            }
        }
    }

    return answer;
}