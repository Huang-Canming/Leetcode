#include <iostream>
#include <stack>

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
    int kthSmallest(TreeNode* root, int k) {
        int nodeCount = 0;
        TreeNode *currentNode = root;
        stack<TreeNode *> stkNode;

        while (nullptr != currentNode || !stkNode.empty())
        {
            while (nullptr != currentNode)
            {
                stkNode.push(currentNode);
                currentNode = currentNode->left;
            }

            currentNode = stkNode.top();
            stkNode.pop();

            #if 1
            // 在中序遍历框架的基础上，加上题目要求返回的倒数第 k 小的节点
            nodeCount++;
            if (nodeCount == k)
            {
                return currentNode->val;
            }
            #endif

            currentNode = currentNode->right;
        }

        return -1;
    }
};

int main()
{
    Solution solution;

    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);

    node5.left = &node3;
    node5.right = &node6;
    node3.left = &node2;
    node3.right = &node4;
    node2.left = &node1;

    cout << solution.kthSmallest(&node5, 3) << endl;

    return 0;
}