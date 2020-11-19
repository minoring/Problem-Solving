#include <cstring>
#include <iostream>

using namespace std;

int cache[101][101];
int count_cache[101][101];
int tri[101][101];
int n;

int find_max_path(int y, int x) {
    int &ret = cache[y][x];
    if (ret != -1) {
        return ret;
    }

    if (y == n) {
        ret = tri[y][x];
    } else {
        ret = tri[y][x] +
              max(find_max_path(y + 1, x), find_max_path(y + 1, x + 1));
    }

    return ret;
}

int tri_path_cnt(int y, int x) {
    if (y == n) {
        return 1;
    }

    int &ret = count_cache[y][x];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    if (find_max_path(y + 1, x) >= find_max_path(y + 1, x + 1)) {
        ret += tri_path_cnt(y + 1, x);
    }
    if (find_max_path(y + 1, x) <= find_max_path(y + 1, x + 1)) {
        ret += tri_path_cnt(y + 1, x + 1);
    }
    return ret;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        memset(cache, -1, sizeof(cache));
        memset(count_cache, -1, sizeof(count_cache));

        cin >> n;
        for (int y = 1; y <= n; ++y) {
            for (int x = 1; x <= y; ++x) {
                cin >> tri[y][x];
            }
        }

        cout << tri_path_cnt(1, 1) << '\n';
    }
}
