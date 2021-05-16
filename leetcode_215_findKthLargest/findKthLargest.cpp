#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool quickSortRecurision(vector<int>& nums, int startIndex, int endIndex, int k){
        if (startIndex == endIndex) {
            return false;
        }
        
        int numsSize = (int)nums.size();
        int low = startIndex, high = numsSize - 1;
        int benchMark = nums[startIndex];
        bool res = false;

        while (low != high) {
            while (low != high)
            {
                if (nums[high] < benchMark) {
                    nums[low] = nums[high];
                    break;
                } else {
                    high--;
                }
            }
            
            while (low != high) {
                if (nums[low] > benchMark) {
                    nums[high] = nums[low];
                    break;
                } else {
                    low++;
                }
            }
        }

        nums[low] = benchMark;
        if (low == numsSize - k) {
            return true;
        }
        if (low > startIndex) {
            res = quickSortRecurision(nums, startIndex, low - 1, k);
            if (true == res) {
                return res;
            }
        }
        if (low < endIndex) {
            res = quickSortRecurision(nums, low + 1, endIndex, k);
            if (true == res) {
                return res;
            }
        }

        return false;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int numsSize = (int)nums.size();
        int startIndex = 0, endIndex = numsSize - 1;

        (void)quickSortRecurision(nums, startIndex, endIndex, k);
        return nums[numsSize - k];
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};

    cout << solution.findKthLargest(nums1, 2) << endl;
    cout << solution.findKthLargest(nums2, 4) << endl;

    return 0;
}