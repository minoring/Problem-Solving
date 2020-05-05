class Solution {
public:
    int findComplement(int num) {
        int temp = num;
        int answer = 0;
        int bit = 0;
        while (temp > 0) {
            answer |= (!(temp % 2)) << bit;
            temp /= 2;
            bit++;
        }
        return answer;
    }
};