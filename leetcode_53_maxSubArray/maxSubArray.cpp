#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void calMaxSubSum(vector<int>& nums, int index, vector<int> &maxSubSum) 
    {
        int vecSize = nums.size();

        if (-10001 == maxSubSum[index])
        {
            if (index == vecSize - 1)
            {
                maxSubSum[index] = nums[index];
            }
            else
            {
                calMaxSubSum(nums, index + 1, maxSubSum);
                if (nums[index] + maxSubSum[index + 1] > nums[index])
                {
                    maxSubSum[index] = nums[index] + maxSubSum[index + 1];
                }
                else
                {
                    maxSubSum[index] = nums[index];
                }
            }
        }

        return;
    }

    int maxSubArray(vector<int>& nums) {
        int sum = -10001;
        int maxSum = -10001;
        int vecSize = nums.size();
        vector<int> maxSubSum(vecSize, -10001);

        for (int i = 0; i < vecSize; i++)
        {
            if (-10001 == maxSubSum[i])
            {
                calMaxSubSum(nums, i, maxSubSum);
            }

            if (maxSubSum[i] > maxSum)
            {
                maxSum = maxSubSum[i];
            }
        }

        return maxSum;
    }
};

int main()
{
    int res = 0;
    Solution solu;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    
    res = solu.maxSubArray(nums);
    cout << res << endl;

    return 0;
}