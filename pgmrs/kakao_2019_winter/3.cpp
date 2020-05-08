#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Comb(vector<string>& curr, vector<string>& user_id, int k, int depth,
          vector<vector<string>>& all_comb);
void Perm(vector<string>& s, int depth, vector<vector<string>>& perm);

bool Match(string& a, string& b) {
    if (a.length() != b.length()) {
        return false;
    }
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] != b[i] && b[i] != '*') {
            return false;
        }
    }
    return true;
}

bool AllMatch(vector<string>& a, vector<string>& b) {
    for (int i = 0; i < a.size(); ++i) {
        if (!Match(a[i], b[i])) {
            return false;
        }
    }
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << ' ' << b[i] << '\n';
    }

    return true;
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    vector<string> curr;
    vector<vector<string>> all_comb;

    Comb(curr, user_id, banned_id.size(), 0, all_comb);

    for (int i = 0; i < all_comb.size(); ++i) {
       	vector<vector<string>> perm_all_comb;
        Perm(all_comb[i], 0, perm_all_comb);
        for (int j = 0; j < perm_all_comb.size(); ++j) {
            if (AllMatch(perm_all_comb[j], banned_id)) {
                answer++;
                break;
            }
        }

    }

    return answer;
}


void Comb(vector<string>& curr, vector<string>& user_id, int k, int depth,
         vector<vector<string>>& all_comb) {
	if (k == 0) {
        all_comb.push_back(curr);
    }

    for (int i = depth; i < user_id.size(); ++i) {
        curr.push_back(user_id[i]);
       	Comb(curr, user_id, k - 1, i + 1, all_comb);
        curr.pop_back();
    }
}

void Perm(vector<string>& s, int depth, vector<vector<string>>& perm) {
    if (depth == s.size()) {
        perm.push_back(s);
        return;
    }
    for (int i = depth; i < s.size(); ++i) {
        swap(s[depth], s[i]);
        Perm(s, depth + 1, perm);
        swap(s[depth], s[i]);
    }
}