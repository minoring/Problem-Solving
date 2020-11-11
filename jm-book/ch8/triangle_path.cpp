#include <cstring>
#include <iostream>

using namespace std;

int triangle[100][100];
int cache[100][100];

int path(int y, int x, const int n) {
    if (y == n - 1) {
        return triangle[y][x];
    }
    int &ret = cache[y][x];
    if (ret != -1) {
        return ret;
    }

    ret = max(path(y + 1, x, n), path(y + 1, x + 1, n)) + triangle[y][x];
    return ret;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;

        memset(cache, -1, sizeof(cache));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                cin >> triangle[i][j];
            }
        }

        cout << path(0, 0, n) << '\n';
    }
}
