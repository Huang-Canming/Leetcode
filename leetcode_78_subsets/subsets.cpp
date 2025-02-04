#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void getSubSet(vector<int>& nums, int startPos, vector<int> &subSet, vector<vector<int>> &res)
    {
        for (int i = startPos; i < nums.size(); i++)
        {
            subSet.push_back(nums[i]);
            res.push_back(subSet);
            getSubSet(nums, i + 1, subSet, res);
            subSet.pop_back();
        }

        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> subSet;
        vector<vector<int>> res;

        res.push_back(subSet);
        getSubSet(nums, 0, subSet, res);

        return res;
    }
};

int main ()
{
    vector<int> nums = {1,2,3};
    Solution solu;

    vector<vector<int>> res = solu.subsets(nums);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
            if (j + 1 < res[i].size())
            {
                cout << ",";
            }
        }
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}