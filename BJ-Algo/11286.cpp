#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    priority_queue<pair<int, int> > pq;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (x) {
            pq.push(pair<int, int>(-abs(x), -x));
        } else if (pq.empty()) {
            printf("0\n");
        } else {
            printf("%d\n", -pq.top().second);
            pq.pop();
        }
    }
    return 0;
}
