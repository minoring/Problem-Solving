/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int num_rows = dim[0];
        int num_cols = dim[1];

        int answer = -1;
        for (int i = 0; i < num_rows; ++i) {
            int lo = 0;
            int hi = num_cols - 1;
            while (hi >= lo) {
                int mid = lo + (hi - lo) / 2;
                if (binaryMatrix.get(i, mid) == 1) {
                    if (answer < 0) {
                        answer = mid;
                    } else {
                        answer = min(answer, mid);
                    }
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }
        return answer;
    }
};