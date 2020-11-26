#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int n;
int A[1001];
int cache[1001];
int choices[1001];

int lis(int start) {
    int &ret = cache[start + 1];
    if (ret != -1) {
        return ret;
    }

    ret = 1;
    int best_next = -1;
    for (int next = start + 1; next < n; ++next) {
        if (start == -1 || A[start] < A[next]) {
            int cand = lis(next) + 1;
            if (cand > ret) {
                ret = cand;
                best_next = next;
            }
        }
    }

    choices[start + 1] = best_next;
    return ret;
}

void recon(int start, vector<int> &seq) {
    if (start != -1) {
        seq.push_back(A[start]);
    }
    int next = choices[start + 1];
    if (next != -1) {
        recon(next, seq);
    }
}

int main() {
    cin >> n;

    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    cout << lis(-1) - 1 << '\n';

    vector<int> seq;
    recon(-1, seq);
    for (int i = 0; i < seq.size(); ++i) {
        cout << seq[i] << ' ';
    }
    cout << '\n';
}
