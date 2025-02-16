#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        bool res = false;
        int cnt = nums.size();
        vector<int> leftMin(cnt);   // nums[i] 左侧的最小值
        vector<int> rightMax(cnt);  // nums[i] 右侧的最大值

        leftMin[0] = nums[0];
        rightMax[cnt - 1] = nums[cnt - 1];
        for (int i = 1; i < cnt; i++) {
            // 1 ~ cnt - 1
            leftMin[i] = min(nums[i], leftMin[i - 1]);
            // cnt - 2 ~ 0
            rightMax[cnt - 1 - i] = max(nums[cnt - 1 - i], rightMax[cnt - 1 - i + 1]);
        }

        for (int i = 0; i < cnt; i++) {
            if (leftMin[i] < nums[i] && nums[i] < rightMax[i]) {
                res = true;
                break;
            }
        }

        return res;
    }
};

int main() {
    Solution solu;
    vector<int> nums = {20,100,10,12,5,13};
    bool res = false;
    
    res = solu.increasingTriplet(nums);
    cout << res << endl;

    return 0;
}