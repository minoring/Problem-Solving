#include <iostream>
#include <vector>

using namespace std;

long long calcNumCables(const vector<int> &cables, long long mid) {
    long long numCables = 0;
    for (int i = 0; i < cables.size(); ++i) {
        numCables += cables[i] / mid;
    }
    return numCables;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long K, N;
    cin >> K >> N;


    vector<int> cables(K);
    for (int i = 0; i < K; ++i) {
        cin >> cables[i];
    }

    long long hi = 2147483647;
    long long lo = 1;
    int answer;
    while (hi >= lo) {
        long long mid = lo + (hi - lo) / 2;
        long long numCables = calcNumCables(cables, mid);
        if (numCables >= N) {
            answer = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << answer << '\n';
}
