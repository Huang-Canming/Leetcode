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
    int maxDepth_Recusion(TreeNode* root) {

        if (nullptr == root)
        {
            return 0;
        }

        int leftDepth = 0, rightDepth = 0;

        leftDepth = maxDepth_Recusion(root->left);
        rightDepth = maxDepth_Recusion(root->right);

        return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
    }

    int maxDepth_BFS_TransShape(TreeNode* root) {

        if (nullptr == root)
        {
            return 0;
        }

        queue<TreeNode *> Q;
        TreeNode *pNode;
        int qSize = 0;
        int depth = 0;

        Q.push(root);
        while(!Q.empty())
        {
            qSize = Q.size();
            while(qSize > 0)
            {
                pNode = Q.front();
                if (pNode->left)
                {
                    Q.push(pNode->left);
                }
                if (pNode->right)
                {
                    Q.push(pNode->right);
                }
                Q.pop();
                qSize--;
            }

            depth++;
        }

        return depth;
    }
};

int main()
{
    //TreeNode TreeNode31(nullptr);
    //TreeNode TreeNode32(nullptr);
    TreeNode TreeNode33(15);
    TreeNode TreeNode34(7);
    TreeNode TreeNode21(9);
    TreeNode TreeNode22(20);
    TreeNode TreeNode11(3);

    TreeNode21.left = nullptr;
    TreeNode21.right = nullptr;
    TreeNode22.left = &TreeNode33;
    TreeNode22.right = &TreeNode34;
    TreeNode11.left = &TreeNode21;
    TreeNode11.right = &TreeNode22;

    Solution solution;
    cout << solution.maxDepth_BFS_TransShape(&TreeNode11) << endl;

    return 0;
}