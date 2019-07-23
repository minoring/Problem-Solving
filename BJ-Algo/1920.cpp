#include <unordered_set>
#include <cstdio>

using namespace std;

int main() {
    int n, m;
    const int N = 100000;
    unordered_set<int> a(N);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d", &temp);
        a.insert(temp);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int temp;
        scanf("%d", &temp);
        if (a.find(temp) == a.end()) {
            printf("0\n");
        } else {
            printf("1\n");
        }
    }
    
    return 0;
}