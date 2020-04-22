/*
Int have 10 digits.
After one process, maximum of result is 10 * (9*9) which is really small.
Ao maximum iteration would be 810.
*/


class Solution {
    int f(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            n /= 10;
            sum += digit * digit;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> visited;

        while (true) {
            if (n == 1) {
                return true;
            }
            n = f(n);
            if (visited.count(n) == 1) {
                return false;
            }
            visited.insert(n);
        }
    }
};