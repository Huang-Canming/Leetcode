#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (0 == nums.size() || 1 == nums.size())
        {
            return nums.size();
        }
        
        int visitPos = 0;
        int insertPos = 1;
        int invalidDataLen = 1;

        for (visitPos = 0; visitPos + 1 < (int) nums.size() && insertPos < (int) nums.size(); visitPos++)
        {
            if (nums[visitPos] != nums[visitPos + 1])
            {
                nums[insertPos] = nums[visitPos + 1];
                insertPos++;
                invalidDataLen++;
            }
        }

        return invalidDataLen;
    }
};

int main()
{
    vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    int invalidDataLen = 0;
    Solution solution;

    invalidDataLen = solution.removeDuplicates(nums);

    for (int i = 0; i < (int) nums.size() && i < invalidDataLen; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}