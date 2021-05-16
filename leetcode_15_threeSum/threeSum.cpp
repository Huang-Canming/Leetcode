#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    #if 0
    /* 错误思路实现 */
    vector<vector<int>> threeSum(vector<int>& nums) {

        int left = 0, right = nums.size() - 1, mid = 0, diff = 0;
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        while(left < right - 1)
        {
            diff = 0 - (nums[left] + nums[right]);

            if (diff < nums[left])
            {
                right--;
                continue;
            }
            else if (diff < nums[left])
            {
                left++;
                continue;
            }

            mid = left + 1;
            while (mid < right && nums[mid] != diff)
            {
                mid++;
            }

            if (nums[mid] == diff)
            {
                res.push_back({nums[left], nums[mid], nums[right]});
            }

            left++;
        }

        return res;
    }
    #endif

    vector<vector<int>> threeSum(vector<int>& nums) {

        int first = 0, second = 0, third = 0, numsSize = (int)nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        for (first = 0; first < numsSize; first++)
        {
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }

            third = numsSize - 1;
            for (second = first + 1; second < numsSize; second++)
            {
                if (second > first + 1 && nums[second] == nums[second - 1])
                {
                    continue;
                }

                // third = numsSize - 1;
                while (second < third  && nums[first] + nums[second] + nums[third] > 0)
                {
                    third--;
                }

                /* 如果指针重合，随着 b 后续的增加就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环 */
                if (second == third)
                {
                    break;
                }

                if (nums[first] + nums[second] + nums[third] == 0)
                {
                    res.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res;

    res = solution.threeSum(nums);

    return 0;
}