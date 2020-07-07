#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_set<string> never_heard;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        never_heard.insert(s);
    }

    priority_queue<string, vector<string>, greater<string>> pq;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if (never_heard.find(s) != never_heard.end()) {
            pq.push(s);
        }
    }

    cout << pq.size() << '\n';

    while (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }
}
