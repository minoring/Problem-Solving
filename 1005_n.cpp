#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n, k, w, time[1001], pre[1001] = {0, };
        vector<int> suc[1001];
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &time[i]);
        for (int i = 0; i < k; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            suc[x].push_back(y);
            pre[y]++;
        }
        scanf("%d", &w);

        int result[1000] = {0, };
        queue<int> q;
        for (int i = 1; i <= n; ++i)
            if (!pre[i]) q.push(i);
        
        while (pre[w] > 0) {
            int u = q.front();
            q.pop();
            for (int next: suc[u]) {
                result[next] = max(result[next], result[u] + time[u]);
                if (--pre[next] == 0) q.push(next); // 이거다.. 선행자가 없으면 push 하게 해서 한번만 들어가게.
            }
        }
        printf("%d\n", result[w] + time[w]);
    }
    return 0;
}