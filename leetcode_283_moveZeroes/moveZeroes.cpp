#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int left = 0, right = 0;

        while (right < (int) nums.size())
        {
            if (0 != nums[right])
            {
                swap(nums[left], nums[right]);
                left++;
            }

            right++;
        }

        return;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 0, 2, 0, 3, 12};

    solution.moveZeroes(nums);
    for (int i = 0; i < (int) nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}