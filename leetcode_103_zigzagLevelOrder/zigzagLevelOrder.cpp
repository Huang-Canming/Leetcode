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
    #if 0
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        int level = 1;
        TreeNode *currentNode;
        queue<TreeNode*> queLevel;
        stack<TreeNode*> staSubTreeNode;
        vector<vector<int>> res;

        if (nullptr == root)
        {
            return res;
        }

        staSubTreeNode.push(root);
        while(!queLevel.empty() || !staSubTreeNode.empty())
        {
            vector<int> oneLevel;

            while (!staSubTreeNode.empty())
            {
                queLevel.push(staSubTreeNode.top());
                staSubTreeNode.pop();
            }

            while (!queLevel.empty())
            {
                currentNode = queLevel.front();
                oneLevel.push_back(currentNode->val);
                if (1 == level % 2 && nullptr != currentNode->left)
                {
                    staSubTreeNode.push(currentNode->left);
                }

                if (1 == level % 2 && nullptr != currentNode->right)
                {
                    staSubTreeNode.push(currentNode->right);
                }

                if (0 == level % 2 && nullptr != currentNode->right)
                {
                    staSubTreeNode.push(currentNode->right);
                }

                if (0 == level % 2 && nullptr != currentNode->left)
                {
                    staSubTreeNode.push(currentNode->left);
                }
                
                queLevel.pop();
            }

            level++;
            res.push_back(oneLevel);
        }

        return res;
    }
    #endif

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool isOrderLeft = true;

        while (!nodeQueue.empty()) {
            deque<int> levelList;
            int size = nodeQueue.size();
            for (int i = 0; i < size; ++i) {
                auto node = nodeQueue.front();
                nodeQueue.pop();
                if (isOrderLeft) {
                    levelList.push_back(node->val);
                } else {
                    levelList.push_front(node->val);
                }
                if (node->left) {
                    nodeQueue.push(node->left);
                }
                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }
            ans.emplace_back(vector<int>{levelList.begin(), levelList.end()});
            isOrderLeft = !isOrderLeft;
        }

        return ans;
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

    res = solution.zigzagLevelOrder(&node3);

    return 0;
}