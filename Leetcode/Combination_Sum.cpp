#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> comb;
        combinationSumHelper(&res, candidates, target, comb, 0);
        return res;
    }

    void combinationSumHelper(vector<vector<int> >* res,
                              const vector<int> &candidates, int target,
                              vector<int> &comb, int depth) {
        if (target == 0) {
            res->push_back(comb);
            return;
        }

        for (int i = depth; i < candidates.size() && target >= candidates[i];
             ++i) {
            comb.push_back(candidates[i]);
            combinationSumHelper(res, candidates, target - candidates[i], comb,
                                 i);
            comb.pop_back();
        }
    }
};