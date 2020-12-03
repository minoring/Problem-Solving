#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

int n;
int m;
double cache[1001][1001];
bool cache_filled[1001][1001];

double climb(int days, int climbed) {
    if (days == m) {
        return climbed >= n ? 1. : 0.;
    }

    if (cache_filled[days][climbed]) {
        return cache[days][climbed];
    }

    cache[days][climbed] = 0.75 * climb(days + 1, climbed + 2) +
                           0.25 * climb(days + 1, climbed + 1);
    cache_filled[days][climbed] = true;
    return cache[days][climbed];
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        memset(cache_filled, false, sizeof(cache_filled));
        cin >> n >> m;
        cout << setprecision(11) << climb(0, 0) << '\n';
    }
}
