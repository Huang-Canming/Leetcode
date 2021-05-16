#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numsSize = (int)nums.size();
        vector<int> L(numsSize, 0), R(numsSize, 0);
        vector<int> answer(numsSize, 0);

        L[0] = 1;
        for (int i = 1; i < numsSize; i++){
            L[i] = L[i - 1] * nums[i - 1];
        }

        R[numsSize - 1] = 1;
        for (int i = numsSize - 2; i >= 0; i--){
            R[i] = R[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < numsSize; i++){
            answer[i] = L[i] * R[i];
        }

        return answer;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};

    solution.productExceptSelf(nums);

    return 0;
}