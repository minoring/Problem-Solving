#include <iostream>
#include <queue>

using namespace std;

struct Location {
    int z;
    int y;
    int x;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int box[100][100][100];
    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};
    int m, n, h;
    cin >> m >> n >> h;
    queue<Location> que;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                cin >> box[i][j][k];  // (h, n, m)
                if (box[i][j][k] == 1) {
                    que.push({i, j, k});
                }
            }
        }
    }

    int day = -1;
    while (!que.empty()) {
        size_t q_size = que.size();
        for (int i = 0; i < q_size; ++i) {
            Location cur_loc = que.front();
            que.pop();

            for (int j = 0; j < sizeof(dx) / sizeof(dx[0]); ++j) {
                int n_z = cur_loc.z + dz[j];
                int n_y = cur_loc.y + dy[j];
                int n_x = cur_loc.x + dx[j];

                if (n_z < 0 || n_z >= h || n_y < 0 || n_y >= n || n_x < 0 ||
                    n_x >= m) {
                    continue;
                }

                if (box[n_z][n_y][n_x] == 0) {
                    box[n_z][n_y][n_x] = 1;
                    que.push({n_z, n_y, n_x});
                }
            }
        }
        day += 1;
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                if (box[i][j][k] == 0) {
                    day = -1;
                    goto fin;
                }
            }
        }
    }

fin:
    cout << day << '\n';
}

// 토마토
// Approach: queue
// note: sizeof(array)는 배열 길이가 아니라, 바이트를 반환한다.