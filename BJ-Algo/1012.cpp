#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void BFS(vector<vector<bool>> &grid, queue<pair<int, int>> &que) {
    int M = grid.size();
    int N = grid[0].size();

    while (!que.empty()) {
        pair<int, int> curr = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int newRow = curr.first + dir[i][0];
            int newCol = curr.second + dir[i][1];
            if (newRow >= 0 && newCol >= 0 && newRow < M && newCol < N &&
                grid[newRow][newCol] == true) {
                grid[newRow][newCol] = false;
                que.push({newRow, newCol});
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;
        vector<vector<bool>> grid(M, vector<bool>(N));

        for (int i = 0; i < K; ++i) {
            int row, col;
            cin >> row >> col;
            grid[row][col] = true;
        }

        int answer = 0;
        queue<pair<int, int>> que;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == true) {
                    answer++;
                    grid[i][j] = false;
                    que.push({i, j});
                    BFS(grid, que);
                }
            }
        }
        cout << answer << '\n';
    }
}
