#include <iostream>
#include <queue>

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
private:
    queue<TreeNode*> parentQue;
    queue<TreeNode*> sonQue;
    
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* invertedTree = root;
        if(nullptr == invertedTree) {
            return nullptr;
        }

        TreeNode* parentNode = nullptr;
        TreeNode* sonNode = nullptr;
        int i = 0;

        parentQue.push(root);
        sonQue.push(root->left);
        sonQue.push(root->right);
        while (!sonQue.empty()) {
            sonNode = sonQue.front();
            sonQue.pop();

            if (0 == i % 2) {
                parentNode = parentQue.front();     // 每处理两个子节点，更换下一个父节点
                parentQue.pop();
                parentNode->right = sonNode;
            } else {
                parentNode->left = sonNode;
            }
            
            if (nullptr != sonNode) {
                sonQue.push(sonNode->left);
                sonQue.push(sonNode->right);
                parentQue.push(sonNode);
            }
            i++;
        }
        return invertedTree;
    }
};

int main () {
    TreeNode node7(9);
    TreeNode node6(6);
    TreeNode node5(3);
    TreeNode node4(1);
    TreeNode node3(7, &node6, &node7);
    TreeNode node2(2, &node4, &node5);
    TreeNode node1(4, &node2, &node3);

    Solution solu;
    TreeNode* invertedTree = solu.invertTree(&node1);
    return 0;
}