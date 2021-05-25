#include <iostream>
#include <queue>
#include <math.h>

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
   bool isSymmetricByIteration(TreeNode* root) {
        if (nullptr == root) {
            return true;
        }

        queue<TreeNode *> queTree;
        TreeNode *p = nullptr, *q = nullptr;

        queTree.push(root->left);
        queTree.push(root->right);
        
        while (!queTree.empty()) {
            p = queTree.front();
            queTree.pop();
            q = queTree.front();
            queTree.pop();

            if (nullptr == p && nullptr == q) {
                continue;
            } else if ((nullptr == p || nullptr == q) || (p->val != q->val)){
                return false;
            } else {
                queTree.push(p->left);
                queTree.push(q->right);

                queTree.push(p->right);
                queTree.push(q->left);
            }
        }

        return true;
    }

    bool checkByRecurision(TreeNode* p, TreeNode* q) {
        if (nullptr == p && nullptr == q) {
            return true;
        } 
        
        if (nullptr == p || nullptr == q) {
            return false;
        } 
        
        if (p->val == q->val) {
            return checkByRecurision(p->left, q->right) && checkByRecurision(p->right, q->left);
        } else {
            return false;
        }
    }

    bool isSymmetricByRecursion(TreeNode* root) {
        if (nullptr == root)
        {
            return true;
        }

        return checkByRecurision(root->left, root->right);
    }
};

int main()
{
    TreeNode TreeNode31(3);
    TreeNode TreeNode32(4);
    TreeNode TreeNode33(4);
    TreeNode TreeNode34(3);
    TreeNode TreeNode21(2);
    TreeNode TreeNode22(2);
    TreeNode TreeNode11(1);

    //TreeNode21.left = &TreeNode31;
    //TreeNode21.right = &TreeNode32;
    //TreeNode22.left = &TreeNode33;
    //TreeNode22.right = &TreeNode34;
    TreeNode11.left = &TreeNode21;
    TreeNode11.right = &TreeNode22;

    Solution solution;
    cout << solution.isSymmetricByRecursion(&TreeNode11) << endl;
    cout << solution.isSymmetricByIteration(&TreeNode11) << endl;

    return 0;
}