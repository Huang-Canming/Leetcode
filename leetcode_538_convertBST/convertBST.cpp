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
    void dfsBST(TreeNode* node, int &sum) {
        if (node == nullptr) {
            return;
        }

        // 右子树优先的中序遍历，得到从大到小的访问序列
        // 对访问到的结果求和，即是要新赋的值
        // 递归访问的过程中，每次要向上回退的时候才给节点赋值
        dfsBST(node->right, sum);
        node->val = node->val + sum;
        sum = node->val;
        dfsBST(node->left, sum);
        return;
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfsBST(root, sum);
        return root;
    }
};

int main(){
    TreeNode node9(8);
    TreeNode node8(3);
    TreeNode node7(7, nullptr, &node9);
    TreeNode node6(5);
    TreeNode node5(2, nullptr, &node8);
    TreeNode node4(0);
    TreeNode node3(6, &node6, &node7);
    TreeNode node2(1, &node4, &node5);
    TreeNode node1(4, &node2, &node3);
    Solution s;
    s.convertBST(&node1);
    return 0;
}