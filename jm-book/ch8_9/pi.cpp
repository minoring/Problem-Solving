#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int cache[10000];

int max_score = 987654321;

int level(const string &s) {
    if (s == string(s.length(), s[0])) {
        return 1;
    }

    bool prog = true;
    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] - s[i + 1] != s[0] - s[1]) {
            prog = false;
        }
    }
    if (prog && abs(s[0] - s[1]) == 1) {
        return 2;
    }

    bool alt = true;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != s[i % 2]) {
            alt = false;
        }
    }

    if (alt) {
        return 4;
    }
    if (prog) {
        return 5;
    }

    return 10;
}

int solve(int i, const string &s) {
    if (i == s.length()) {
        return 0;
    }
    int &ret = cache[i];
    if (ret != -1) {
        return ret;
    }

    ret = max_score;
    for (int l = 3; l <= 5; ++l) {
        if (i + l <= s.length()) {
            ret = min(ret, solve(i + l, s) + level(s.substr(i, l)));
        }
    }
    return ret;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        memset(cache, -1, sizeof(cache));
        string s;
        cin >> s;
        cout << solve(0, s) << '\n';
    }
}
