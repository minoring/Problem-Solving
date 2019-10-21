/*
https://leetcode.com/problems/n-queens/
Approach: Backtracking
Think
1. choice, explorer
2. constraints
3. Goal
*/
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<int> col_placements;
        solveHelper(&res, col_placements, n, 0);
        return res;
    }

    vector<string> createPlacedBoard(int n, const vector<int>& col_placements) {
        vector<string> board;
        for (int row = 0; row < n; ++row) {
            string curr_row = "";
            int col_place = col_placements[row];
            for (int col = 0; col < n; ++col) {
                if (col == col_place) {
                    curr_row += "Q";
                } else {
                    curr_row += ".";
                }
            }
            board.push_back(curr_row);
        }
        return board;
    }

    void solveHelper(vector<vector<string> >* res, vector<int>& col_placements,
                     int n, int curr_row) {
        if (curr_row == n) {
            res->push_back(createPlacedBoard(n, col_placements));
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isValid(col_placements, col)) {
                col_placements.push_back(col);
                solveHelper(res, col_placements, n, curr_row + 1);
                col_placements.pop_back();
            }
        }
    }

    bool isValid(const vector<int>& col_placements, int curr_col) {
        int curr_row = col_placements.size();
        for (int row = 0; row < curr_row; ++row) {
            int diff = col_placements[row] - curr_col;
            diff = (diff < 0) ? -diff : diff;
            if (diff == 0 || diff == curr_row - row) {
                return false;
            }
        }
        return true;
    }
};