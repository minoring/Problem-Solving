#include <iostream>

using namespace std;

int m[50][50];
const int NUM_DIR = 8;
int dx[NUM_DIR] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[NUM_DIR] = {-1, -1, 0, 1, 1, 1, 0, -1};

void DFS(int i, int j, int w, int h) {
    if (i < 0 || i >= h || j < 0 || j >= w || !m[i][j]) {
        return;
    }

    m[i][j] = 0;
    for (int k = 0; k < NUM_DIR; ++k) {
        DFS(i + dy[k], j + dx[k], w, h);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int w;
    int h;
    cin >> w >> h;
    while (w != 0 || h != 0) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> m[i][j];
            }
        }

        int num_island = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (m[i][j] == 1) {
                    ++num_island;
                    DFS(i, j, w, h);
                }
            }
        }
        cout << num_island << '\n';
        cin >> w >> h;
    }
}