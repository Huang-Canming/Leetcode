#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if (nullptr == headA || nullptr == headB)
        {
            return nullptr;
        }

        int lenA = 1, lenB = 1;
        ListNode *tmpA = headA;
        ListNode *tmpB = headB;
        ListNode *longList = nullptr;
        ListNode *shortList = nullptr;

        while (nullptr != tmpA->next)
        {
            tmpA = tmpA->next;
            lenA++;
        }

        while (nullptr != tmpB->next)
        {
            tmpB = tmpB->next;
            lenB++;
        }

        if (lenA > lenB)
        {
            longList = headA;
            shortList = headB;
        }
        else 
        {
            longList = headB;
            shortList = headA;
        }

        lenA > lenB ? longList = headA, shortList = headB : longList = headB, shortList = headA;

        for (int i = 0; i < abs(lenA - lenB); i++)
        {
            longList = longList->next;
        }

        while (longList != shortList)
        {
            longList = longList->next;
            shortList = shortList->next;
        }

        return longList;
    }
};

int main()
{
    ListNode nodeA(1);
    ListNode nodeB(9);
    ListNode nodeC(1);
    ListNode nodeD(2);
    ListNode nodeE(4);
    ListNode nodeF(3);

    nodeA.next = &nodeB;
    nodeB.next = &nodeC;
    nodeC.next = &nodeD;
    nodeD.next = &nodeE;
    nodeF.next = &nodeD;

    Solution solution;

    cout << solution.getIntersectionNode(&nodeA, &nodeF)->val << endl;

    return 0;
}