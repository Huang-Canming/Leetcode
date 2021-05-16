#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 struct TreeNodeWithLevel {
     TreeNode *pNode;
     int level;
 };
 
class Solution {
public:
    void levelTraverse(TreeNode* root, vector<TreeNodeWithLevel> &vecLevelTraverse, const TreeNode* p, const TreeNode* q, int &pIndex, int &qIndex){
        queue<TreeNodeWithLevel> queTreeNode;
        TreeNodeWithLevel nodeWithLevel = {0};

        queTreeNode.push({root, 0});
        while (-1 == pIndex || -1 == qIndex){
            nodeWithLevel = queTreeNode.front();
            vecLevelTraverse.push_back(nodeWithLevel);
            if (nullptr != nodeWithLevel.pNode){
                queTreeNode.push({nodeWithLevel.pNode->left, nodeWithLevel.level + 1});
                queTreeNode.push({nodeWithLevel.pNode->right, nodeWithLevel.level + 1});
            } else {
                queTreeNode.push({nullptr, nodeWithLevel.level + 1});
                queTreeNode.push({nullptr, nodeWithLevel.level + 1});
            }

            if (p == nodeWithLevel.pNode){
                pIndex = vecLevelTraverse.size() - 1;
            } else if (q == nodeWithLevel.pNode){
                qIndex = vecLevelTraverse.size() - 1;
            }

            queTreeNode.pop();
        }

        return;
    }

    TreeNode* lowestCommonAncestor_TimeOut(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNodeWithLevel> vecLevelTraverse;
        int pIndex = -1, qIndex = -1, deeperNodeIndex = 0, lowerNodeIndex = 0;

        levelTraverse(root, vecLevelTraverse, p, q, pIndex, qIndex);
        if (pIndex > qIndex){
            deeperNodeIndex = pIndex;
            lowerNodeIndex = qIndex;
        } else {
            deeperNodeIndex = qIndex;
            lowerNodeIndex = pIndex;
        }

        while (vecLevelTraverse[deeperNodeIndex].level > vecLevelTraverse[lowerNodeIndex].level){
            deeperNodeIndex = (deeperNodeIndex - 1) / 2;
        }

        while (deeperNodeIndex != lowerNodeIndex){
            deeperNodeIndex = (deeperNodeIndex - 1) / 2;
            lowerNodeIndex = (lowerNodeIndex - 1) / 2;
        }

        return vecLevelTraverse[deeperNodeIndex].pNode;
    }

    void dfs(TreeNode* root, unordered_map<int, TreeNode *> &father){
        if (nullptr != root->left){
            father[root->left->val] = root;
            dfs(root->left, father);
        }
        if (nullptr != root->right){
            father[root->right->val] = root;
            dfs(root->right, father);
        }
        return;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<int, TreeNode *> father;
        unordered_map<int, bool> visited;
        father[root->val] = nullptr;
        dfs(root, father);
        while (nullptr != p)
        {
            visited[p->val] = true;
            p = father[p->val];
        }
        
        while (nullptr != q){
            if (visited[q->val]){
                return q;
            }

            q = father[q->val];
        }

        return nullptr;
    }
};

int main(){
    Solution solution;

    TreeNode node0(0);
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);
    TreeNode node8(8);

    node3.left = &node5;
    node3.right = &node1;
    node5.left = &node6;
    node5.right = &node2;
    node1.left = &node0;
    node1.right = &node8;
    node2.left = &node7;
    node2.right = &node4;

    TreeNode *commAncestor = solution.lowestCommonAncestor(&node3, &node5, &node4);
    cout << commAncestor->val << endl;

    return 0;
}