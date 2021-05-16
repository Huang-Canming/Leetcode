#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthestPos = 0, numsSize = (int)nums.size();
        bool res = false;

        for (int i = 0; i < numsSize && i <= farthestPos; i++)
        {
            if (i + nums[i] > farthestPos)
            {
                farthestPos = i + nums[i];
            }

            if (farthestPos >= numsSize - 1)
            {
                res = true;
                break;
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {2, 5, 0, 0};

    cout << solution.canJump(nums) << endl;

    return 0;
}