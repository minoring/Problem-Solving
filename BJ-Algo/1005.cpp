#include <cstdio>
#include <vector>
#include <algorithm>

int t[1001];
int time_n[1001];
std::vector<int> buildings[1001];

// 이거 제귀호출 너무 많아서 스택 오버플로우나는듯.

int construct_time(int b) {
    if (time_n[b] != -1)
        return time_n[b];
    int b_time, max = 0;
    std::vector<int>::iterator iter;
    for (iter = buildings[b].begin(); iter != buildings[b].end(); ++iter) {
        b_time = construct_time(*iter);
        if (b_time > max)
            max = b_time;
    }
    time_n[b] = t[b] + max;
    return t[b] + max;
}

int main() {
    int test_case; scanf("%d", &test_case);

    while (test_case--) {
        int num_buildings, num_rules;
        int goal, req, con;
        std::fill_n(time_n, 1001, -1);
        scanf("%d %d", &num_buildings, &num_rules);

        for (int i = 1; i <= num_buildings; ++i)
            scanf("%d", &t[i]);
        for (int i = 0; i < num_rules; ++i) {
            scanf("%d %d", &req, &con);
            buildings[con].push_back(req);
        }
        scanf("%d", &goal);
        printf("%d\n", construct_time(goal));
    }
    return 0;
}