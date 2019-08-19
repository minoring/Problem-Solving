#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
vector<int> v;

void solve(int idx, int depth) {
    if (m == depth) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i <= n; ++i) {
        v.push_back(i);
        solve(i + 1, depth + 1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    solve(1, 0);
}