class Solution {
public:
    int arrangeCoins(int n) {
        int answer = 0;
        int i = 1;
        while (n - i >= 0) {
            n -= i;
            answer++;
            i++;
        }
        return answer;
    }
};
