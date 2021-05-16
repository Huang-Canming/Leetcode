#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int numsSize = (int)nums.size();
        long long int maxProduct = nums[0];
        vector<long long int> dpMax(numsSize, 1);
        vector<long long int> dpMin(numsSize, 1);

        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        for (int i = 1; i < numsSize; i++)
        {
            dpMax[i] = max({(long long int)nums[i], nums[i] * dpMax[i - 1], nums[i] * dpMin[i - 1]});
            dpMin[i] = min({(long long int)nums[i], nums[i] * dpMax[i - 1], nums[i] * dpMin[i - 1]});
            if (dpMax[i] > maxProduct)
            {
                maxProduct = dpMax[i];
            }
        }

        return maxProduct;
    }
};

int main()
{

    Solution solution;
    vector<int> nums1 = {2, 3, -2, 4};
    vector<int> nums2 = {-2, 0, -1};

    cout << solution.maxProduct(nums1) << endl;
    cout << solution.maxProduct(nums2) << endl;

    return 0;
}