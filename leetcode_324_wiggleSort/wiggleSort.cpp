#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int numCnt = nums.size();
        if (numCnt <= 1) {
            return;
        }

        // 找到中间值（奇数场景：左半边的最后一个；偶数场景：正好中间那个）
        int halfCnt = numCnt / 2;
        vector<int>::iterator midPtr = nums.begin() + halfCnt;
        nth_element(nums.begin(), midPtr, nums.end());
        int midVal = nums[halfCnt];

        // three-way-partition 分成 “小于 midVal，等于 midVal，大于 midVal” 三部分
        int low = 0;
        int high = numCnt - 1;
        int i = 0;
        while (i < high) {
            if (nums[i] > midVal) {
                // 把大于 midVal 的值换到右侧
                swap(nums[i], nums[high]);
                // 换到左侧的值需要在下一趟循环重新检查，所以 i 不变
                high--;
            } else {
                if (nums[i] < midVal) {
                    // 把小于 midVal 的值尽量换到左边
                    swap(nums[low], nums[i]);
                    low++;
                }
                // 等于 midVal 的 nums[i] 先不动，因为
                // 如果在 i 的右侧还有小于 midVal 的元素，会在后面把 nums[i] 往右换
                i++;
            }
        }

        // 倒序穿插：
        midPtr += numCnt % 2;
        vector<int> leftSubArr(nums.begin(), midPtr);
        vector<int> rightSubArr(midPtr, nums.end());
        // 左半边的数组倒序放入原数组的偶数位置
        // 对于元素总数是奇数的场景，个数多的那个子数组插到偶数下标位置（也就是第奇数个位置）
        for (i = 0; i < leftSubArr.size(); i++) {
            nums[i * 2] = leftSubArr[leftSubArr.size() - i - 1];
        }
        // 右半边的数组倒序放入原数组的奇数位置
        for (i = 0; i < rightSubArr.size(); i++) {
            nums[i * 2 + 1] = rightSubArr[rightSubArr.size() - i - 1];
        }

        return;
    }
};

int main () {
    Solution solu;
    vector<int> arr = {1, 1, 2, 1, 2, 2, 1};
    // vector<int> arr = {1};

    solu.wiggleSort(arr);
    cout << "result :";
    for (int val : arr) {
        cout << " " << val;
    }
    cout << endl;
    return 0;
}