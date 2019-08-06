#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > res;
        res.push_back(vector<int>());

        findSubset(nums, vector<int>(), 0, &res);

        return res;
    }

    void findSubset(const vector<int>& nums, vector<int> curr_vec, int i,
                    vector<vector<int> >* res) {
        if (i >= nums.size()) {
            return;
        }
        for (int j = i; j < nums.size(); ++j) {
            curr_vec.push_back(nums[j]);
            res->push_back(curr_vec);
            findSubset(nums, curr_vec, j + 1, res);
            curr_vec.pop_back();
        }
    }
};