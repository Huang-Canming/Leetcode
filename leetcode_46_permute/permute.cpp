#include <vector>

using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<bool>& numUsed, vector<int>& path)
    {
        int pathSize = (int)path.size();
        int numsSize = (int)nums.size();

        if (pathSize == numsSize)
        {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < numsSize; i++)
        {
            if (true == numUsed[i])
            {
                continue;
            }

            path.push_back(nums[i]);
            numUsed[i] = true;
            backtrack(res, nums, numUsed, path);
            path.pop_back();
            numUsed[i] = false;
        }

        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> numUsed(nums.size(), false);

        backtrack(res, nums, numUsed, path);
        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res;

    res = solution.permute(nums);

    return 0;
}