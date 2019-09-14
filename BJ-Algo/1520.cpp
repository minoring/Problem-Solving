/*
https://www.acmicpc.net/problem/1520
BFS로 푸니까 시간초과남
DFS로 모든 경로를 구해놓으면, DP로 값만 뽑으면 되니까 괜춘
dp의 값이 0인게 이미 방문했는데 길이 없는걸수도 있는데, 방문 안한줄 알고 다시
찾아서 시간 초과남. 방문 안한건 -1로 초기화 해주고, 방문하면 0으로 바꿔서
더해주자.
*/
#include <cstring>
#include <iostream>

using namespace std;

int m;
int n;
int map[501][501];
int dp[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int row, int col) {
    if (row == m && col == n) {
        return 1;
    }
    if (dp[row][col] != -1) {
        return dp[row][col];
    }
    dp[row][col] = 0;
    for (int i = 0; i < 4; ++i) {
        int new_row = row + dx[i];
        int new_col = col + dy[i];
        if (new_row >= 1 && new_row <= m && new_col >= 1 && new_col <= n &&
            map[new_row][new_col] < map[row][col]) {
            dp[row][col] += dfs(new_row, new_col);
        }
    }
    return dp[row][col];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    dfs(1, 1);
    cout << dp[1][1] << '\n';
}