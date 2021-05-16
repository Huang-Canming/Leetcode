#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int len = nums.size();
        unordered_map<int, int> numTimesMap;

        for (int i = 0; i < len; i++)
        {
            #if 0
            if (0 == numTimesMap.count(nums[i]))
            {
                numTimesMap.insert({nums[i], 1});
            }
            else 
            {
                numTimesMap[nums[i]]++;
            }
            #endif

            numTimesMap[nums[i]]++;
            
            if (numTimesMap[nums[i]] > len / 2)
            {
                return nums[i];
            }
        }

        return nums[0];
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {3, 2, 3};
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};

    cout << solution.majorityElement(nums1) << endl;
    cout << solution.majorityElement(nums2) << endl;

    return 0;
}