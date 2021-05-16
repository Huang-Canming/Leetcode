
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, mid = 0, right = nums.size() - 1;

        while(left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[left] < nums[mid] && nums[left] <= target && target <= nums[mid])
            {
                right = mid - 1;
            }
            else if (nums[mid] < nums[left] && (target <= nums[mid] || nums[left] <= target))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return -1;
    }
};

int main()
{
    int target = 1;
    vector<int> nums = {5, 1, 2, 3, 4};
    Solution solution;

    cout << solution.search(nums, target) << endl;

    return 0;
}