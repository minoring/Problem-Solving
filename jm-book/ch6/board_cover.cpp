#include <iostream>
#include <vector>

using namespace std;

const int coverDir[4][3][2] = {{{0, 0}, {0, 1}, {1, 0}},
                               {{0, 0}, {0, 1}, {1, 1}},
                               {{0, 0}, {1, 0}, {1, 1}},
                               {{0, 0}, {1, 0}, {1, -1}}};

void printBoard(const vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

bool canCover(const vector<vector<char>> &board, int dir, int y, int x) {
    for (int j = 0; j < 3; ++j) {
        int newY = y + coverDir[dir][j][0];
        int newX = x + coverDir[dir][j][1];

        if (newY < 0 || newX < 0 || newY >= board.size() ||
            newX >= board[0].size() || board[newY][newX] == '#') {
            return false;
        }
    }
    return true;
}

void cover(vector<vector<char>> &board, int dir, int y, int x) {
    for (int i = 0; i < 3; ++i) {
        board[y + coverDir[dir][i][0]][x + coverDir[dir][i][1]] = '#';
    }
}

void unCover(vector<vector<char>> &board, int dir, int y, int x) {
    for (int i = 0; i < 3; ++i) {
        board[y + coverDir[dir][i][0]][x + coverDir[dir][i][1]] = '.';
    }
}

int numCover(vector<vector<char>> &board) {
    int y = -1;
    int x = -1;
    bool found = false;
    for (int i = 0; i < board.size(); ++i) {
        if (found) {
            break;
        }
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[i][j] == '.') {
                y = i;
                x = j;
                found = true;
                break;
            }
        }
    }
    if (y == -1) {
        return 1;
    }

    int answer = 0;
    for (int dir = 0; dir < 4; ++dir) {
        if (canCover(board, dir, y, x)) {
            cover(board, dir, y, x);
            answer += numCover(board);
            unCover(board, dir, y, x);
        }
    }
    return answer;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int h;
        int w;

        cin >> h >> w;
        vector<vector<char>> board(h, vector<char>(w));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> board[i][j];
            }
        }

        cout << numCover(board) << '\n';
    }
}
