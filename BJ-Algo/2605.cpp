#include <iostream>
#include <iterator>
#include <list>

using namespace std;

int main() {
    int n;
    cin >> n;

    list<int> students;
    for (int i = 0; i < n; ++i) {
        int pick;
        cin >> pick;
        auto it = students.end();
        advance(it, -pick);
        students.insert(it, i + 1);
    }

    for (auto student : students) {
        cout << student << ' ';
    }
}
