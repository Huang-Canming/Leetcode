#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        int numCnt = nums.size();
        int correctIdx = 0;
        for (i = 0; i < numCnt; i++) {
            // 把 nums 中的元素填到对应的位置，nums[0] 填 1，nums[1] 填 2，···
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > numCnt) {
                    break;
                }

                // 确认 nums[i] 应该要在的位置 correctIdx
                correctIdx = nums[i] - 1;
                // 存在重复元素，nums[correctIdx] 已经填好了正确的元素
                if (nums[i] == nums[correctIdx]) {
                    break;
                }

                // 在下一趟循环，根据换到下标 i 位置的元素重新确认处理方式
                swap(nums[i], nums[correctIdx]);
            }
        }

        // 重新遍历找到缺失的最小的正整数：
        // “1” 或者 “1~numCnt 之间缺失的最小正整数” 或者 “numCnt+1”
        for (i = 0; i < numCnt; i++) {
            if (nums[i] != i + 1) {
                break;
            }
        }
        return (i + 1);
    }
};

int main () {
    Solution solu;
    
    vector<int> nums1 = {1,2,0};
    cout << solu.firstMissingPositive(nums1) << endl;

    vector<int> nums2 = {3,4,-1,1};
    cout << solu.firstMissingPositive(nums2) << endl;

    vector<int> nums3 = {7,8,9,11,12};
    cout << solu.firstMissingPositive(nums3) << endl;

    return 0;
}