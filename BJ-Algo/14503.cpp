#include <iostream>

using namespace std;

int grid_map[51][51];

struct Pos {
  int r;
  int c;
};

int mov[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int n;
int m;

int LeftDir(int dir)
{
  if (dir - 1 < 0)
    return 3;
  return dir - 1;
}

bool LeftExistsClean(Pos pos, int dir)
{
  dir = LeftDir(dir);
  Pos moved_pos;
  moved_pos.r = pos.r + mov[dir][0];
  moved_pos.c = pos.c + mov[dir][1];

  if (moved_pos.r < 0 || moved_pos.r >= n) {
    return false;
  }
  if (moved_pos.c < 0 || moved_pos.c >= m) {
    return false;
  }

  if (grid_map[moved_pos.r][moved_pos.c] == 0) {
    return true;
  }
  return false;
}

Pos Goto(Pos curr_pos, int dir)
{
  Pos new_pos;
  new_pos.r = curr_pos.r + mov[dir][0];
  new_pos.c = curr_pos.c + mov[dir][1];

  return new_pos;
}

bool CanGoBack(Pos curr_pos, int dir)
{
  Pos new_pos;
  new_pos.r = curr_pos.r - mov[dir][0];
  new_pos.c = curr_pos.c - mov[dir][1];

  if (new_pos.r < 0 || new_pos.r >= n || new_pos.c < 0 || new_pos.c >= m) {
    return false;
  }

  if (grid_map[new_pos.r][new_pos.c] == 1) {
    return false;
  }

  return true;
}

Pos GoBack(Pos curr_pos, int dir)
{
  Pos new_pos;
  new_pos.r = curr_pos.r - mov[dir][0];
  new_pos.c = curr_pos.c - mov[dir][1];

  return new_pos;
}

int main()
{
  cin >> n >> m;

  int dir;
  Pos pos;
  cin >> pos.r >> pos.c >> dir;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid_map[i][j];
    }
  }

  int num_clean = 0;
  int tried = 0;

  while (true) {
    if (tried == 4) {
      if (CanGoBack(pos, dir)) {
        pos = GoBack(pos, dir);
        tried = 0;
      } else {
        break;
      }
    }

    if (grid_map[pos.r][pos.c] == 0) {
      num_clean++;
      grid_map[pos.r][pos.c] = 2;
      tried = 0;
    }

    if (LeftExistsClean(pos, dir)) {
      dir = LeftDir(dir);
      pos = Goto(pos, dir);
      tried = 0;
      continue;
    } else {
      dir = LeftDir(dir);
      tried++;
    }
  }
  cout << num_clean << '\n';
}
