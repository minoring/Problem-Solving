#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool CanGo(const vector<int>& stones, int mid, int k) {
    int count_zero = 0;
    for (int i = 0; i < stones.size(); ++i) {
        int curr = stones[i] - mid + 1;
        if (curr <= 0) {
            count_zero++;
            if (count_zero >= k) {
                return false;
            }
        } else {
            count_zero = 0;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;

    int hi = 200000000;
    int lo = 0;

    while (hi >= lo) {
        int mid = lo + (hi - lo) / 2;
        if (CanGo(stones, mid, k)) {
            answer = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return answer;
}
