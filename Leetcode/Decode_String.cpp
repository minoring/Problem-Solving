class Solution {
public:
  string decodeString(string s) {
    int i = 0;
    return helper(s, i);
  }
  string helper(string s, int &i) {
    string ans;
    while (i < s.length() && s[i] != ']') {
      if (!isdigit(s[i])) {
        ans += s[i];
        ++i;
      } else {
        int n = 0;
        while (isdigit(s[i])) {
          n = n * 10 + s[i++] - '0';
        }

        i++; // '['
        string temp = helper(s, i);
        i++; // ']'
        while (n--) {
          ans += temp;
        }
      }
    }
    return ans;
  }
};
