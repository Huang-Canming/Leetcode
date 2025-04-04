#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int num = 0;
        // 以 nums[i] 作为下标，把 nums[i] 置为负数
        for (int i = 0; i < nums.size(); i++) {
            // 把 num 恢复成原来的数
            num = abs(nums[i]);
            if (nums[num - 1] > 0) {
                nums[num - 1] = -nums[num - 1];
            }
        }

        vector<int> res;
        // 检查所有 num，若 num 没有被改为负数，说明对应的元素不存在
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

int main () {
    Solution s;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> res = s.findDisappearedNumbers(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;

}