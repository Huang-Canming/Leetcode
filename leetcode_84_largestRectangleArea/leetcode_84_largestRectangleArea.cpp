#include <vector>
#include <iostream>

using namespace std;

#if 1
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, area = 0, left = 0, right = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (i > 1 && heights[i] == heights[i - 1]) {
                continue;
            }
            
            left = i;
            right = i;
            while (left >= 0 && heights[left] >= heights[i]) {
                left--;
            }
            while (right < heights.size() && heights[right] >= heights[i]) {
                right++;
            }
            area = heights[i] * (right - left - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
#endif

int main () {
    Solution s;
    vector<int> heights = {2,1,5,6,2,3};
    cout << s.largestRectangleArea(heights) << endl;
    return 0;
}