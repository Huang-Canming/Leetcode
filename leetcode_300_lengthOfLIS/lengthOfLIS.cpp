#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int numsSize = (int)nums.size();
        vector<int> dp(numsSize, 1);

        for (int i = 1; i < numsSize; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        auto iterLIS = max_element(dp.begin(), dp.end());
        return *iterLIS;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    cout << solution.lengthOfLIS(nums1) << endl;
    cout << solution.lengthOfLIS(nums2) << endl;
    cout << solution.lengthOfLIS(nums3) << endl;

    return 0;
}