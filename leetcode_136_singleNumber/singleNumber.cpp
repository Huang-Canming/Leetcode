#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int res = 0;

        for (int i = 0; i < (int) nums.size(); i++)
        {
            res ^= nums[i];
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> v1 = {2, 2, 1};
    vector<int> v2 = {4, 1, 2, 1, 2};

    cout << solution.singleNumber(v1) << endl;
    cout << solution.singleNumber(v2) << endl;

    return 0;
}