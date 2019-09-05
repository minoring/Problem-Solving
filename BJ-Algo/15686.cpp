#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 51
#define MAX_M 13

int n;
int m;
int res = INT_MAX;
int city[MAX_N][MAX_N];
bool visited[MAX_M + 1] = {
    false,
};

vector<pair<int, int>> chiken_coords;
vector<pair<int, int>> house_coords;

int l1_dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int idx, int num_selected) {
    if (idx > chiken_coords.size()) {
        return;
    }

    if (num_selected == m) {
        int curr_min_dist = 0;
        for (int i = 0; i < house_coords.size(); i++) {
            int dist = INT_MAX;
            for (int j = 0; j < chiken_coords.size(); j++) {
                if (!visited[j]) {
                    continue;
                }
                dist = min(dist, l1_dist(house_coords[i], chiken_coords[j]));
            }
            curr_min_dist += dist;
        }

        res = min(res, curr_min_dist);
        return;
    }

    visited[idx] = true;
    dfs(idx + 1, num_selected + 1);
    visited[idx] = false;
    dfs(idx + 1, num_selected);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
            if (city[i][j] == 1) {
                house_coords.push_back({i, j});
            } else if (city[i][j] == 2) {
                chiken_coords.push_back({i, j});
            }
        }
    }

    dfs(0, 0);
    cout << res << "\n";
}

/* 
치킨배달
https://www.acmicpc.net/problem/15686
Approach: Brute force
Key: comb로 안하고 visited dfs로 처리하는.
Time Complexity: O(13CM * 2N * M)
*/