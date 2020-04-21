#include <iostream>

using namespace std;

int max_val = -1000000001;
int min_val = 1000000001;

int n;
int nums[4];
int a[11];

int Max(int a, int b)
{
  if (a > b)
    return a;
  return b;
}

int Min(int a, int b)
{
  if (a < b)
    return a;
  return b;
}

void FindMaxMin(int curr_val, int idx)
{
  if (idx >= n) {
    max_val = Max(max_val, curr_val);
    min_val = Min(min_val, curr_val);
  }
  for (int i = 0; i < 4; ++i) {
    if (nums[i] <= 0) {
      continue;
    }
    nums[i] -= 1;
    int val;
    if (i == 0) {
      FindMaxMin(curr_val + a[idx], idx + 1);
    }
    if (i == 1) {
      FindMaxMin(curr_val - a[idx], idx + 1);
    }
    if (i == 2) {
      FindMaxMin(curr_val * a[idx], idx + 1);
    }
    if (i == 3) {
      FindMaxMin(curr_val / a[idx], idx + 1);
    }

    nums[i] += 1;
  }
}

int main()
{
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];

  FindMaxMin(a[0], 1);

  cout << max_val << '\n' << min_val << '\n';
}
