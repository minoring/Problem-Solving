#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, w;
int scores[101];
int volumns[101];
vector<string> names;
int choices[101];
int cache[1001][100];

int pack(int cap, int item) {
    if (item == n) {
        return 0;
    }
    int &ret = cache[cap][item];
    if (ret != -1) {
        return ret;
    }
    ret = pack(cap, item + 1);
    if (cap >= volumns[item]) {
        ret = max(ret, pack(cap - volumns[item], item + 1) + scores[item]);
    }
    return ret;
}

void recon(int cap, int item, vector<string> &out) {
    if (item == n) {
        return;
    }
    if (pack(cap, item) == pack(cap, item + 1)) {
        recon(cap, item + 1, out);
    } else {
        out.push_back(names[item]);
        recon(cap - volumns[item], item + 1, out);
    }
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        memset(cache, -1, sizeof(cache));

        cin >> n >> w;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            names.push_back(s);

            cin >> volumns[i];
            cin >> scores[i];
        }

        cout << pack(w, 0) << ' ';

        vector<string> out;
        recon(w, 0, out);

        cout << out.size() << '\n';
        ;

        for (int i = 0; i < out.size(); ++i) {
            cout << out[i] << '\n';
        }

        names.clear();
    }
}
