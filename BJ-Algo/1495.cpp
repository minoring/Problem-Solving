#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    bool d[101][1001] = {
        false,
    };
    int n, s, m;
    cin >> n >> s >> m;
    d[0][s] = true;

    int v[101];
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (!d[i - 1][j]) {
                continue;
            }

            if (j + v[i] <= m) {
                d[i][j + v[i]] = true;
            }

            if (j - v[i] >= 0) {
                d[i][j - v[i]] = true;
            }
        }
    }

    int res = -1;
    for (int i = 0; i <= m; ++i) {
        if (d[n][i]) {
            res = i;
        }
    }

    cout << res << '\n';
}

/*
기타리스트
https://www.acmicpc.net/problem/1495

Approach: DP
kernel: we have to select whether +d[i] or -d[i] every step.
However, there is restrict that it has to be >=0 and <=m.
Therefore, we do not have to search every possibility which is 2^n.
Instead, we build n * m matrix which contains m value is possible in nth state.

Complexity Analysis
Time complexity: O(n*m) as we iterate through n*m matrix.
Space Complexity: O(n*m)
*/