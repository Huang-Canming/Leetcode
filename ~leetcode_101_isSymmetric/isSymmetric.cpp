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
    bool isSymmetric(TreeNode* root) {

        if (nullptr == root)
        {
            return true;
        }

        int i = 1, count = 0;
        queue<TreeNode *> qTmp;

        qTmp.push(root->left);
        qTmp.push(root->right);

        while (!qTmp.empty())
        {
            i = i * 2;
            vector<TreeNode *> vTmp;
            for (int j = 0; j < i; j++)
            {
                vTmp.push_back(qTmp.front());
                if (nullptr != qTmp.front())
                {
                    qTmp.push(qTmp.front()->left);
                    qTmp.push(qTmp.front()->right);
                }
                else 
                {
                    qTmp.push(nullptr);
                    qTmp.push(nullptr);
                    count++;
                }
                qTmp.pop();
            }

            if (count == i)
            {
                return true;
            }

            for (int j = 0; j < (int) vTmp.size() / 2; j++)
            {
                /* 两个都是空指针 */
                if (nullptr == vTmp[j] && nullptr == vTmp[vTmp.size() - 1 - j])
                {
                    continue;
                }

                /* 一个是空指针，一个不是空指针 */
                if (nullptr == vTmp[j] || nullptr == vTmp[vTmp.size() - 1 - j])
                {
                    return false;
                }

                /* 两个都不是空指针 */
                if (vTmp[j]->val != vTmp[vTmp.size() - 1 - j]->val)
                {
                    return false;
                }
            }
        }

        return false;
    }
};

int main()
{
    //TreeNode TreeNode31(nullptr);
    TreeNode TreeNode32(3);
    //TreeNode TreeNode33(nullptr);
    TreeNode TreeNode34(3);
    TreeNode TreeNode21(2);
    TreeNode TreeNode22(2);
    TreeNode TreeNode11(1);

    //TreeNode21.left = &TreeNode31;
    TreeNode21.right = &TreeNode32;
    //TreeNode22.left = &TreeNode33;
    TreeNode22.right = &TreeNode34;
    TreeNode11.left = &TreeNode21;
    TreeNode11.right = &TreeNode22;

    Solution solution;
    cout << solution.isSymmetric(&TreeNode11) << endl;

    return 0;
}