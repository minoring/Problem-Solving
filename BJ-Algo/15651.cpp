#include <iostream>
#include <vector>

using namespace std;

void combWithRepl(vector<int> &comb, int n, int m) {
    if (m == 0) {
        for (int i = 0; i < comb.size(); ++i) {
            cout << comb[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; ++i) {
        comb.push_back(i);
        combWithRepl(comb, n, m - 1);
        comb.pop_back();
    }
}

int main() {
    int n;
    int m;
    cin >> n >> m;

    vector<int> comb;
    combWithRepl(comb, n, m);
}
