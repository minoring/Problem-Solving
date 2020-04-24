class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int x : stones) {
            pq.push(x);
        }
        while (pq.size() != 1) {
            int a = pq.top();
            pq.pop();
             if (pq.size() == 0) {
                return a;
            }
            int b = pq.top();
            pq.pop();
            pq.push(a - b);
        }
        return pq.top();
    }
};