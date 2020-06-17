#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  int m;
  cin >> n >> m;
  vector<bool> isPrime(m + 1);
  fill(isPrime.begin(), isPrime.end(), true);
  isPrime[1] = false;

  for (int i = 2; i * i <= m; ++i) {
    if (isPrime[i]) {
      for (int j = i * 2; j <= m; j += i) {
        isPrime[j] = false;
      }
    }
  }

  bool foundPrime = false;
  int minPrime;
  int sum = 0;
  for (int i = n; i <= m; ++i) {
    if (isPrime[i]) {
      if (!foundPrime) {
        foundPrime = true;
        minPrime = i;
      }
      sum += i;
    }
  }

  if (!foundPrime) {
    cout << -1 << '\n';
  } else {
    cout << sum << '\n';
    cout << minPrime << '\n';
  }
}
