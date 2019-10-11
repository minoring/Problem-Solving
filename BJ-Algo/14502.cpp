/*
늦게 푼 이유.
1. 전역번수에 있는 맵이 전염된상태로 계속 남아있어서 답이 안나왔다.
-> 새로운 맵을 만들어서 복사해서, 그맵을 감염
2. 조합을 잘 못구했다.
-> start_idx를  start_idx + 1 이 아니라, i + 1로 해줘야 한다.
*/

#include <array>
#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
const int NUM_DIR = 4;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
vector<array<pair<int, int>, 3> > empty_wall_combs;

void CopyMap(int dst[][8], int src[][8]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dst[i][j] = src[i][j];
        }
    }
}

void FindEmptyWallComb(const vector<pair<int, int> >& vacants,
                       array<pair<int, int>, 3>& curr_comb, int start_idx,
                       int depth) {
    if (depth == 3) {
        empty_wall_combs.push_back(curr_comb);
        return;
    }

    for (int i = start_idx; i < vacants.size(); ++i) {
        curr_comb[depth] = vacants[i];
        FindEmptyWallComb(vacants, curr_comb, i + 1, depth + 1);
    }
}

void SetValueAtCoords(int map[][8], array<pair<int, int>, 3> cords, int value) {
    map[cords[0].first][cords[0].second] = value;
    map[cords[1].first][cords[1].second] = value;
    map[cords[2].first][cords[2].second] = value;
}

void Infect(int row, int col, int infect_map[][8]) {
    for (int i = 0; i < NUM_DIR; ++i) {
        int new_row = row + dy[i];
        int new_col = col + dx[i];
        if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m &&
            infect_map[new_row][new_col] == 0) {
            infect_map[new_row][new_col] = 2;
            Infect(new_row, new_col, infect_map);
        }
    }
}

int CalcNumSafeArea(const int map[][8]) {
    int num_safe_area = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == 0) ++num_safe_area;
        }
    }
    return num_safe_area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;

    int grid[8][8];
    vector<pair<int, int> > vacants;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 0) {
                vacants.push_back({i, j});
            }
        }
    }

    array<pair<int, int>, 3> dummy_array;
    FindEmptyWallComb(vacants, dummy_array, 0, 0);

    int max_area = 0;
    int infect_map[8][8];
    for (auto comb : empty_wall_combs) {
        SetValueAtCoords(grid, comb, 1);
        CopyMap(infect_map, grid);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (infect_map[i][j] == 2) {
                    Infect(i, j, infect_map);
                }
            }
        }

        max_area = max(max_area, CalcNumSafeArea(infect_map));
        SetValueAtCoords(grid, comb, 0);
    }

    cout << max_area << '\n';
}