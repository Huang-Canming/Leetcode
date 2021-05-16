#include <vector>
#include <stack>
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
    bool isValidBST(TreeNode* root) {

        long long preNodeVal = (long long)INT_MIN - 1;   // 中序遍历过程中，上一个结点的值
        stack<TreeNode*> stTreeNode;    

        while (nullptr != root || !stTreeNode.empty())
        {
            while (nullptr != root)         // 沿左节点一路遍历到底
            {
                stTreeNode.push(root);
                root = root->left;
            }

            root = stTreeNode.top();        // 回退
            stTreeNode.pop();

            if (root->val <= preNodeVal)    // 判断是否满足二叉搜索树的要求 - 中序遍历访问到的节点值的顺序为升序
            {
                return false;
            }
            else
            {
                preNodeVal = root->val;
                root = root->right;         // 遍历当前访问节点的右子树
            }
        }

        return true;
    }
};

int main()
{
    Solution solution;

    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);

    node2.left = &node1;
    node2.right = &node3;

    cout << solution.isValidBST(&node2) << endl;

    return 0;
}