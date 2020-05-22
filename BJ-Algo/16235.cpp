#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct Tree {
    int r;
    int c;
    int age;

    Tree(int r, int c, int age) : r(r), c(c), age(age) {}
};

vector<Tree> spreadTrees;
int numTrees = 0;

void SpringSummer(int N, vector<vector<deque<int>>> &trees,
                  vector<vector<int>> &energy) {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (trees[r][c].empty()) {
                continue;
            }
            int dieEnergy = 0;
            deque<int> newTrees;
            for (int i = 0; i < trees[r][c].size(); ++i) {
                int age = trees[r][c][i];
                if (energy[r][c] < age) {
                    dieEnergy += age / 2;
                    numTrees--;
                } else {
                    energy[r][c] -= age;
                    int newAge = age + 1;
                    newTrees.push_back(newAge);
                    if (newAge % 5 == 0) {
                        spreadTrees.push_back(Tree(r, c, newAge));
                    }
                }
            }
            energy[r][c] += dieEnergy;
            trees[r][c] = newTrees;
        }
    }
}

const int dir[8][2] = {{-1, -1}, {-1, 0},  {-1, +1}, {0, -1},
                       {0, +1},  {+1, -1}, {+1, 0},  {+1, +1}};
void Autumn(int N, vector<vector<deque<int>>> &trees) {
    for (int i = 0; i < spreadTrees.size(); ++i) {
        for (int d = 0; d < 8; ++d) {
            int new_r = spreadTrees[i].r + dir[d][0];
            int new_c = spreadTrees[i].c + dir[d][1];
            if (new_r >= 0 && new_r < N && new_c >= 0 && new_c < N) {
                trees[new_r][new_c].push_front(1);
                numTrees++;
            }
        }
    }
    spreadTrees.clear();
}

void Winter(int N, vector<vector<int>> &A, vector<vector<int>> &energy) {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            energy[r][c] += A[r][c];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;

    cin >> N >> M >> K;

    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> energy(N, vector<int>(N, 5));
    vector<vector<deque<int>>> trees(N, vector<deque<int>>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < M; ++i) {
        int r, c, z;
        cin >> r >> c >> z;
        trees[r - 1][c - 1].push_back(z);
        numTrees++;
    }

    for (int i = 0; i < K; ++i) {
        SpringSummer(N, trees, energy);
        Autumn(N, trees);
        Winter(N, A, energy);
    }

    cout << numTrees << '\n';
}
