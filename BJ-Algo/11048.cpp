#include <algorithm>
#include <iostream>

int main() {
    const int MAX_SIZE = 1000;
    int map[MAX_SIZE + 1][MAX_SIZE + 1];
    int dp[MAX_SIZE + 1][MAX_SIZE + 1] = {};

    const int NUM_DIR = 3;
    int dx[NUM_DIR] = {-1, -1, 0};
    int dy[NUM_DIR] = {0, -1, -1};

    int num_row;
    int num_col;
    std::cin >> num_row >> num_col;
    for (int i = 1; i <= num_row; ++i) {
        for (int j = 1; j <= num_col; ++j) {
            std::cin >> map[i][j];
        }
    }

    for (int i = 1; i <= num_row; ++i) {
        for (int j = 1; j <= num_col; ++j) {
            for (int k = 0; k < NUM_DIR; ++k) {
                dp[i][j] = std::max(dp[i][j], dp[i + dx[k]][j + dy[k]]);
            }
            dp[i][j] += map[i][j];
        }
    }

    std::cout << dp[num_row][num_col] << '\n';
}