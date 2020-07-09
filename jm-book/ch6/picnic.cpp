#include <iostream>

using namespace std;

int countPairings(int n, bool taken[], bool areFriends[][10]) {
    int firstFree = -1;
    for (int i = 0; i < n; ++i) {
        if (!taken[i]) {
            firstFree = i;
            break;
        }
    }

    if (firstFree == -1) {
        return 1;
    }

    int ans = 0;
    for (int i = firstFree + 1; i < n; ++i) {
        if (!taken[i] && areFriends[firstFree][i]) {
            taken[firstFree] = true;
            taken[i] = true;
            ans += countPairings(n, taken, areFriends);
            taken[firstFree] = false;
            taken[i] = false;
        }
    }

    return ans;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        int m;
        cin >> n >> m;

        bool areFriends[10][10] = {
            false,
        };

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            areFriends[a][b] = true;
            areFriends[b][a] = true;
        }

        bool taken[10] = {
            false,
        };
        cout << countPairings(n, taken, areFriends) << '\n';
    }
}
