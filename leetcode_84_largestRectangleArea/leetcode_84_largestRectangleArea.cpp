#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int res = 0;
        int height = 0;
        stack<int> stk;				// 单调递增栈，不直接存储 heights 中的元素，而是存储下标
        
        heights.push_back(0);		// 哨兵
        for (int i = 0; i < heights.size(); ++i)						
        {
            // 遍历到的元素比栈顶元素更小，把比遍历到的元素更大的栈里的元素都出栈
            while (!stk.empty() && heights[i] <= heights[stk.top()])
            {
                // 保留栈顶元素的具体高度
                height = heights[stk.top()];
                // 栈顶元素出栈
                stk.pop();
                if (stk.empty()) {
                    // 栈已空，对应的矩形宽度是“这个元素的下标”，因为栈为空说明：栈顶元素左边所有元素的高度都大于 height
                    res = max(res, height * i);
                } else {
                    // 栈非空，对应的矩形宽度是“右边比他小的第一个 - 左边比它小的第一个 - 1”
                    res = max(res, height * (i - stk.top() - 1));
                }
            }
            stk.push(i);
        }
        return res;
    }
};

int main () {
    Solution s;
    vector<int> heights = {2,1,5,6,2,3};
    cout << s.largestRectangleArea(heights) << endl;
    return 0;
}