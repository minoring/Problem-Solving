/*
Make canonical form.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for (string s : strs) {
            string s2 = s;
            sort(s2.begin(), s2.end());
            m[s2].push_back(s);
        }
        vector<vector<string>> res;
        for (auto pp : m) {
            res.push_back(pp.second);
        }
        return res;
    }
};