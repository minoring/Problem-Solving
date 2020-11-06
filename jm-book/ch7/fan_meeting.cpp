#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void addTo(vector<int> &a, const vector<int> &b, int k) {
    a.resize(max(a.size(), b.size() + k));
    for (int i = 0; i < b.size(); ++i) {
        a[i + k] += b[i];
    }
}

void subFrom(vector<int> &a, const vector<int> &b) {
    a.resize(max(a.size(), b.size()) + 1);
    for (int i = 0; i < b.size(); ++i) {
        a[i] -= b[i];
    }
}

vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vector<int> c(a.size() + b.size() + 1, 0);

    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            c[i + j] += a[i] * b[j];
        }
    }

    return c;
}

vector<int> karatsuba(const vector<int> &a, const vector<int> &b) {
    if (a.size() < b.size()) {
        return karatsuba(b, a);
    }

    if (a.size() == 0 || b.size() == 0) {
        return vector<int>();
    }

    if (a.size() <= 50) {
        return multiply(a, b);
    }

    int half = a.size() / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    addTo(a0, a1, 0);
    addTo(b0, b1, 0);
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);

    return ret;
}

int hugs(const vector<int> &a, const vector<int> &b) {
    vector<int> c = karatsuba(a, b);

    int num_hugs = 0;
    for (int i = a.size() - 1; i < b.size(); ++i) {
        if (c[i] == 0) {
            num_hugs++;
        }
    }
    return num_hugs;
}

int main() {
    int c;
    cin >> c;

    while (c--) {
        string members;
        string fans;
        cin >> members >> fans;

        vector<int> a(members.size());
        vector<int> b(fans.size());

        for (int i = 0; i < members.size(); ++i) {
            a[i] = (members[i] == 'M') ? 1 : 0;
        }
        for (int i = 0; i < fans.size(); ++i) {
            b[fans.size() - i - 1] = (fans[i] == 'M') ? 1 : 0;
        }

        cout << hugs(a, b) << '\n';
    }
}
