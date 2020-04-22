#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int grid[21][21];
int result = 2147483647;

int Abs(int x)
{
  if (x < 0)
    return -x;
  return x;
}

int Score(vector<int> t)
{
  int sum = 0;
  for (int i = 0; i < t.size(); ++i) {
    for (int j = i + 1; j < t.size(); ++j) {
      sum += grid[t[i]][t[j]] + grid[t[j]][t[i]];
    }
  }
  return sum;
}

void FindComb(vector<int> team_a, vector<int> team_b, int idx)
{
  if (team_a.size() == n / 2 && team_b.size() == n / 2) {
    int score_diff = Abs(Score(team_a) - Score(team_b));
    result = min(result, score_diff);
    return;
  }

  if (idx > n) {
    return;
  }

  team_a.push_back(idx);
  FindComb(team_a, team_b, idx + 1);
  team_a.pop_back();

  team_b.push_back(idx);
  FindComb(team_a, team_b, idx + 1);
  team_b.pop_back();
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
    }
  }

  vector<int> team_a;
  vector<int> team_b;

  FindComb(team_a, team_b, 0);
  cout << result << '\n';
}
