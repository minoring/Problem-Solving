#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cache[101][101];
string W;
string S;

int match(int w, int s) {
    int &ret = cache[w][s];
    if (ret != -1) {
        return ret;
    }

    if (w < W.length() && s < S.length() && (W[w] == '?' || W[w] == S[s])) {
        return ret = match(w + 1, s + 1);
    }

    if (w == W.length() && s == S.length()) {
        return ret = 1;
    }

    if (W[w] == '*') {
        if (match(w + 1, s) || (s < S.size() && match(w, s + 1))) {
            return ret = 1;
        }
    }
    return ret = 0;
}

int main() {
    int c;
    cin >> c;

    while (c--) {
        cin >> W;
        int n;
        cin >> n;

        vector<string> matched_names;
        for (int i = 0; i < n; ++i) {
            memset(cache, -1, sizeof(cache));
            cin >> S;
            if (match(0, 0) == 1) {
                matched_names.push_back(S);
            }
        }
        sort(matched_names.begin(), matched_names.end());

        for (int i = 0; i < matched_names.size(); ++i) {
            cout << matched_names[i] << '\n';
        }
    }
}
