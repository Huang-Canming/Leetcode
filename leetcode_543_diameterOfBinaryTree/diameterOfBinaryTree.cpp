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
    int getMaxDepth(TreeNode* node, int& maxDepth) {
        if (nullptr == node) {
            return 0;
        }
        int leftDepth = 0, rightDepth = 0, depth = 0;
        leftDepth = getMaxDepth(node->left, maxDepth);
        rightDepth = getMaxDepth(node->right, maxDepth);
        maxDepth = max(maxDepth, leftDepth + rightDepth);
        depth = 1 + max(leftDepth, rightDepth);
        return depth;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        int maxDepth = 0;
        int leftDepth = getMaxDepth(root->left, maxDepth);    // 返回到根节点的距离
        int rightDepth = getMaxDepth(root->right, maxDepth);
        maxDepth = max(maxDepth, leftDepth + rightDepth);
        return maxDepth;
    }
};

int main() {
    TreeNode node5(5);
    TreeNode node4(4);
    TreeNode node3(3);
    TreeNode node2(2, &node4, &node5);
    TreeNode node1(1, &node2, &node3);
    Solution s;
    cout << s.diameterOfBinaryTree(&node1) << endl;
    return 0;
}