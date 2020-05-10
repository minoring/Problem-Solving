#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int M;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int DFS(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int i,
        int j, int curr, int depth) {
    if (depth == 3) {
        return curr;
    }

    int answer = 0;
    for (int d = 0; d < 4; ++d) {
        int new_i = i + dir[d][0];
        int new_j = j + dir[d][1];

        if (new_i < 0 || new_j < 0 || new_i >= N || new_j >= M) {
            continue;
        }
        if (!visited[new_i][new_j]) {
            visited[new_i][new_j] = true;
            answer = max(answer, DFS(grid, visited, new_i, new_j,
                                     curr + grid[new_i][new_j], depth + 1));
            visited[new_i][new_j] = false;
        }
    }
    return answer;
}

int Mountain(const vector<vector<int>>& grid, int i, int j) {
    int answer = 0;

    if (i > 0 && j > 0 && j + 1 < M) {  // ㅗ shape
        int p = grid[i - 1][j] + grid[i][j] + grid[i][j - 1] + grid[i][j + 1];
        answer = max(answer, p);
    }
    if (i + 1 < N && j > 0 && j + 1 < M) {  // ㅜ shape
        int p = grid[i + 1][j] + grid[i][j] + grid[i][j - 1] + grid[i][j + 1];
        answer = max(answer, p);
    }
    if (j > 0 && i > 0 && i + 1 < N) {  // ㅓ shape
        int p = grid[i][j - 1] + grid[i][j] + grid[i - 1][j] + grid[i + 1][j];
        answer = max(answer, p);
    }
    if (j + 1 < M && i > 0 && i + 1 < N) {  // ㅏ shape
        int p = grid[i][j + 1] + grid[i][j] + grid[i - 1][j] + grid[i + 1][j];
        answer = max(answer, p);
    }
    return answer;
}

int main() {
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }

    int answer = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            visited[i][j] = true;
            answer = max(answer, DFS(grid, visited, i, j, grid[i][j], 0));
            visited[i][j] = false;
            answer = max(answer, Mountain(grid, i, j));
        }
    }
    cout << answer << '\n';
}
