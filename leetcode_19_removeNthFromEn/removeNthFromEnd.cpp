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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pNode1 = head, *pNode2 = head;

        for (int i = 0; i < n + 1; i++)
        {
            if (nullptr == pNode2)
            {
                return pNode1->next;
            }

            pNode2 = pNode2->next;
        }

        while (pNode2 != nullptr)
        {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }

        pNode1->next = pNode1->next->next;

        return head;
    }
};

int main()
{
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(2);
    ListNode node3 = ListNode(3);
    ListNode node4 = ListNode(4);
    ListNode node5 = ListNode(5);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    Solution solution;
    ListNode *pNodeTmp = nullptr;

    solution.removeNthFromEnd(&node1, 1);
    pNodeTmp = &node1;
    while (pNodeTmp != nullptr)
    {
        cout << pNodeTmp->val << endl;
        pNodeTmp = pNodeTmp->next;
    }

    return 0;
}