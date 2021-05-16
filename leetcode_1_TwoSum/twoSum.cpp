#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum_solution1(vector<int>& nums, int target) {
        int i, j = 0;
        vector<int> res;

        for(i = 0; i < nums.size() - 1; i++)
        {
            for(j = i + 1; j < nums.size(); j++)
            {
                if((nums[i] + nums[j]) == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }

    vector<int> twoSum_solution2(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]); 
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;             //unordered_map 的 find 接口查找的是键，所以这里面把要匹配的值作为键，把对应的数组下标作为值
        }
        return {};
    }
};

int main()
{
    int target = 9;
    int i, j = 0;
    vector<int> nums = {11,15,2,7};
    vector<int> res1, res2;
    Solution solution;

    res1 = solution.twoSum_solution1(nums, target);
    while(i < res1.size())
    {
        cout << res1[i] << " ";
        i++;
    }

    cout << endl;

    res2 = solution.twoSum_solution2(nums, target);
    while(j < res2.size())
    {
        cout << res2[j] << " ";
        j++;
    }

    return 0;
}