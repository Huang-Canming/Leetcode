#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode lNewPrev = ListNode(-1);
        ListNode *plNewTail = &lNewPrev;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                plNewTail->next = l1;
                l1 = l1->next;
            }
            else 
            {
                plNewTail->next = l2;
                l2 = l2->next;
            }

            plNewTail = plNewTail->next;
        }

        plNewTail->next = l1 == nullptr ? l2 : l1;

        return lNewPrev.next;
    }

    ListNode* mergeTwoLists_recusion(ListNode* l1, ListNode* l2) {

        ListNode *pResList = NULL;

        /* 终止条件（基础情形） - l1 和 l2 有一个为空，或者两个都为空 */
        if (nullptr == l1 || nullptr == l2)
        {
            return l1 == NULL ? l2 : l1;
        }

        /* 函数等价关系 - 要完成 l1 和 l2 的合并，只需要从 l1 的头结点和 l2 的头结点中选出一个结点加入新队列，再跟上 l1、l2 剩余结点合并后的链表即可 */
        if (l1->val < l2->val)
        {
            pResList = l1;
            pResList->next = mergeTwoLists_recusion(l1->next, l2);
        }
        else 
        {
            pResList = l2;
            pResList->next = mergeTwoLists_recusion(l1, l2->next);
        }

        return pResList;
    }
};

void printList(ListNode *pList)
{
    while(pList != NULL)
    {
        cout << pList->val << " ";
        pList = pList->next;
    }

    cout << endl;

    return;
}

int main()
{
    ListNode *plNew = NULL;

    ListNode n14 = ListNode(4);
    ListNode n12 = ListNode(2, &n14);
    ListNode n11 = ListNode(1, &n12);

    printList(&n11);

    ListNode n24 = ListNode(4);
    ListNode n23 = ListNode(3, &n24);
    ListNode n21 = ListNode(1, &n23);

    printList(&n21);

    Solution solution;
    //plNew = solution.mergeTwoLists(&n11, &n21);
    plNew = solution.mergeTwoLists_recusion(&n11, &n21);
    printList(plNew);

    return 0;
}