#include <iostream>
#include <string>
#include <vector>

using namespace std;

int CalcRunLength(const string& s, int crop) {
    int res = 0;
    int prev_count = 0;
    string prev = "";

    for (int i = 0; i <= s.length(); i += crop) {
        string curr = s.substr(i, crop);

        if (curr == prev) {
            prev_count++;
        } else {
            res += curr.length();
            if (prev_count <= 1) {
                res += 0;
            } else if (prev_count < 10) {
                res += 1;
            } else if (prev_count < 100) {
                res += 2;
            } else if (prev_count < 1000) {
                res += 3;
            } else {
                res += 4;
            }
            prev_count = 1;
        }
        prev = curr;
    }
    return res;
}

int solution(string s) {
    int answer = 1001;
    for (int i = 1; i <= s.length() / 2 + 1; ++i) {
        int run_len = CalcRunLength(s, i);
        answer = min(answer, run_len);
    }
    return answer;
}