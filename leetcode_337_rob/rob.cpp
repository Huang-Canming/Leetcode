#include <iostream>
#include <vector>
#include <unordered_map>

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
    int subRob(TreeNode* node, bool doRob, unordered_map<TreeNode*, int> &robMax, 
               unordered_map<TreeNode*, int> &notRobMax) {
        int leftMax = 0, rightMax = 0;
        TreeNode *leftNode = node->left;
        TreeNode *rightNode = node->right;

        if (true == doRob) {
            if (robMax.end() != robMax.find(node)) {
                return robMax[node];
            }

            if (nullptr != leftNode) {
                leftMax = subRob(leftNode, false, robMax, notRobMax);
            }
            if (nullptr != rightNode) {
                rightMax = subRob(rightNode, false, robMax, notRobMax);
            }
            // 抢当前节点 + 不抢左子树的根节点 + 不抢右子树的根节点
            robMax[node] = node->val + leftMax + rightMax;
            return robMax[node];
        } else {
            if (notRobMax.end() != notRobMax.find(node)) {
                return notRobMax[node];
            }
            
            if (nullptr != leftNode) {
                //left max = max(不抢左子树的根节点, 抢左子树的根节点)
                leftMax = max(subRob(leftNode, false, robMax, notRobMax), subRob(leftNode, true, robMax, notRobMax));
            }
            if (nullptr != rightNode) {
                //rigth max = max(不抢右子树的根节点, 抢右子树的根节点)
                rightMax = max(subRob(rightNode, false, robMax, notRobMax), subRob(rightNode, true, robMax, notRobMax));
            }
            // 不抢当前节点 + 抢左子树的最大值 + 抢右子树的最大值
            notRobMax[node] = leftMax + rightMax;
            return notRobMax[node];
        }
    }
    int rob(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        unordered_map<TreeNode*, int> robMax;           // 抢某一个节点的最大值
        unordered_map<TreeNode*, int> notRobMax;        // 不抢某一个节点的最大值
        int robRoot = subRob(root, true, robMax, notRobMax);
        int notRobRoot = subRob(root, false, robMax, notRobMax);
        return max(robRoot, notRobRoot);
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    cout << s.rob(root) << endl;

    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(1);
    cout << s.rob(root) << endl;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}