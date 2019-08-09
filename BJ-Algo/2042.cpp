#include <cassert>
#include <cstdio>

using namespace std;

typedef long long ll;

ll N[4000001];
ll input_data[1000000];

ll build_tree(int idx, int l, int r) {
    if (l == r) {
        N[idx] = input_data[l];
        return N[idx];
    }

    int mid = (l + r) / 2;
    N[idx] = build_tree(2 * idx, l, mid) + build_tree(2 * idx + 1, mid + 1, r);
    return N[idx];
}

ll calc_sum(int l, int r, int start, int end, int idx) {
    if (l > r) {
        return 0;
    }

    if (l <= start && end <= r) {
        return N[idx];
    } else if (r < start || l > end) {
        return 0;
    } else {
        int mid = (start + end) / 2;
        return calc_sum(l, r, start, mid, 2 * idx) +
               calc_sum(l, r, mid + 1, end, 2 * idx + 1);
    }
}

int change_val(int curr_node, int l, int r, int target_idx, int val) {
    ll diff = 0;

    if (l == r && r == target_idx) {
        diff = val - N[curr_node];
        N[curr_node] = val;

        return diff;
    }

    int mid = (l + r) / 2;
    if (target_idx <= mid) {
        diff = change_val(curr_node * 2, l, mid, target_idx, val);
    } else {
        diff = change_val(curr_node * 2 + 1, mid + 1, r, target_idx, val);
    }
    N[curr_node] += diff;
    return diff;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &input_data[i]);
    }

    build_tree(1, 0, n - 1);

    for (int i = 0; i < m + k; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            change_val(1, 0, n - 1, b - 1, c);
        } else if (a == 2) {
            ll sum = calc_sum(b - 1, c - 1, 0, n - 1, 1);
            printf("%lld\n", sum);
        } else {
            assert(0);
        }
    }
}