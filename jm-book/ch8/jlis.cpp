#include <iostream>
#include <limits>
#include <vector>

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();

int A[100];
int B[100];
int n;
int m;

int cache[101][101];

int jlis(int a_i, int b_i) {
    int &ret = cache[a_i + 1][b_i + 1];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    long long a = a_i == -1 ? NEGINF : A[a_i];
    long long b = b_i == -1 ? NEGINF : B[b_i];
    long long max_elem = max(a, b);

    for (int a_next = a_i + 1; a_next < n; ++a_next) {
        if (max_elem < A[a_next]) {
            ret = max(ret, jlis(a_next, b_i) + 1);
        }
    }

    for (int b_next = b_i + 1; b_next < m; ++b_next) {
        if (max_elem < B[b_next]) {
            ret = max(ret, jlis(a_i, b_next) + 1);
        }
    }

    return ret;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        memset(cache, -1, sizeof(cache));
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> B[i];
        }
        cout << jlis(-1, -1) << '\n';
    }
}
