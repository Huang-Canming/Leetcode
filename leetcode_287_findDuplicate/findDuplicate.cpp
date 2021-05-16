#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int numsSize = (int)nums.size();
        for (int i = 0; i < numsSize; i++)
        {
            for (int j = i + 1; j < numsSize; j++)
            {
                if (nums[i] == nums[j])
                {
                    return nums[i];
                }
            }
        }

        return 0;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1, 3, 4, 2, 2};

    cout << solution.findDuplicate(nums) << endl;

    return 0;
}