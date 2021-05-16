#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        set<int> sTmp;
        set<int>::iterator sIter;

        for (int i = 0; i < (int)nums.size(); i++)
        {
            sIter = sTmp.find(nums[i]);
            if (sIter != sTmp.end())
            {
                return true;
            }
            sTmp.insert(nums[i]);
        }

        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> vNums1 = {1, 2, 3, 1};
    vector<int> vNums2 = {1, 2, 3, 4};
    vector<int> vNums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    cout << solution.containsDuplicate(vNums1) << endl;
    cout << solution.containsDuplicate(vNums2) << endl;
    cout << solution.containsDuplicate(vNums3) << endl;

    return 0;
}