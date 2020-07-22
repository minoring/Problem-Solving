#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(const vector<char>& codes, int i, int num_vowel, int num_consonant,
         string comb, int l) {
  if (i == codes.size()) {
    if (num_vowel >= 1 && num_consonant >= 2 && comb.length() == l) {
      cout << comb << '\n';
    }
    return;
  }

  if (codes[i] == 'a' || codes[i] == 'e' || codes[i] == 'i' ||
      codes[i] == 'o' || codes[i] == 'u') {
    num_vowel++;
  } else {
    num_consonant++;
  }
  dfs(codes, i + 1, num_vowel, num_consonant, comb + codes[i], l);
  dfs(codes, i + 1, num_vowel, num_consonant, comb, l);
}

int main() {
  int l, c;
  cin >> l >> c;

  vector<char> codes(c);
  for (int i = 0; i < c; ++i) {
    cin >> codes[i];
  }
  sort(codes.begin(), codes.end());
  dfs(codes, 0, 0, 0, "", l);
}
