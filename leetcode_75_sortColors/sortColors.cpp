#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pos = 0;
        int vecSize = nums.size();

        for (int i = 0; i < vecSize; i++)
        {
            if (0 == nums[i])
            {
                swap(nums[i], nums[pos]);
                pos++;
            }
        }

        for (int j = pos; j < vecSize; j++)
        {
            if (1 == nums[j])
            {
                swap(nums[j], nums[pos]);
                pos++;
            }
        }

        return;
    }
};

int main()
{
    Solution solu;

    vector<int> nums1 = {2,0,2,1,1,0};
    solu.sortColors(nums1);
    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {0,1};
    solu.sortColors(nums2);
    for (int num : nums2)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}