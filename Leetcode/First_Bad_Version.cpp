// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 0;
        int hi = n;

        int answer = -1;
        while (hi >= lo) {
            int mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid)) {
                answer = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return answer;
    }
};