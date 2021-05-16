#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int oneLevelSize = 0;
        TreeNode *pNode = nullptr;
        queue<TreeNode *> queNode;
        vector<vector<int>> res;

        if (nullptr == root)
        {
            return res;
        }
        
        queNode.push(root);
        oneLevelSize = 1;
        while (!queNode.empty())
        {
            vector<int> oneLevel;

            for (int i = 0; i < oneLevelSize; i++)
            {
                pNode = queNode.front();
                oneLevel.push_back(pNode->val);
                queNode.pop();
                if (nullptr != pNode->left)
                {
                    queNode.push(pNode->left);
                }
                if (nullptr != pNode->right)
                {
                    queNode.push(pNode->right);
                }
            }

            oneLevelSize = queNode.size();
            res.push_back(oneLevel);
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> res;

    TreeNode node3(3);
    TreeNode node9(9);
    TreeNode node20(20);
    TreeNode node15(15);
    TreeNode node7(7);

    node3.left = &node9;
    node3.right = &node20;
    node20.left = &node15;
    node20.right = &node7;

    res = solution.levelOrder(&node3);

    return 0;
}