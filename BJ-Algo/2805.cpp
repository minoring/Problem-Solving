#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long SumHeight(int mid, const vector<int> &trees) {
    long long sum = 0;
    for (int i = 0; i < trees.size(); ++i) {
        sum += max(trees[i] - mid, 0);
    }
    return sum;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> trees(N);

    for (int i = 0; i < N; ++i) {
        cin >> trees[i];
    }

    int lo = 0;
    int hi = 1000000000;
    long long answer;

    while (hi >= lo) {
        int mid = lo + (hi - lo) / 2;

        long long height = SumHeight(mid, trees);
        if (height >= M) {
            answer = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << answer << '\n';
}
