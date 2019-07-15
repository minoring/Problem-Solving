#include <cstdio>
#include <queue>

int main() {
    int n;
    scanf("%d", &n);
    std::queue<int> q;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }

    int res;
    while (!q.empty()) {
        res = q.front();
        q.pop();
        if (!q.empty()) {
            q.push(q.front());
            q.pop();
        }
    }
    printf("%d\n", res);
}