 #include <iostream>

 using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    void insertAfter(ListNode* node, ListNode* pos) {
        if (nullptr == pos->next) {
            pos->next = node;
        } else {
            node->next = pos->next;
            pos->next = node;
        }
        return;
    }

    ListNode* removeAfter(ListNode* pos) {
        ListNode* removedNode = nullptr;
        if (nullptr != pos->next) {
            removedNode = pos->next;
            pos->next = pos->next->next;
        }
        return removedNode;
    }

    ListNode* oddEvenList(ListNode* head) {
        if (nullptr == head) {
            return nullptr;
        }

        ListNode* oddNode = head;           // 奇数节点
        ListNode* evenNode = head->next;    // 偶数节点

        while (nullptr != evenNode && nullptr != evenNode->next) {
            ListNode* moveNode = removeAfter(evenNode);
            insertAfter(moveNode, oddNode);
            oddNode = oddNode->next;
            evenNode = evenNode->next;
        }

        return head;
    }
};

int main () {
    ListNode node5(5);
    ListNode node4(4, &node5);
    ListNode node3(3, &node4);
    ListNode node2(2, &node3);
    ListNode head(1, &node2);

    Solution solu;
    ListNode *node = solu.oddEvenList(&head);
    while (nullptr != node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    return 0;
}