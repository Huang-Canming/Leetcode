#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
#if 0
// timeout
class Solution {
public:
    void mergeSort(vector<int> nums, vector<int> &idx, vector<int>& tmp, 
                      int left, int right, vector<int>& res) {
        while (left >= right) {
            return;
        }

        int mid = (left +right) / 2;
        mergeSort(nums, idx, tmp, left, mid, res);
        mergeSort(nums, idx, tmp, mid + 1, right, res);
        
        for (int k = left; k <= right; k++) {
            tmp[k] = idx[k];
        }
        
        int i = left, j = mid + 1, fillPos = left;
        while (i <= mid && j <= right) {
            if (nums[tmp[i]] <= nums[tmp[j]]) {
                idx[fillPos] = tmp[i];
                i++;
            } else{
                idx[fillPos] = tmp[j];
                j++;
                for (int k = i; k <= mid; k++) {
                    res[tmp[k]]++;
                }
            }
            fillPos++;
        }

        if (i > mid) {
            while (j <= right) {
                idx[fillPos] = tmp[j];
                fillPos++;
                j++;
            }
        }

        if (j > right) {
            while (i <= mid) {
                idx[fillPos] = tmp[i];
                fillPos++;
                i++;
            }
        }
        
        return;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int numCnt = nums.size();
        vector<int> res(numCnt, 0);
        vector<int> tmp(numCnt, 0);
        vector<int> idx(numCnt, 0);
        iota(idx.begin(), idx.end(), 0);
        
        mergeSort(nums, idx, tmp, 0, numCnt - 1, res);
        return res;
    }
};
#else
class Solution {
public:
    void mergeSort(vector<int> &nums, vector<int> &idx, vector<int>& tmp, int left, int right, vector<int>& res) {
        if (left >= right) {
            return;
        }

        int mid = (left +right) / 2;
        mergeSort(nums, idx, tmp, left, mid, res);
        mergeSort(nums, idx, tmp, mid + 1, right, res);
        
        for (int k = left; k <= right; k++) {
            tmp[k] = idx[k];
        }

        // 降序排序
        int i = left, j = mid + 1, fillPos = left;
        while (i <= mid && j <= right) {
            if (nums[tmp[i]] > nums[tmp[j]]) {
                // 先计数，再给 idx 赋值，赋值过程中 i 会变化
                res[tmp[i]] += right - j + 1;
                idx[fillPos++] = tmp[i++];
            } else {
                idx[fillPos++] = tmp[j++];
            }
        }

        if (i > mid) {
            while (j <= right) {
                idx[fillPos++] = tmp[j++];
            }
        }

        if (j > right) {
            while (i <= mid) {
                idx[fillPos++] = tmp[i++];
            }
        }
        
        return;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int numCnt = nums.size();
        vector<int> res(numCnt, 0);
        vector<int> tmp(numCnt, 0);
        vector<int> idx(numCnt, 0);
        iota(idx.begin(), idx.end(), 0);
        
        mergeSort(nums, idx, tmp, 0, numCnt - 1, res);
        return res;
    }
}; 
#endif

int main () {
    Solution solu1;
    vector<int> nums1 = {5,2,6,1};
    vector<int> cnts1 = solu1.countSmaller(nums1);
    cout << "cnts1 :";
    for (int cnt : cnts1) {
        cout << " " << cnt;
    }
    cout << endl;
    return 0;
}