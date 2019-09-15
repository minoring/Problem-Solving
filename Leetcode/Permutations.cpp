/*
https://leetcode.com/problems/permutations/
Approach: Recursion
Algorithm:
Combination이랑 다른점은 Combination은 for 문에서 넘어가면 이게 포함 되어있다는것, 
혹은 포함 안시키겠다 는것을 보장하고 넘어갈 수 있는데, permutation은 그러지 못함.
예를들어서 [1, 2, 3]에서 2의 위치에 index가 있을때, combination은 2를 포함 혹은
미포함 하고 조합을 구해야 하는데,
Permutation은 2를 포함시키면, [1, 3]의 배열을 갖고있던지 해서, 2가 이미 나와있다고,
나머지 순열 가능한게 뭔지 계산해야함.
하지만 vector의  insert, delete는 매우 시간복잡도가 높음

Key: 넣고 빼는게 시간이 오래걸리니 바꾸자!
이미 들어간걸 앞으로 swap하고, depth를 증가시켜서 다시 안나오게 한다.
Time Complexity: O(n!). permutation
Space Complexity: O(1). No extra mem.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        permuteHelper(res, 0, nums);
        return res;
    }
    
    void permuteHelper(vector<vector<int> >& res, int depth, 
                       vector<int>& nums) {
        if (depth == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = depth; i < nums.size(); ++i) {
            swap(nums[depth], nums[i]);
            permuteHelper(res, depth + 1, nums);
            swap(nums[depth], nums[i]);
        } 
    }
};