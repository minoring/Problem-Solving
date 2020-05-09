#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long ll;

ll Find(unordered_map<ll, ll>& m, ll room) {
	if (m.find(room) == m.end()) {
        m[room] = room + 1;
        return room;
    }
    return m[room] = Find(m, m[room]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    unordered_map<ll, ll> m;
    for (ll room : room_number) {
        ll u = Find(m, room);
        answer.push_back(u);
    }
    return answer;
}
