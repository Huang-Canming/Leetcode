#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        queue<TreeNode *> level;
        TreeNode *node = nullptr;

        level.push(root);
        while (!level.empty()) {         // 层序遍历
            if (0 != res.length()) {
                res += ",";
            }

            node = level.front();
            if (nullptr != node) {
                res += to_string(node->val);
                level.push(node->left);
                level.push(node->right);
            } else {
                res += "null";          // 空节点不存在子树
            }
            level.pop();
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if ("null" == data) {
            return nullptr;
        }

        stringstream ss(data);
        string subStr = "";
        char delimiter = ',';

        getline(ss, subStr, delimiter);
        TreeNode *root = new TreeNode(stoi(subStr));
        queue<TreeNode *> level;
        level.push(root);

        while (!level.empty()) {
            TreeNode *node = level.front();
            if (getline(ss, subStr, delimiter)) {
                if ("null" == subStr) {
                    node->left = nullptr;
                } else {
                    TreeNode *childNode = new TreeNode(stoi(subStr));
                    node->left = childNode;
                    level.push(childNode);
                }
            }

            if (getline(ss, subStr, delimiter)) {
                if ("null" == subStr) {
                    node->right = nullptr;
                } else {
                    TreeNode *childNode = new TreeNode(stoi(subStr));
                    node->right = childNode;
                    level.push(childNode);
                }
            }
            level.pop();
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main () {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);

    node1.left = &node2;
    node1.right = &node3;
    node3.left = &node4;
    node3.right = &node5;

    Codec codeTree;
    string res = codeTree.serialize(&node1);
    cout << res << endl;

    TreeNode *root = codeTree.deserialize(res);

    return 0;
}