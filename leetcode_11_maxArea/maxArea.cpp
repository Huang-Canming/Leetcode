#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int heightLen = height.size();
        int left = 0, right = heightLen - 1;
        int res = 0, waterContain = 0;

        while (left < right)
        {
            waterContain = min(height[left], height[right]) * (right - left);
            if (waterContain > res)
            {
                res = waterContain;
            }

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return res;
    }
};

int main ()
{
    Solution solution;
    vector<int> vTest = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << solution.maxArea(vTest) << endl;

    return 0;
}