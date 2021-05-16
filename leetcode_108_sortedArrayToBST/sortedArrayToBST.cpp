#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        if (0 == nums.size())
        {
            return nullptr;
        }

        if (1 == nums.size())
        {
            return (new TreeNode(nums[0]));
        }

        int rootIndex = nums.size() / 2;
        int rootVal = nums[rootIndex];
        TreeNode *pRoot = new TreeNode(rootVal);

        vector<int> numsLeft;
        numsLeft.assign(nums.begin(), nums.begin() + rootIndex);
        pRoot->left = sortedArrayToBST(numsLeft);
        
        vector<int> numsRight;
        numsRight.assign(nums.begin() + rootIndex + 1, nums.end());
        pRoot->right = sortedArrayToBST(numsRight);

        return pRoot;
    }
};

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution solution;
    cout << solution.sortedArrayToBST(nums) << endl;

    return 0;
}