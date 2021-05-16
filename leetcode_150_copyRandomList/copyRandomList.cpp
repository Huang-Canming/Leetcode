#include <iostream>
#include <map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (nullptr == head) {
            return nullptr;
        }

        bool bFirstNode = true;
        map<Node *, Node *> mpNodes;    // 以原节点作为 key，以新节点作为 value
        Node *newListHead = nullptr, *newListTail = nullptr, *newListNode = nullptr, *oldListNode = head;

        // 拷贝一份链表，并做好新旧节点的映射
        while (nullptr != oldListNode) {
            newListNode = new Node(oldListNode->val);
            if (bFirstNode) {
                newListHead = newListNode;
                newListTail = newListHead;
                bFirstNode = false;
            } else {
                newListTail->next = newListNode;
                newListTail = newListTail->next;
            }
            mpNodes[oldListNode] = newListNode;
            oldListNode = oldListNode->next;
        }
        newListTail->next = nullptr;

        // 拷贝 random 指针
        oldListNode = head;
        while (nullptr != oldListNode) {
            mpNodes[oldListNode]->random = mpNodes[oldListNode->random];
            oldListNode = oldListNode->next;
        }

        return newListHead;
    }
};

int main() {
    Solution solution;
    Node node1(1);
    Node node2(2);
    Node node3(3);

    node1.next = &node2;
    node2.next = &node3;
    node1.random = &node3;
    node3.random = &node2;

    solution.copyRandomList(nullptr);

    return 0;
}