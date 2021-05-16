#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        if (0 != nums[0])
        {
            return 0;
        }
        
        for (int i = 0; i < (int) nums.size() - 1; i++)
        {
            if (nums[i] + 1 != nums[i + 1])
            {
                return nums[i] + 1;
            }
        }

        return (int) nums.size();
    }
};

int main()
{
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    Solution solution;

    cout << solution.missingNumber(nums) << endl;

    return 0;
}