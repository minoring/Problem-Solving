#include <iostream>
#include <string>

using namespace std;

string quad(string::iterator &it) {
    char root = *it;
    it++;
    if (root == 'b' || root == 'w') {
        return string(1, root);
    }

    string q = quad(it);
    string w = quad(it);
    string e = quad(it);
    string r = quad(it);

    return string("x") + e + r + q + w;
}

int main() {
    int c;
    cin >> c;

    while (c--) {
        string s;
        cin >> s;
        string::iterator it = s.begin();
        cout << quad(it) << '\n';
    }
}
