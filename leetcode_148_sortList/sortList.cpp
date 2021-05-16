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

    int getListLen(ListNode* head) {
        int listLen = 0;
        ListNode *pNodeTmp = head;
        
        while (nullptr != pNodeTmp) {
            listLen++;
            pNodeTmp = pNodeTmp->next;
        }
        return listLen;
    }

    ListNode * mergeList(ListNode *subListA, ListNode *subListB) {

        ListNode *mergedListHead = new ListNode(0);
        ListNode *mergedListTail = mergedListHead;

        while (nullptr != subListA && nullptr != subListB)
        {
            if (subListA->val < subListB->val) {
                mergedListTail->next = subListA;
                subListA = subListA->next;
            } else {
                mergedListTail->next = subListB;
                subListB = subListB->next;
            }

            mergedListTail = mergedListTail->next;
        }

        /* 合并剩余的链表节点 */
        mergedListTail->next = subListA != nullptr ? subListA : subListB;

        return mergedListHead->next;
    }

    ListNode* sortList(ListNode* head) {
        int listLen = 0, subListNodeCount = 0;
        ListNode *nodeTmp = nullptr, *subListA = nullptr, *subListB = nullptr, *dummyHead = nullptr;
        ListNode *mergedSubList = nullptr, *lastMergedListTail = nullptr, *nextPairlist = nullptr;

        listLen = getListLen(head);
        dummyHead = new ListNode(0, head);
        for (int subListLen = 1; subListLen < listLen; subListLen *= 2) {
            lastMergedListTail = dummyHead;
            nextPairlist = lastMergedListTail->next;
            while (nextPairlist != nullptr) {
                /* 分：找到第一个子链表 */
                subListNodeCount = 1;
                subListA = nextPairlist;
                nodeTmp = subListA;
                while (nullptr != nodeTmp && nullptr != nodeTmp->next && subListNodeCount < subListLen) {
                    nodeTmp = nodeTmp->next;
                    subListNodeCount++;
                }
                /* 断开链表 */
                subListB = nodeTmp->next;
                nodeTmp->next = nullptr;
                
                /* 分：找到第二个子链表 */
                subListNodeCount = 1;
                nodeTmp = subListB;
                while (nullptr != nodeTmp && nullptr != nodeTmp->next && subListNodeCount < subListLen) {
                    nodeTmp = nodeTmp->next;
                    subListNodeCount++;
                }
                /* 断开链表 */
                if (nullptr != nodeTmp) {
                    nextPairlist = nodeTmp->next;
                    nodeTmp->next = nullptr;
                } else {
                    nextPairlist = nullptr;
                }
            
                /* 治：合并两个链表 */
                mergedSubList = mergeList(subListA, subListB);
                lastMergedListTail->next = mergedSubList;

                while (nullptr != mergedSubList && nullptr != mergedSubList->next) {
                    mergedSubList = mergedSubList->next;
                }
                lastMergedListTail = mergedSubList;
            }
        }

        return dummyHead->next;
    }
};

int main()
{
    Solution solution;
    ListNode node_1(-1);
    ListNode node5(5);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node0(0);

    node_1.next = &node5;
    node5.next = &node3;
    node3.next = &node4;
    node4.next = &node0;

    solution.sortList(&node_1);

    return 0;
}