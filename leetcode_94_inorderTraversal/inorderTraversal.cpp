#include <stack>
#include <queue>
#include <deque>
#include <iostream>

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
    void inorderRecursion(TreeNode* root, vector<int> &res)
    {
        if (nullptr == root)
        {
            return;
        }

        inorderRecursion(root->left, res);
        res.push_back(root->val);
        inorderRecursion(root->right, res);

        return;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        inorderRecursion(root, res);

        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> res;

    TreeNode node3(3);
    TreeNode node9(9);
    TreeNode node20(20);
    TreeNode node15(15);
    TreeNode node7(7);

    node3.left = &node9;
    node3.right = &node20;
    node20.left = &node15;
    node20.right = &node7;

    res = solution.inorderTraversal(&node3);

    return 0;
}