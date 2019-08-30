#include <stdio.h>
#include <string.h>

#define max(a, b)               \
    ({                          \
        __typeof__(a) _a = (a); \
        __typeof__(b) _b = (b); \
        _a > _b ? _a : _b;      \
    })

int heights[100][100];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int temp[][100], int i, int j, int n) {
    if (i < 0 || i >= n || j < 0 || j >= n) {
        return;
    }
    if (temp[i][j] == 0) {
        return;
    }
    temp[i][j] = 0;
    for (int k = 0; k < 4; ++k) {
        dfs(temp, i + dx[k], j + dy[k], n);
    }
}

int find_safe(const int heights[][100], int height, int n) {
    int temp[100][100];
    memcpy(temp, heights, sizeof(int) * 100 * 100);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            temp[i][j] = (temp[i][j] <= height) ? 0 : temp[i][j];
        }
    }

    int safezone = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (temp[i][j] != 0) {
                safezone += 1;
                dfs(temp, i, j, n);
            }
        }
    }
    return safezone;
}

int main() {
    int n;
    scanf("%d", &n);

    int max_height = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &heights[i][j]);
            max_height = max(heights[i][j], max_height);
        }
    }

    int res = 1;
    for (int height = 1; height < max_height; ++height) {
        int safezone = find_safe(heights, height, n);
        res = max(res, safezone);
    }

    printf("%d\n", res);
}

/* 백준 안전영역
https://www.acmicpc.net/problem/2468
Approach: try every height, DFS
when copying two-dimension array, copy whole array. 
(gives me a bug when copying n size)
use dx, dy to indicate location to visit.
visit->early return produce more clean code than if->visit in DFS.
C does not have max fun!
*/
