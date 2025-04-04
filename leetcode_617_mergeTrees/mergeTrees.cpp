struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#if 1
// 精简写法
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (nullptr == root1 && nullptr == root2) {
            return nullptr;
        } else if (nullptr == root1) {
            return root2;
        } else if (nullptr == root2) {
            return root1;
        } else {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
            return root1;
        }
    }
};
#else
// 复杂写法
class Solution {
public:
    void dfs(TreeNode* node1, TreeNode* node2, TreeNode** parent) {
        if (nullptr == node1 && nullptr == node2) {
            return;
        } else if (nullptr == node1) {
            *parent = node2;
            return;
        } else if (nullptr == node2) {
            return;
        } else {
            node1->val += node2->val;
            dfs(node1->left, node2->left, &(node1->left));
            dfs(node1->right, node2->right, &(node1->right));
        }
        return;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (nullptr == root1 && nullptr == root2) {
            return nullptr;
        } else if (nullptr == root1) {
            return root2;
        } else if (nullptr == root2) {
            return root1;
        } else {
            root1->val += root2->val;
            dfs(root1->left, root2->left, &(root1->left));
            dfs(root1->right, root2->right, &(root1->right));
        }
        // 往 root1 上合并
        return root1;
    }
};
#endif

int main () {
    TreeNode node14(5);
    TreeNode node13(2);
    TreeNode node12(3, &node14, nullptr);
    TreeNode node11(1, &node12, &node13);
    
    TreeNode node25(7);
    TreeNode node24(4);
    TreeNode node23(3, nullptr, &node25);
    TreeNode node22(1, nullptr, &node24);
    TreeNode node21(2, &node22, &node23);
    
    Solution solu;
    TreeNode *mergedTree = solu.mergeTrees(&node11, &node21);
    return 0;
}