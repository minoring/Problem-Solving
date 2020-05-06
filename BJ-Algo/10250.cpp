#include <iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--) {
    int H, W, n;
    cin >> H >> W >> n;

    int height = ((n % H == 0) ? H : n % H);
    int room = n / H + ((n % H == 0) ? 0 : 1);

    cout << height * 100 + room << '\n';
  }
}
