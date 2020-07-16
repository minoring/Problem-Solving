#include <iostream>
#include <vector>

using namespace std;

void comb(vector<int> &curr, int n, int m, int depth) {
    if (m == 0) {
        for (int i = 0; i < curr.size(); ++i) {
            cout << curr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = depth; i <= n; ++i) {
        curr.push_back(i);
        comb(curr, n, m - 1, i);
        curr.pop_back();
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> curr;
    comb(curr, n, m, 1);
}
