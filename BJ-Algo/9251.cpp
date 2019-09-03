#include <iostream>

using namespace std;

int main() {
    string s1;
    string s2;

    cin >> s1 >> s2;
    int m = s1.length();
    int n = s2.length();

    int lcs[1001][1001] = {
        0,
    };
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            } else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    cout << lcs[m][n] << '\n';
}

// LCS
// https://www.acmicpc.net/problem/9251
// Approach: DP
// DP를 풀땐 항상 Sub problem을 생각하자.
// 손으로 풀수있으면 코드는 필요없지. 손으로 설명.