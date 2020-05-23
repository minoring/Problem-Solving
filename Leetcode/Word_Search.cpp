class Solution {
  public:
    bool exist(vector<vector<char>> &board, string word) {
        vector<vector<bool>> visited;
        for (int i = 0; i < board.size(); ++i) {
            visited.push_back(vector<bool>(board[i].size()));
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(word, 0, i, j, visited, board)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    const int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    bool dfs(const string &word, int idx, int r, int c,
             vector<vector<bool>> &visited, const vector<vector<char>> &board) {
        if (idx >= word.length()) {
            return true;
        }
        if (r < 0 || r >= board.size() || c < 0 || c >= board[r].size()) {
            return false;
        }
        if (visited[r][c]) {
            return false;
        }

        if (word[idx] == board[r][c]) {
            for (int i = 0; i < 4; ++i) {
                visited[r][c] = true;
                int new_r = r + dir[i][0];
                int new_c = c + dir[i][1];
                if (dfs(word, idx + 1, new_r, new_c, visited, board)) {
                    return true;
                }
                visited[r][c] = false;
            }
        }

        return false;
    }
};
