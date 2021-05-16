#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    #if 0
    void backTrace(vector<int>& nums, vector<int>& visited, int pos, int sum, int &maxSum){

        if (pos == (int)nums.size())
        {
            maxSum = sum > maxSum ? sum : maxSum;
            return;
        }

        /* 偷这家店 */
        if (0 == pos || 1 != visited[pos - 1]) 
        {
            visited[pos] = 1;
            backTrace(nums, visited, pos + 1, sum + nums[pos], maxSum);
            visited[pos] = 0;
        }

        /* 不偷这家店 */
        backTrace(nums, visited, pos + 1, sum, maxSum);

        return;
    }

    int rob(vector<int>& nums) {

        int numsSize = (int)nums.size(), pos = 0, sum = 0, maxSum = 0;
        vector<int> visited(numsSize, 0);

        backTrace(nums, visited, pos, sum, maxSum);

        return maxSum;
    }
    #endif

    int rob(vector<int>& nums) {

        int numsSize = (int)nums.size();
        vector<int> dp(numsSize, 0);

        if (1 == numsSize)
        {
            return nums[0];
        }

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < numsSize; i++)
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[numsSize - 1];
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {2, 1, 1, 2};

    cout << solution.rob(nums) << endl;

    return 0;
}