#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int max_area = (r - l) * min(height[r], height[l]);
        while (r > l) {
            if (height[l] > height[r]) {
                r--;
            } else {
                l++;
            }
            max_area = max(max_area, (r - l) * min(height[r], height[l]));
        }

        return max_area;
    }
};