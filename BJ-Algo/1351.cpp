#include <iostream>
#include <map>

typedef unsigned long long ull;

using namespace std;

ull p;
ull q;
map<ull, ull> dp;

ull seq(ull n) {
    if (dp.find(n) == dp.end()) {
        dp.insert(pair<ull, ull>(n, seq(ull(n / p)) + seq(ull(n / q))));
    }
    return dp[n];
}

int main() {
    dp.insert(pair<ull, ull>(0, 1));
    ull n;

    cin >> n >> p >> q;
    cout << seq(n) << '\n';
}