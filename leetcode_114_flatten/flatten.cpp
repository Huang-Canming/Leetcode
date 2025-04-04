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
    TreeNode* flattenRecursive (TreeNode* node) {
        if (nullptr == node) {
            return nullptr;
        }

        TreeNode* leftTail = nullptr;
        TreeNode* rightTail = nullptr;
        if (nullptr != node->right) {
            rightTail = flattenRecursive(node->right);
        }

        if (nullptr != node->left) {
            leftTail = flattenRecursive(node->left);
            leftTail->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }
        if (nullptr != rightTail) {
            return rightTail;
        } else if (nullptr != leftTail) {
            return leftTail;
        } else {
            return node;
        }
    }

    void flatten(TreeNode* root) {
        (void) flattenRecursive(root);
        return;
    }
};

int main() {
    // 创建节点
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    Solution s;
    s.flatten(root);
    return 0;
}