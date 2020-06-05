class Solution {
public:
  void reverseString(vector<char> &s) {
    int lo = 0;
    int hi = s.size() - 1;
    while (hi > lo) {
      swap(s[lo], s[hi]);
      lo++;
      hi--;
    }
  }
};
