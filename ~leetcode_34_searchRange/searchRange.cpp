#include <vector>

using namespace std;

class Solution {
public:
    int binartSearch(vector<int>& nums, int target, bool bLeftBound)
    {
        int left = 0, mid = 0, right = nums.size() - 1;

        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] == target)
            {
                if (true == bLeftBound)
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                right = mid;
            }
        }

        if (true == bLeftBound && target == nums[left])
        {
            return left;
        }
        else if (false == bLeftBound && target != nums[left] && target == nums[left - 1])
        {
            return left - 1;
        }
        else if (false == bLeftBound && target == nums[left])
        {
            return left;
        }
        else
        {
            return -1;
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        if (0 == (int)nums.size())
        {
            return {-1, -1};
        }

        if (1 == (int)nums.size() && target != nums[0])
        {
            return {-1, -1};
        }
        else if (1 == (int)nums.size() && target == nums[0])
        {
            return {0, 0};
        }

        int leftBound = 0, rightBound = 0;

        leftBound = binartSearch(nums, target, true);
        if (-1 == leftBound)
        {
            return {-1, -1};
        }

        rightBound = binartSearch(nums, target, false);
        return {leftBound, rightBound};
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> res;

    res = solution.searchRange(nums, 8);

    return 0;
}