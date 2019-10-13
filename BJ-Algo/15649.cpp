/*
https://www.acmicpc.net/problem/15649
Approach: Permutation, Recursive
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void PrintPermutation(const vector<int>& curr_permutation) {
    for (int num : curr_permutation) {
        cout << num << ' ';
    }
    cout << '\n';
}

void CalcPermutation(vector<int> curr_permutation, int start_idx, int m,
                     vector<int> remainders) {
    if (curr_permutation.size() == m) {
        PrintPermutation(curr_permutation);
    }

    sort(remainders.begin() + start_idx, remainders.end());

    for (int i = start_idx; i < remainders.size(); ++i) {
        curr_permutation.push_back(remainders[i]);
        swap(remainders[start_idx], remainders[i]);
        CalcPermutation(curr_permutation, start_idx + 1, m, remainders);
        swap(remainders[start_idx], remainders[i]);
        curr_permutation.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;
    cin >> n >> m;

    vector<int> remainders;
    for (int i = 0; i < n; ++i) {
        remainders.push_back(i + 1);
    }

    CalcPermutation(vector<int>(), 0, m, remainders);
}