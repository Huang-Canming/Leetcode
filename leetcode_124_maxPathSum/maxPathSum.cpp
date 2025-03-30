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
    int sumRecursive(TreeNode *node, int &maxSum) {
        if (node == nullptr) {
            return 0;
        }

        int bothSubPath = node->val, singleSubPath = node->val;
        if (nullptr != node->left || nullptr != node->right) {
            int leftPath = -1001, rightPath = -1001;
            if (nullptr != node->left) {
                leftPath = sumRecursive(node->left, maxSum);
                if (leftPath > 0) {
                    bothSubPath += leftPath;
                }
            }
            if (nullptr != node->right) {
                rightPath = sumRecursive(node->right, maxSum);
                if (rightPath > 0) {
                    bothSubPath += rightPath;
                }
            }
            if (!(leftPath < 0 && rightPath < 0)) {
                singleSubPath += max(leftPath, rightPath);
            }
        }
        maxSum = max(maxSum, max(singleSubPath, bothSubPath));
        return singleSubPath;
    }

    int maxPathSum(TreeNode* root) {
        // 最大路径：除非是单个的叶子节点，否则一定会经过某一个子树的根节点
        // 最大路径（同时包含左右子树） = 根节点的值 + 左子树最大路径 + 右子树最大路径
        // 最大路径（仅包括左子树或者右子树） = 根节点的值 + max(左子树最大路径, 右子树最大路径)
        int maxSum = -1001;
        (void)sumRecursive(root, maxSum);
        return maxSum;
    }
};

int main() {
    Solution s;
    TreeNode node3(15);
    TreeNode node4(7);
    TreeNode node2(20, &node3, &node4);
    TreeNode node1(9);
    TreeNode node0(-10, &node1, &node2);
    int maxPathSum = s.maxPathSum(&node0);
    cout << maxPathSum << endl;
    return 0;
}