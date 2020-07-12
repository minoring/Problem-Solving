#include <climits>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool allTwelve(const vector<int> &times) {
    for (int i = 0; i < times.size(); ++i) {
        if (times[i] != 12) {
            return false;
        }
    }
    return true;
}

void pushButton(vector<int> &times, const vector<unordered_set<int>> &links,
                int button) {
    for (auto elem : links[button]) {
        times[elem] += 3;
        if (times[elem] == 15) {
            times[elem] = 3;
        }
    }
}

int minNumPush(vector<int> &times, const vector<unordered_set<int>> &links,
               int button, int cnt) {
    if (button == 10) {
        if (allTwelve(times)) {
            return cnt;
        }
        return INT_MAX;
    }

    int ans = INT_MAX;
    for (int i = 0; i < 4; ++i) {
        ans = min(ans, minNumPush(times, links, button + 1, cnt + i));
        pushButton(times, links, button);
    }
    return ans;
}

int main() {
    int c;
    cin >> c;

    vector<unordered_set<int>> links(10);
    links[0].insert({0, 1, 2});
    links[1].insert({3, 7, 9, 11});
    links[2].insert({4, 10, 14, 15});
    links[3].insert({0, 4, 5, 6, 7});
    links[4].insert({6, 7, 8, 10, 12});
    links[5].insert({0, 2, 14, 15});
    links[6].insert({3, 14, 15});
    links[7].insert({4, 5, 7, 14, 15});
    links[8].insert({1, 2, 3, 4, 5});
    links[9].insert({3, 4, 5, 9, 13});

    while (c--) {
        vector<int> times;
        for (int i = 0; i < 16; ++i) {
            int temp;
            cin >> temp;
            times.push_back(temp);
        }

        int answer = minNumPush(times, links, 0, 0);
        if (answer == INT_MAX) {
            answer = -1;
        }
        cout << answer << '\n';
    }
}
