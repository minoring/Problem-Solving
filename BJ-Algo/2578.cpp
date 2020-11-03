#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, pair<int, int>> board;
vector<vector<bool>> visited(5, vector<bool>(5));

int hori(int r) {
  for (int i = 0; i < 5; ++i) {
    if (!visited[r][i]) {
      return 0;
    }
  }
  return 1;
}

int vert(int c) {
  for (int i = 0; i < 5; ++i) {
    if (!visited[i][c]) {
      return 0;
    }
  }
  return 1;
}

int up_diag() {
  for (int i = 0; i < 5; ++i) {
    if (!visited[i][i]) {
      return 0;
    }
  }
  return 1;
}

int down_diag() {
  for (int i = 0; i < 5; ++i) {
    if (!visited[4 - i][i]) {
      return 0;
    }
  }
  return 1;
}

int bingo(int r, int c) {
  return hori(r) + vert(c) + ((r == c) ? up_diag() : 0) +
         ((r + c == 4) ? down_diag() : 0);
}

int main() {

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      int n;
      cin >> n;
      board.insert({n, {i, j}});
    }
  }
  int ans = 0;
  for (int i = 1; i <= 25; ++i) {
    int n;
    cin >> n;
    int r = board[n].first;
    int c = board[n].second;
    visited[r][c] = true;

    ans += bingo(r, c);

    if (ans >= 3) {
      cout << i << '\n';
      break;
    }
  }
}
