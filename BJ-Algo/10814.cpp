#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person {
    int age;
    string name;
    int order;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<Person> people(N);

    for (int i = 0; i < N; ++i) {
        cin >> people[i].age >> people[i].name;
        people[i].order = i;
    }

    sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        if (a.age < b.age) {
            return true;
        }
        if (b.age < a.age) {
            return false;
        }
        if (a.order < b.order) {
            return true;
        }
        return false;
    });

    for (int i = 0; i < N; ++i) {
        cout << people[i].age << " " << people[i].name << '\n';
    }
}
