#include <vector>
#include <queue>
#include <algorithm>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if (0 == (int)preorder.size())
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[0]);
        vector<int> leftSubTreePreorder, leftSubTreeInorder, rightSubTreePreorder, rightSubTreeInorder;
        int rootAtInorder = 0, leftSubTreeSize = 0;

        for (int i = 0; i < (int)inorder.size(); i++)
        {
            if (inorder[i] == root->val)
            {
                rootAtInorder = i;
                break;
            }
        }

        leftSubTreeSize = rootAtInorder;
        
        leftSubTreePreorder.assign(preorder.begin() + 1, preorder.begin() + 1 + leftSubTreeSize);
        leftSubTreeInorder.assign(inorder.begin(), inorder.begin() + leftSubTreeSize);
        rightSubTreePreorder.assign(preorder.begin() + 1 + leftSubTreeSize, preorder.end());
        rightSubTreeInorder.assign(inorder.begin() + 1 + leftSubTreeSize, inorder.end());

        root->left = buildTree(leftSubTreePreorder, leftSubTreeInorder);
        root->right = buildTree(rightSubTreePreorder, rightSubTreeInorder);

        return root;
    }
};

int main()
{
    Solution solution;
    vector<int> preOrder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    solution.buildTree(preOrder, inorder);

    return 0;
}