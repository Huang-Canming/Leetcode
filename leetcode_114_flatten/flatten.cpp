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
    #if 1
    TreeNode* flattenRecursive (TreeNode* node) {
        if (nullptr == node) {
            return nullptr;
        }
        TreeNode* tail = node;
        TreeNode* leftTail = nullptr;
        TreeNode* rightTail = nullptr;

        // 左子树非空
        if (nullptr != node->left) {
            leftTail = flattenRecursive(node->left);
            leftTail->right = node->right;
            node->right = node->left;
            node->left = nullptr;
            // node->right 已被修改，实际原右子树的根节点是 leftTail->right
            if (nullptr != leftTail->right) {
                // 右子树非空
                rightTail = flattenRecursive(leftTail->right);
                tail = rightTail;
            } else {
                // 右子树为空
                tail = leftTail;
            }
        } else if (nullptr != node->right) {
            // 左子树为空，右子树非空
            rightTail = flattenRecursive(node->right);
            tail = rightTail;
        }

        return tail;
    }
    #else
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
    #endif

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