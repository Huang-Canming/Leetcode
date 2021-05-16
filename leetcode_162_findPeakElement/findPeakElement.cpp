#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int numsSize = (int)nums.size();
        int boundLeft = 0, mid = 0, boundRight = numsSize;
        int valLeft = 0, valRight = 0;

        while(boundLeft <= boundRight){
            mid = (boundLeft + boundRight) / 2;
            valLeft = (0 == mid) ? -1 : nums[mid - 1];
            valRight = (mid == numsSize - 1) ? INT_MIN : nums[mid + 1];

            if (valLeft < nums[mid] && nums[mid] > valRight)
            {
                break;
            }
            else if (valLeft < nums[mid] && nums[mid] < valRight)
            {
                boundLeft = mid + 1;
            }
            else
            {
                boundRight = mid - 1;
            }
        }

        return mid;
    }
};

int main(){
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    vector<int> nums3 = {1};

    cout << solution.findPeakElement(nums1) << endl;
    cout << solution.findPeakElement(nums2) << endl;
    cout << solution.findPeakElement(nums3) << endl;

    return 0;
}