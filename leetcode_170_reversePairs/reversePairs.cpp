#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sortRecursive(vector<int> &nums, int left, int right, vector<int> &tmpVec) {
        // 已经递归到只有一个或者两个元素最小层级
        if (left >= right) {
            return 0;
        }

        int res = 0;
        // 拆分成左右两个数组，递归排序
        int mid = (left + right) / 2;
        res += sortRecursive(nums, left, mid, tmpVec);
        res += sortRecursive(nums, mid + 1, right, tmpVec);

        // 合并子数组
        // 先把 nums 中对应区段的元素记录到 tmp 里
        for (int k = left; k <= right; k++) {
            tmpVec[k] = nums[k];
        }
        // 再从 tmp 回填元素到 nums
        int i = left, j = mid + 1, fillPos = left;
        while (i <= mid || j <= right) {
            if (i > mid) {
                // 左子数组已经处理完
                nums[fillPos] = tmpVec[j];
                j++;
            } else if (j > right || tmpVec[i] <= tmpVec[j]) {
                // 右子数组已经处理完 || 左右子数组都还没有处理完，且左子数组当前元素更小
                nums[fillPos] = tmpVec[i];
                i++;
            } else {
                // 左右子数组都还没有处理完，且右子数组当前元素更小
                nums[fillPos] = tmpVec[j];
                j++;
                // 统计逆序数
                res += (mid - i + 1);
            }
            fillPos++;
        }
        return res;
    }

    int reversePairs(vector<int>& record) {
        int res = 0;
        int recCnt = record.size();
        vector<int> tmpVec(recCnt, 0);
        res = sortRecursive(record, 0, recCnt - 1, tmpVec);
        return res;
    }
};

int main () {
    Solution solu;
    vector<int> nums = {1,3,2,3,1};
    cout << solu.reversePairs(nums) << endl;
    return 0;
}