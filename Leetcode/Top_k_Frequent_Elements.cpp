/*
https://leetcode.com/problems/top-k-frequent-elements/
Approach: Heap
Algorithm:
First, count frequency O(N)
Second, build heap adding take O(log(m)), we have N elements,
it takes O(Nlog(m)). (m is number of node in heap)
Last step, output list O(klog(m))
Time complexity: O(Nlog(k))
Space complexity: O(n) to store the hash map

정렬하지 말고 Heap 쓰자.
정렬: O(NlogN)
힙: 만드는거 O(Nlogm), 빼는거 (klogm) (k is num of operation)
*/

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }

        priority_queue<pair<int, int> > pq;
        for (auto it = freq_map.begin(); it != freq_map.end(); ++it) {
            pq.push({it->second, it->first});
        }

        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};