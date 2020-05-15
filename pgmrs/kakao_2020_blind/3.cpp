#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Rotate90(const vector<vector<int>>& key);
bool CheckAnswer(const vector<vector<int>>& key, vector<vector<int>> temp,
                 int i, int j);

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size();
    int n = lock.size();

    int padded_size = n + (m - 1) + (m - 1);
    vector<vector<int>> padded_lock(padded_size, vector<int>(padded_size));

    int lock_start = m - 1;
    for (int i = lock_start; i < lock_start + n; ++i) {
        for (int j = lock_start; j < lock_start + n; ++j) {
            padded_lock[i][j] = lock[i - lock_start][j - lock_start];
        }
    }

    for (int i = 0; i < n + m - 1; ++i) {
        for (int j = 0; j < n + m - 1; ++j) {
            for (int k = 0; k < 4; ++k) {
                key = Rotate90(key);
                if (CheckAnswer(key, padded_lock, i, j)) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool CheckAnswer(const vector<vector<int>>& key, vector<vector<int>> temp,
                 int i, int j) {
    int m = key.size();

    for (int row = i; row < i + m; ++row) {
        for (int col = j; col < j + m; ++col) {
            temp[row][col] += key[row - i][col - j];
        }
    }

    for (int row = m - 1; row < temp.size() - (m - 1); ++row) {
        for (int col = m - 1; col < temp.size() - (m - 1); ++col) {
            if (temp[row][col] == 2 || temp[row][col] == 0) {
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> Rotate90(const vector<vector<int>>& key) {
    vector<vector<int>> new_key(key.size(), vector<int>(key.size()));

    for (int i = 0; i < key.size(); ++i) {
        for (int j = 0; j < key.size(); ++j) {
            new_key[i][j] = key[key.size() - 1 - j][i];
        }
    }
    return new_key;
}
