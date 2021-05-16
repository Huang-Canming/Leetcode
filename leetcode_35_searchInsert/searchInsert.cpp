#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        for (int i = 0; i < (int) nums.size(); i++)
        {
            if (nums[i] < target)
            {
                continue;
            }
            else if (nums[i] == target)
            {
                return i;
            }
            else 
            {
                return i;
            }
        }

        return (int) nums.size();
    }
};

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    Solution solution;

    cout << solution.searchInsert(nums, 5) << endl;
    cout << solution.searchInsert(nums, 2) << endl;
    cout << solution.searchInsert(nums, 7) << endl;
    cout << solution.searchInsert(nums, 0) << endl;

    return 0;
}