/*
https://leetcode.com/problems/group-anagrams/
Time Complexity: O(NKlogK), where N is the length of strs, and K is the
maximum length of string in strs.
Space Complexity: O(NK), total information contents in result.
나는 Sorting해줘서 비슷한놈끼리 묶었는데
Hash를 이용해서 Key: 같은애들 하는 방법이 있구나.
*/
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp;
        
        for (const string& str : strs) {
            string sort_str = str;
            sort(sort_str.begin(), sort_str.end());
            mp[sort_str].push_back(str);    
        }
        
        vector<vector<string> > anagrams;
        for (const auto& p : mp) {
            anagrams.push_back(p.second);
        }
        
        return anagrams;
    }
};