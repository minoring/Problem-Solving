#include <cstdio>
#include <queue>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        int res = 1;
        scanf("%d %d", &n, &m);

        std::queue<std::pair<int, int> > q;
        std::priority_queue<int> pq;

        for (int i = 0; i < n; ++i) {
            int v;
            scanf("%d", &v);
            q.push({i, v});
            pq.push(v);
        }

        while (!q.empty()) {
            if (q.front().second == pq.top()) {
                if (q.front().first == m) {
                    printf("%d\n", res);
                    break;
                } else {
                    q.pop();
                    res++;
                }
                pq.pop();
            } else {
                q.push({q.front().first, q.front().second});
                q.pop();
            }
        }
    }
}