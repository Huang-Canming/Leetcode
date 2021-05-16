#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> st;
        ListNode *pTmp = head;

        if(pTmp == NULL)
        {
            return head;
        }

        st.push(pTmp->val);
        while(pTmp->next != NULL)
        {
            pTmp = pTmp->next;
            st.push(pTmp->val);
        }

        pTmp = head;
        pTmp->val = st.top();
        st.pop();
        while(pTmp->next != NULL)
        {
            pTmp = pTmp->next;
            pTmp->val = st.top();
            st.pop();
        }

        return head;
    }

    /* 递归方式实现 */
    ListNode* reverseList_recursion(ListNode* head) {

        /* 终止条件 —— 空链表或者只有一个节点的时候 —— 把数字缩小，把结点数减少 */
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        /* 递归函数功能（反转链表）、f(n) 和 f(n-1) 的等价关系 */
        ListNode* SubList = reverseList_recursion(head->next);
        head->next->next = head;
        head->next = NULL;

        return SubList;
    }

    /* 迭代方式实现 */
    ListNode* reverseList_iteration(ListNode* head) {

        if(NULL == head || NULL == head->next)
        {
            return head;
        }

        ListNode *NextNode = NULL;
        ListNode *CurNode = head;
        ListNode *PreNode = NULL;

        /* NULL == CurNode->next 说明是最后一个结点了 */
        while(NULL != CurNode->next)
        {
            NextNode = CurNode->next;
            CurNode->next = PreNode;
            PreNode = CurNode;
            CurNode = NextNode;
        }

        CurNode->next = PreNode;

        return CurNode;
    }
};

int main()
{
    ListNode *pList = NULL;
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    Solution solution;
    //pList = solution.reverseList(&node1);
    //pList = solution.reverseList_recursion(&node1);
    pList = solution.reverseList_iteration(&node1);

    for (int i = 0; i < 5; i++)
    {
        cout << pList->val << " ";
        pList = pList->next;
    }

    return 0;
}