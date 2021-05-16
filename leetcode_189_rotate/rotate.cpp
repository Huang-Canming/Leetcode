#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int numsSize = (int)nums.size(), posNow = 0;

        for (int start = 0; start < __gcd(numsSize, k); start++){
            posNow = (start + k) % numsSize;
            while(start != posNow) {
                swap(nums[posNow], nums[start]);
                posNow = (posNow + k) % numsSize;     
            }
        }

        return;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    vector<int> nums2 = {-1, -100, 3, 99};

    solution.rotate(nums, 3);
    solution.rotate(nums2, 2);

    return 0;
}