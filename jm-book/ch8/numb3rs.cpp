#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

int n, p;
int A[51][51];
double cache[101][51];
int deg[51];

double from(int v) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (A[v][i]) {
            cnt++;
        }
    }
    return 1. / cnt;
}

double prob(int day, int v) {
    if (day == 0) {
        if (v == p) {
            return 1.;
        }
        return 0.;
    }

    double &ret = cache[day][v];
    if (ret > -0.5) {
        return ret;
    }

    ret = 0.;
    for (int w = 0; w < n; ++w) {
        if (A[v][w]) {
            ret += prob(day - 1, w) / deg[w];
        }
    }
    return ret;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        memset(cache, -1.0, sizeof(cache));
        memset(deg, 0, sizeof(deg));
        int d;
        cin >> n >> d >> p;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> A[i][j];
            }
        }

        for (int v = 0; v < n; ++v) {
            for (int w = 0; w < n; ++w) {
                if (A[v][w]) {
                    deg[v]++;
                }
            }
        }

        int t;
        cin >> t;
        for (int i = 0; i < t; ++i) {
            int end;
            cin >> end;
            cout << setprecision(8) << prob(d, end) << ' ';
        }
        cout << '\n';
    }
}
