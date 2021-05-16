#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {

        if (nullptr == root)
        {
            return root;
        }

        int levelSize = 0;
        Node *currentNode = nullptr;
        queue<Node *> queLevel;

        queLevel.push(root);
        while (!queLevel.empty())
        {
            levelSize = (int)queLevel.size();
            for (int i = 0; i < levelSize; i++)
            {
                currentNode = queLevel.front();
                queLevel.pop();
                if (nullptr != currentNode->left)
                {
                    queLevel.push(currentNode->left);
                }
                if (nullptr != currentNode->right)
                {
                    queLevel.push(currentNode->right);
                }

                currentNode->next = (i < (levelSize - 1)) ? queLevel.front() : nullptr;
            }
        }

        return root;
    }
};

int main()
{
    Node node1(1);
    Node node2(2);
    Node node3(3);
    Node node4(4);
    Node node5(5);
    Node node6(6);
    Node node7(7);

    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;

    Solution solution;

    solution.connect(&node1);

    return 0;
}