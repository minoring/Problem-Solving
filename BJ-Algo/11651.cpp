/*
https://www.acmicpc.net/problem/11651
*/
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pii> points; 
    for (int i = 0; i < n; ++i) {
        int temp_x;
        int temp_y;
        cin >> temp_x >> temp_y;
        points.push_back({temp_x, temp_y});
    }

    sort(points.begin(), points.end(), [](const pii& a, const pii& b) {
        if (a.second < b.second) return 1;
        if (a.second == b.second && a.first < b.first) return 1;
        return 0;
    });

    for (const pii& point : points) {
        cout << point.first << ' ' << point.second << '\n';
    }
}