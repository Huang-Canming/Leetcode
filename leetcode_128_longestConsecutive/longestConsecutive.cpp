#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int num : nums) {
            numSet.insert(num);
        }

        int maxCnt = 0;
        for (const int num : numSet) {
            if (!numSet.count(num - 1)) {
                int currentNum = num;
                int currentCnt = 1;
                while (numSet.count(currentNum + 1)) {
                    currentNum++;
                    currentCnt++;
                }
                maxCnt = max(maxCnt, currentCnt);
            }
        }

        return maxCnt;
    }
};

int main () {

    Solution solu;

    vector<int> nums1 = {100,4,200,1,3,2};
    int res1 = solu.longestConsecutive(nums1);
    cout << res1 << endl;

    vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};
    int res2 = solu.longestConsecutive(nums2);
    cout << res2 << endl;

    return 0;
}