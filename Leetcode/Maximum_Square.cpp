/*
dp[i][j]를 i, j까지의 최대 square x
i, j에서 끝나는 사각형의 square.
DP를 저장하는게 꼭 정답만 저장할 필요는 없다.
필요한걸 저장. 정답은 그중에 최고.
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int height = matrix.size();
        if (height == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int width = matrix[0].size();
        vector<vector<int>> dp(height, vector<int>(width));

        int answer = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (matrix[i][j] == '0') {
                    continue;
                }
                dp[i][j] = 1;
                if (i > 0 && j > 0) {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
                answer = max(answer, dp[i][j]);
            }
        }
        return answer * answer;
    }
};